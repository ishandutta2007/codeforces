#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
#define SZ(x) ((int)((x).size()))

template <typename T1, typename T2>
string print_iterable(T1 begin_iter, T2 end_iter, int counter) {
    bool done_something = false;
    stringstream res;
    res << "[";
    for (; begin_iter != end_iter and counter; ++begin_iter) {
        done_something = true;
        counter--;
        res << *begin_iter << ", ";
    }
    string str = res.str();
    if (done_something) {
        str.pop_back();
        str.pop_back();
    }
    str += "]";
    return str;
}

vector<int> SortIndex(int size, std::function<bool(int, int)> compare) {
    vector<int> ord(size);
    for (int i = 0; i < size; i++) ord[i] = i;
    sort(ord.begin(), ord.end(), compare);
    return ord;
}

template <typename T>
bool MinPlace(T& a, const T& b) {
    if (a > b) {
        a = b;
        return true;
    }
    return false;
}

template <typename T>
bool MaxPlace(T& a, const T& b) {
    if (a < b) {
        a = b;
        return true;
    }
    return false;
}

template <typename S, typename T>
ostream& operator <<(ostream& out, const pair<S, T>& p) {
    out << "{" << p.first << ", " << p.second << "}";
    return out;
}

template <typename T>
ostream& operator <<(ostream& out, const vector<T>& v) {
    out << "[";
    for (int i = 0; i < (int)v.size(); i++) {
        out << v[i];
        if (i != (int)v.size()-1) out << ", ";
    }
    out << "]";
    return out;
}

template<class TH>
void _dbg(const char* name, TH val){
    clog << name << ": " << val << endl;
}
template<class TH, class... TA>
void _dbg(const char* names, TH curr_val, TA... vals) {
    while(*names != ',') clog << *names++;
    clog << ": " << curr_val << ", ";
    _dbg(names+1, vals...);
}

#if DEBUG && !ONLINE_JUDGE
    ifstream input_from_file("input.txt");
    #define cin input_from_file

    #define dbg(...) _dbg(#__VA_ARGS__, __VA_ARGS__)
    #define dbg_arr(x, len) clog << #x << ": " << print_iterable(x, x+len, -1) << endl;
#else
    #define dbg(...)
    #define dbg_arr(x, len)
#endif

#ifndef AHO_CORASICK
#define AHO_CORASICK

// Implementation of the Aho-Corasick tree data structure for handling
// dictionaries and searching the occurrences in a text.
// All the operations are linear in the size of the input/output.

#include <vector>
#include <string>
#include <queue>
using namespace std;

// Aho-Corasick tree of a dictionary of words. This structure keeps the
// longest prefix of a word currently matched while parsing a text. The prefixes
// of the words are identified by nodes in the trie.
// The class is templated on the alphabet: the size of the alphabet and the
// alphabet first letter i.e. if lowercase letter of the latin alphabet
// are needed the proper specialization is AhoCorasick<26, 'a'>.
//
// Navigating the trie (for example while parsing a string) should be done
// using the iterator returned by GetIterator().
// The iterator offers the following APIs:
//  1. MoveTo(c): Parse a new character c and moves the iterator accordingly.
//  2. GetDepth(): Get the depth of the current node in the trie.
//  3. GetLongestMatchingWord(): Get the index of the longest word of the
//     dictionary currently matching a suffix of the text.
//
// Here is an example of a possible usage of this class:
//
//  AhoCorasick<26, 'a'> ac(vector_of_words);
//  auto it = ac.GetIterator();
//  string s = "hellolloallolhallo";
//  for (char c : s) {
//      it.MoveTo(c);
//      int index = it.GetLongestMatchingWord();
//      if (index != 0) {
//          ...
//      }
//  }
//
int curr_id = 0;
template<int alphabet_size, char first_letter>
struct AhoCorasick {
    // Utility function to get from a char to its index of the letter in the
    // alphabet. 
    static short int char2index(char c) {
        return c - first_letter;
    }

    // Internal struct used to represent a node of the trie/Aho-Corasick tree.
    struct Node {
        Node() :
            son(),
            transition(),
            longest_matching_word(-1),
            id(curr_id++) {}
        
        Node* GetSon(char c) {
            int index = char2index(c);
            if (son[index] == nullptr) {
                son[index] = new Node();
                son[index]->letter = c;
                son[index]->father = this;
                son[index]->depth = depth + 1;
            }
            return son[index];
        }
        
        char letter;
        // The sons in the trie. If the son doesn't exist then son[c] = nullptr.
        Node* son[alphabet_size];
        // transition[c] = Longest prefix in the trie that is a suffix of the
        // string identified by the current node with the char c appended.
        Node* transition[alphabet_size];
        // The father in the trie. Null pointer if it's the root.
        Node* father;
        // Longest prefix in the trie that is a suffix of the node.
        Node* fallback;

        // Depth of this node in the trie.
        int depth;
        // Index of the longest word that is a suffix of the string identified
        // by this node. If no such word exists the value is -1.
        // Words' indexes are 0-based and are relative to the order in the
        // vector passed to the constructor.
        int longest_matching_word;
        int id;
    };
    
  public:
    AhoCorasick(const vector<vector<char>>& words) :
            root(new Node()),
            word_count(0) {
        root->depth = 0;
        root->letter = '\0';
        for (const auto& word : words) AddWordToTrie(word);
        BfsToBuildAhoCorasick();
    }
    
    class iterator {
      public:
        iterator(const Node* node) : current_node(node) {}

        // Move to the next state in the trie parsing the char c.
        void MoveTo(char c) {
            current_node = current_node->transition[char2index(c)];
        }
        // Get the current depth in the trie.
        int GetDepth() const {
            return current_node->depth;
        }
        // Get the index of the longest matching word present in the dictionary.
        // If no word is matching -1 is returned.
        // If there are multiple (equal) equally long matching words, the one
        // with lowest index is selected.
        int GetLongestMatchingWord() const {
            return current_node->longest_matching_word;
        }
      private:
        const Node* current_node;
    };
    iterator GetIterator() const {
        return iterator(root);
    }
    void AddWordToTrie(const vector<char>& word) {
        Node* current_node = root;
        for (char c : word) current_node = current_node->GetSon(c);
        if (current_node->longest_matching_word == -1) {
            // Words inserted multiple times are ignored.
            current_node->longest_matching_word = word_count;
        }
        word_count++;
    }

    void BfsToBuildAhoCorasick() {
        queue<Node*> active_nodes;
        for (int i = 0; i < alphabet_size; i++) {
            if (root->son[i] != nullptr) active_nodes.push(root->son[i]);
        }
        for (int i = 0; i < alphabet_size; i++) root->transition[i] = root;

        // While building the Aho-Corasick tree, we process the trie in a
        // breadth first order. At each step the Aho-Corasick tree built is
        // correct only with respect to the currently processed nodes, as if
        // the other ones were not existing.
        while(!active_nodes.empty()){
            Node* v = active_nodes.front();
            active_nodes.pop();
            for (int i = 0; i < alphabet_size; i++) {
                if (v->son[i] != nullptr) active_nodes.push(v->son[i]);
            }
            int index = char2index(v->letter);
            Node* father = v->father;
            v->fallback = father->transition[index];
            Node* fallback = v->fallback;
            father->transition[index] = v; // Fixing transition function.
            if (v->longest_matching_word == -1) {
                v->longest_matching_word = fallback->longest_matching_word;
            }
            
            for (int i = 0; i < alphabet_size; i++) {
                // Here we cannot say
                //  v->transition[i] = fallback->transition[i];
                // in the general case as the sons of fallback might still
                // have to be processed.
                if (fallback->son[i] != nullptr) {
                    v->transition[i] = fallback->son[i];
                } else {
                    v->transition[i] = fallback->transition[i];
                }
            }
        }
    }
    
    Node* root;
    int word_count;
};

#endif // AHO_CORASICK


///////////////////////////////////////////////////////////////////////////
//////////////////// DO NOT TOUCH BEFORE THIS LINE ////////////////////////
///////////////////////////////////////////////////////////////////////////

vector<vector<char>> forbidden;

void generate(vector<char>& vec, int sum, int x) {
    if (sum == x) {
        bool is_prime = true;
        for (int x: vec) is_prime &= x != 1;
        if (!is_prime) return;
        int l = SZ(vec);
        for (int i = 0; i < l && is_prime; i++) {
            int sum = 0;
            for (int j = i; j < l; j++) {
                sum += vec[j];
                if (x%sum == 0 and x != sum) is_prime = false; 
            }
        }
        if (is_prime) forbidden.push_back(vec);
        return;
    }
    for (int i = 1; i <= 9 and sum + i <= x; i++) {
        vec.push_back(i);
        generate(vec, sum+i, x);
        vec.pop_back();
    }
}

void forbidden_strings(int x) {
    if (x == 1) {
        forbidden.push_back({1});
        return;
    }
    vector<char> vec;
    generate(vec, 0, x);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); // Remove in problems with online queries!
    int x;
    string S;
    cin >> S;
    vector<char> vec;
    for (char c: S) vec.push_back(c-'0');
    cin >> x;
    forbidden_strings(x);
    AhoCorasick<10, 0> aho(forbidden);
    // forbidden_strings(19);
    // cout << forbidden.size() << endl;
    vector<int> din(curr_id, 1e8);
    vector<AhoCorasick<10,0>::Node*> NN(curr_id, nullptr);
    din[0] = 0;
    NN[0] = aho.root;
    for (char c: vec) {
        vector<int> din2(curr_id, 1e8);
        for (int i = 0; i < curr_id; i++) {
            if (NN[i] == nullptr) continue;
            din2[i] = min(din2[i], 1 + din[i]);
            assert(NN[i] != nullptr);
            // assert(0 <= c <=
            if (NN[i]->transition[c]->longest_matching_word != -1) continue;
            int j = NN[i]->transition[c]->id;
            din2[j] = min(din2[j], din[i]);
            NN[j] = NN[i]->transition[c];
        }
        din = din2;
    }
    int res = 1e8;
    for (int i = 0; i < curr_id; i++) res = min(res, din[i]);
    cout << res << endl;
}