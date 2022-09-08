#include <bits/stdc++.h>

using namespace std;

namespace std {

template<typename T, typename... Args>
std::unique_ptr<T> make_unique(Args&&... args) {
    return std::unique_ptr<T>(new T(std::forward<Args>(args)...));
}

}

template <class Iterator>
class IteratorRange {
public:
    IteratorRange(Iterator begin, Iterator end) : begin_(begin), end_(end) {
    }

    Iterator begin() const {
        return begin_;
    }
    Iterator end() const {
        return end_;
    }

private:
    Iterator begin_, end_;
};

namespace traverses {

// Traverses the connected component in a breadth-first order
// from the vertex 'origin_vertex'.
// Refer to
// https://goo.gl/0qYXzC
// for the visitor events.
template <class Vertex, class Graph, class Visitor>
void BreadthFirstSearch(Vertex origin_vertex, const Graph &graph,
                        Visitor visitor) {
    std::unordered_set<Vertex> visited{origin_vertex};
    std::queue<Vertex> queue;
    visitor.DiscoverVertex(origin_vertex);
    queue.push(origin_vertex);
    while (!queue.empty()) {
        auto vertex = queue.front();
        queue.pop();
        visitor.ExamineVertex(vertex);
        for (const auto &edge : OutgoingEdges(graph, vertex)) {
            auto target = GetTarget(graph, edge);
            visitor.ExamineEdge(edge);
            if (visited.count(target)) {
                continue;
            }
            visitor.DiscoverVertex(target);
            visited.insert(target);
            queue.push(target);
        }
    }
}

// See "Visitor Event Points" on
// https://goo.gl/wtAl0y
template <class Vertex, class Edge>
class BfsVisitor {
public:
    virtual void DiscoverVertex(Vertex /*vertex*/) {}
    virtual void ExamineEdge(const Edge & /*edge*/) {}
    virtual void ExamineVertex(Vertex /*vertex*/) {}
    virtual ~BfsVisitor() = default;
};

} // namespace traverses

struct AutomatonNode {
    AutomatonNode() : suffix_link(nullptr), terminal_link(nullptr) {
    }

    // Stores ids of strings which are ended at this node.
    std::vector<size_t> terminated_string_ids;
    // Stores tree structure of nodes.
    std::map<char, AutomatonNode> trie_transitions;
    // Stores cached transitions of the automaton, contains
    // only pointers to the elements of trie_transitions.
    std::map<char, AutomatonNode *> automaton_transitions_cache;
    AutomatonNode *suffix_link;
    AutomatonNode *terminal_link;
};

// Returns a corresponding trie transition 'nullptr' otherwise.
AutomatonNode *GetTrieTransition(AutomatonNode *node, char character) {
    auto transition = node->trie_transitions.find(character);
    if (transition != node->trie_transitions.end()) {
        return &transition->second;
    }
    return nullptr;
}

// Returns an automaton transition, updates 'node->automaton_transitions_cache'
// if necessary.
// Provides constant amortized runtime.
AutomatonNode *GetAutomatonTransition(AutomatonNode *node,
                                      const AutomatonNode *root,
                                      char character) {
    auto cache_transition = node->automaton_transitions_cache.find(character);
    if (cache_transition != node->automaton_transitions_cache.end()) {
        return cache_transition->second;
    }
    AutomatonNode *automaton_transition = GetTrieTransition(node, character);
    if (automaton_transition) {
        return node->automaton_transitions_cache[character] = automaton_transition;
    }
    if (node == root) {
        automaton_transition = node;
    } else {
        automaton_transition = GetAutomatonTransition(node->suffix_link, root, character);
    }
    return node->automaton_transitions_cache[character] = automaton_transition;
}

namespace internal {

class AutomatonGraph {
public:
    struct Edge {
        Edge(AutomatonNode *source, AutomatonNode *target, char character)
            : source(source), target(target), character(character) {}

        AutomatonNode *source;
        AutomatonNode *target;
        char character;
    };
};

std::vector<typename AutomatonGraph::Edge> OutgoingEdges(
    const AutomatonGraph & /*graph*/, AutomatonNode *vertex) {
    std::vector<typename AutomatonGraph::Edge> edges;
    for (auto &trie_transition : vertex->trie_transitions) {
        edges.emplace_back(vertex,
                           &trie_transition.second,
                           trie_transition.first);
    }
    return edges;
}

AutomatonNode *GetTarget(const AutomatonGraph & /*graph*/,
                         const AutomatonGraph::Edge &edge) {
    return edge.target;
}

class SuffixLinkCalculator
    : public traverses::BfsVisitor<AutomatonNode *, AutomatonGraph::Edge> {
public:
    explicit SuffixLinkCalculator(AutomatonNode *root) : root_(root) {
    }

    void ExamineVertex(AutomatonNode *node) override {
        if (!node->suffix_link) {
            node->suffix_link = root_;
        }
    }

    void ExamineEdge(const AutomatonGraph::Edge &edge) override {
        AutomatonNode *node = edge.source;
        AutomatonNode *target = edge.target;
        char character = edge.character;
        if (node == root_) {
            target->suffix_link = root_;
        } else {
            target->suffix_link = GetAutomatonTransition(node->suffix_link, root_, character);
        }
    }

private:
    AutomatonNode *root_;
};

class TerminalLinkCalculator
    : public traverses::BfsVisitor<AutomatonNode *, AutomatonGraph::Edge> {
public:
    explicit TerminalLinkCalculator(AutomatonNode *root) : root_(root) {}

    void DiscoverVertex(AutomatonNode *node) override {
        node->terminal_link = nullptr;
        if (node == root_) {
            return;
        }
        if (node->suffix_link->terminated_string_ids.empty()) {
            node->terminal_link = node->suffix_link->terminal_link;
            return;
        }
        node->terminal_link = node->suffix_link;
    }

private:
    AutomatonNode *root_;
};

} // namespace internal

class NodeReference {
public:
    NodeReference() : node_(nullptr), root_(nullptr) {}

    NodeReference(AutomatonNode *node, AutomatonNode *root)
        : node_(node), root_(root) {}

    NodeReference Next(char character) const {
        return {GetAutomatonTransition(node_, root_, character), root_};
    }

    template <class Callback>
    void GenerateMatches(Callback on_match) const {
        auto current = *this;
        while (current) {
            for (size_t string_id : current.TerminatedStringIds()) {
                on_match(string_id);
            }
            current = current.TerminalLink();
        }
    }

    bool IsTerminal() const {
        return !node_->terminated_string_ids.empty();
    }

    explicit operator bool() const {
        return node_ != nullptr;
    }

    bool operator==(const NodeReference &other) const {
        return node_ == other.node_ && root_ == other.root_;
    }

private:
    using TerminatedStringIterator = std::vector<size_t>::const_iterator;
    using TerminatedStringIteratorRange = IteratorRange<TerminatedStringIterator>;

    NodeReference TerminalLink() const {
        return {node_->terminal_link, root_};
    }

    TerminatedStringIteratorRange TerminatedStringIds() const {
        return {node_->terminated_string_ids.begin(), node_->terminated_string_ids.end()};
    }

    AutomatonNode *node_;
    AutomatonNode *root_;
};

class AutomatonBuilder;

class Automaton {
public:
    Automaton() = default;

    Automaton(const Automaton &) = delete;
    Automaton &operator=(const Automaton &) = delete;

    NodeReference Root() {
        return {&root_, &root_};
    }

private:
    AutomatonNode root_;

    friend class AutomatonBuilder;
};

class AutomatonBuilder {
public:
    void Add(const std::string &string, size_t id) {
        words_.push_back(string);
        ids_.push_back(id);
    }

    std::unique_ptr<Automaton> Build() {
        auto automaton = std::make_unique<Automaton>();
        BuildTrie(words_, ids_, automaton.get());
        BuildSuffixLinks(automaton.get());
        BuildTerminalLinks(automaton.get());
        return automaton;
    }

private:
    static void BuildTrie(const std::vector<std::string> &words,
                          const std::vector<size_t> &ids, Automaton *automaton) {
        for (size_t i = 0; i < words.size(); ++i) {
            AddString(&automaton->root_, ids[i], words[i]);
        }
    }

    static void AddString(AutomatonNode *root, size_t string_id,
                          const std::string &string) {
        AutomatonNode *current = root;
        for (char symbol : string) {
            current = &current->trie_transitions[symbol];
        }
        current->terminated_string_ids.push_back(string_id);
    }

    static void BuildSuffixLinks(Automaton *automaton) {
        internal::SuffixLinkCalculator suffix_link_calculator(&automaton->root_);
        traverses::BreadthFirstSearch(&automaton->root_,
                                      internal::AutomatonGraph(),
                                      suffix_link_calculator);
    }

    static void BuildTerminalLinks(Automaton *automaton) {
        internal::TerminalLinkCalculator terminal_link_calculator(&automaton->root_);
        traverses::BreadthFirstSearch(&automaton->root_,
                                      internal::AutomatonGraph(),
                                      terminal_link_calculator);
    }

    std::vector<std::string> words_;
    std::vector<size_t> ids_;
};

const int max_n = 100011, inf = 1000111222;

int n, k[max_n], ans[max_n];
string s, t[max_n];
vector<int> all[max_n];
AutomatonBuilder q;

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> s >> n;
    for (int i = 0; i < n; ++i) {
        cin >> k[i] >> t[i];
        q.Add(t[i], i);
    }
    const auto &automaton = q.Build();
    NodeReference state = automaton->Root();
    for (int i = 0; i < s.length(); ++i) {
        state = state.Next(s[i]);
        auto lambda = [i](int id) {
            all[id].push_back(i);
        };
        state.GenerateMatches(lambda);
    }
    for (int i = 0; i < n; ++i) {
        int len = inf;
        for (int j = 0; j + k[i] <= all[i].size(); ++j) {
            len = min(len, all[i][j + k[i] - 1] - all[i][j]);
        }
        if (len == inf) {
            cout << "-1\n";
        } else {
            cout << len + t[i].length() << "\n";
        }
    }
    return 0;
}