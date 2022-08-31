//#pragma GCC optimize("O3")
//#pragma GCC target("arch=corei7-avx")
#include <bits/stdc++.h>
#ifndef ONLINE_JUDGE
# include <sys/time.h>
# include <sys/resource.h>
#endif

/*** TEMPLATE CODE STARTS HERE ***/

#ifndef M_PI
#define M_PI 3.1415926535897932384626433832795028841971693993751
#endif

using namespace std;

typedef vector<string> vs;
typedef long long ll;
typedef complex<double> pnt;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

#define RA(x) begin(x), end(x)
#define FE(i, x) for (auto i = begin(x); i != end(x); ++i)
#define SZ(x) ((ll) (x).size())

template<class T>
void splitstr(const string &s, vector<T> &out)
{
    istringstream in(s);
    out.clear();
    copy(istream_iterator<T>(in), istream_iterator<T>(), back_inserter(out));
}

static void redirect(int argc, const char **argv)
{
#ifndef ONLINE_JUDGE
    struct rlimit rlim;
    getrlimit(RLIMIT_STACK, &rlim);
    rlim.rlim_cur = 256 * 1024 * 1024;
    setrlimit(RLIMIT_STACK, &rlim);
#ifndef __SANITIZE_ADDRESS__
    getrlimit(RLIMIT_DATA, &rlim);
    rlim.rlim_cur = 256 * 1024 * 1024;
    setrlimit(RLIMIT_DATA, &rlim);
#endif
#endif

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    if (argc > 1)
    {
        static filebuf f;
        f.open(argv[1], ios::in);
        cin.rdbuf(&f);
        if (!cin)
        {
            cerr << "Failed to open '" << argv[1] << "'" << endl;
            exit(1);
        }
    }

    if (argc > 2)
    {
        static filebuf f;
        f.open(argv[2], ios::out | ios::trunc);
        cout.rdbuf(&f);
        if (!cout)
        {
            cerr << "Failed to open '" << argv[2] << "'" << endl;
        }
    }
    cin.exceptions(ios::failbit);
}

/*** TEMPLATE CODE ENDS HERE */

template<typename Key, typename Data, typename Compare, typename Modifier>
class AvlTree
{
    friend class TestAvlTree;
public:
    typedef Key key_type;
    typedef Data data_type;
    typedef std::pair<Key, Data> value_type;
    typedef Compare key_compare;
    typedef Modifier modifier_type;

private:
    struct Node
    {
        value_type value;
        Modifier modifier; // applies to subtree, but NOT this node
        std::size_t height;
        Node *child_[2];
        Node *parent;

        ~Node()
        {
            delete child_[0];
            delete child_[1];
        }

        Node() : value(), modifier(), height(0), parent(NULL)
        {
            child_[0] = NULL;
            child_[1] = NULL;
        }

        void push_down()
        {
            if (modifier)
            {
                for (int i = 0; i < 2; i++)
                    if (child_[i] != NULL)
                    {
                        child_[i]->value = modifier(child_[i]->value);
                        child_[i]->modifier = modifier(child_[i]->modifier);
                    }
                modifier = Modifier();
            }
        }

        Node *&child(int side)
        {
            assert(side == 0 || side == 1);
            push_down();
            return child_[side];
        }

        Node *&left()
        {
            return child(0);
        }

        Node *&right()
        {
            return child(1);
        }

    private:
        // make non-copyable
        Node(const Node &);
        Node &operator=(const Node &);
    };

    // Make non-copyable
    AvlTree(const AvlTree &);
    AvlTree &operator=(const AvlTree &);

    Node *root;
    Compare comp;

public:
    class iterator
    {
        friend class AvlTree;
        friend class TestAvlTree;
    private:
        AvlTree *owner;
        Node *node;

    public:
        iterator() : owner(NULL), node(NULL) {}
        iterator(AvlTree *owner, Node *node) : owner(owner), node(node) {}

        iterator &operator++()
        {
            assert(owner);
            assert(node);
            // Go right, the as far left as possible
            if (node->right() != NULL)
            {
                node = node->right();
                while (node->left())
                    node = node->left();
            }
            else
            {
                // Can't go right, so go up-and-left repeatly then right
                while (node->parent != NULL && node->parent->right() == node)
                    node = node->parent;
                node = node->parent; // note: might be NULL
            }
            return *this;
        }

        iterator &operator--()
        {
            assert(owner);
            if (node == NULL)
            {
                node = owner->root;
                assert(node != NULL);
                while (node->right() != NULL)
                    node = node->right();
            }
            else if (node->left() != NULL)
            {
                node = node->left();
                while (node->right() != NULL)
                    node = node->right();
            }
            else
            {
                while (node->parent != NULL && node->parent->left() == node)
                    node = node->parent;
                node = node->parent;
                assert(node != NULL);
            }
            return *this;
        }

        value_type &operator*() const
        {
            assert(owner);
            assert(node);
            return node->value;
        }

        value_type *operator->() const
        {
            assert(owner);
            assert(node);
            return &node->value;
        }

        bool operator==(const iterator &other) const
        {
            assert(owner);
            return node == other.node;
        }

        bool operator!=(const iterator &other) const
        {
            assert(owner);
            return node != other.node;
        }

        // Call after calling modify() on the tree to make value valid again
        void repair()
        {
            assert(owner);
            if (node != NULL && node->parent != NULL)
            {
                iterator(owner, node->parent).repair();
                node->parent->push_down();
            }
        }
    };

private:
    int height(Node *node)
    {
        return node ? node->height : -1;
    }

    void fix_height(Node *node)
    {
        int lheight = height(node->left());
        int rheight = height(node->right());
        node->height = std::max(lheight, rheight) + 1;
    }

    Node *single_rotate(Node *a, int side) // side == 1 for rotate right
    {
        Node *b = a->child(!side);
        Node *y = b->child(side);

        b->parent = a->parent;
        if (b->parent)
            replace_child(b->parent, a, b);
        b->child(side) = a;
        a->parent = b;
        a->child(!side) = y;
        if (y)
            y->parent = a;
        if (root == a)
            root = b;

        fix_height(a);
        fix_height(b);
        return b;
    }

    Node *double_rotate(Node *a, int side) // side == 1 for rotate right
    {
        Node *b = a->child(!side);
        Node *c = b->child(side);
        Node *y = c->child(!side);
        Node *z = c->child(side);

        c->parent = a->parent;
        if (c->parent)
            replace_child(c->parent, a, c);
        c->child(!side) = b;
        c->child(side) = a;
        a->parent = c;
        b->parent = c;

        b->child(side) = y;
        if (y)
            y->parent = b;
        a->child(!side) = z;
        if (z)
            z->parent = a;

        if (root == a)
            root = c;

        fix_height(a);
        fix_height(b);
        fix_height(c);
        return c;
    }

    // Returns new root of the subtree
    Node *fix(Node *node)
    {
        fix_height(node);
        for (int side = 0; side < 2; side++)
        {
            if (height(node->child(!side)) > height(node->child(side)) + 1)
            {
                if (height(node->child(!side)->child(!side)) <= height(node->child(side)))
                    return double_rotate(node, side);
                else
                    return single_rotate(node, side);
            }
        }
        return node;
    }

    void replace_child(Node *node, Node *old_child, Node *new_child)
    {
        assert(!bool(node->modifier));
        assert(node->child_[0] == old_child || node->child_[1] == old_child);
        node->child_[node->child_[1] == old_child] = new_child;
    }

    /* Remove a node from the tree, reconnecting the parent (if any) to the
     * child (if any). The node must have at most one child. Does not call
     * fix. Returns the node that filtered up, if any
     */
    Node *unlink(Node *node)
    {
        assert(node);
        Node *p = node->parent;
        Node *l = node->child(0);
        Node *r = node->child(1);
        Node *child = l ? l : r;
        assert(!l || !r);
        if (l)
            l->parent = p;
        if (r)
            r->parent = p;
        if (p)
            replace_child(p, node, child);

        node->parent = NULL;
        node->child_[0] = NULL;
        node->child_[1] = NULL;
        return child;
    }

    // Apply key comparison to two nodes, with NULL being infinite
    bool compare_nodes(Node *a, Node *b)
    {
        if (a == NULL)
            return false;
        else if (b == NULL)
            return true;
        else
            return comp(a->value.first, b->value.first);
    }

public:
    iterator begin()
    {
        Node *n = root;
        if (n != NULL)
            while (n->child(0) != NULL)
                n = n->child(0);
        return iterator(this, n);
    }

    iterator end()
    {
        return iterator(this, NULL);
    }

    iterator find(const key_type &key)
    {
        Node *node = root;
        while (node != NULL)
        {
            const key_type &nkey = node->value.first;
            if (comp(nkey, key))
                node = node->right();
            else if (comp(key, nkey))
                node = node->left();
            else
                break;
        }
        return iterator(this, node);
    }

    iterator lower_bound(const key_type &key)
    {
        Node *node = root;
        Node *ans = NULL;
        while (node != NULL)
        {
            const key_type &nkey = node->value.first;
            if (comp(nkey, key))
                node = node->right();
            else
            {
                ans = node;
                node = node->left();
            }
        }
        return iterator(this, ans);
    }

    iterator upper_bound(const key_type &key)
    {
        Node *node = root;
        Node *ans = NULL;
        while (node != NULL)
        {
            const key_type &nkey = node->value.first;
            if (!comp(key, nkey))
                node = node->right();
            else
            {
                ans = node;
                node = node->left();
            }
        }
        return iterator(this, ans);
    }

    std::pair<iterator, bool> insert(const value_type &v)
    {
        Node **pos = &root;
        Node *parent = NULL;
        while (*pos != NULL)
        {
            parent = *pos;
            const key_type &pos_key = (*pos)->value.first;
            if (comp(pos_key, v.first))
                pos = &((*pos)->right());
            else if (comp(v.first, pos_key))
                pos = &((*pos)->left());
            else
                return std::make_pair(iterator(this, *pos), false);
        }

        Node *n = new Node();
        n->value = v;
        n->parent = parent;
        *pos = n;
        while (parent != NULL)
        {
            parent = fix(parent);
            parent = parent->parent;
        }
        return std::make_pair(iterator(this, n), true);
    }

    void erase(iterator pos)
    {
        Node *nfix; // lowest node that needs repair
        Node *repl; // node that moved into the same spot
        Node *n = pos.node;
        assert(n);
        if (!n->right())
        {
            nfix = n->parent;
            repl = unlink(n);
        }
        else if (!n->right()->left())
        {
            repl = n->right();
            repl->left() = n->left();
            repl->parent = n->parent;
            if (n->parent)
                replace_child(n->parent, n, repl);
            if (n->left())
                n->left()->parent = repl;
            nfix = repl;
        }
        else
        {
            repl = n->right()->left();
            while (repl->left())
                repl = repl->left();
            nfix = repl->parent;
            unlink(repl);
            repl->parent = n->parent;
            for (int i = 0; i < 2; i++)
            {
                repl->child(i) = n->child(i);
                if (repl->child(i))
                    repl->child(i)->parent = repl;
            }
            if (repl->parent)
                replace_child(repl->parent, n, repl);
        }
        n->child_[0] = n->child_[1] = n->parent = NULL;
        if (root == n)
            root = repl;
        delete(n);

        while (nfix != NULL)
        {
            nfix = fix(nfix);
            nfix = nfix->parent;
        }
    }

    // Afterwards, any iterators must call repair!
    void modify(iterator lower, iterator upper, const Modifier &modifier)
    {
        // Note: has to be implemented carefully to ensure that

        // Not recursive, because that would require multiple lookups of
        // the first element of various subtrees
        Node *cur = root;
        while (cur != NULL)
        {
            if (!compare_nodes(cur, upper.node))
                cur = cur->left();
            else if (compare_nodes(cur, lower.node))
                cur = cur->right();
            else
                break;
        }
        if (cur != NULL)
        {
            // Walk down left side
            Node *left = cur->left();
            while (left != NULL)
            {
                if (compare_nodes(left, lower.node))
                    left = left->right();
                else
                {
                    Node *r = left->right();
                    if (r)
                    {
                        r->value = modifier(r->value);
                        r->modifier = modifier(r->modifier);
                    }
                    Node *next = left->left();
                    left->value = modifier(left->value);
                    left = next;
                }
            }

            // Walk down right side
            Node *right = cur->right();
            while (right != NULL)
            {
                if (!compare_nodes(right, upper.node))
                    right = right->left();
                else
                {
                    Node *l = right->left();
                    if (l)
                    {
                        l->value = modifier(l->value);
                        l->modifier = modifier(l->modifier);
                    }
                    Node *next = right->right();
                    right->value = modifier(right->value);
                    right = next;
                }
            }

            cur->value = modifier(cur->value);
        }
    }

    Data &operator[](const Key &key)
    {
        return insert(value_type(key, Data())).first->second;
    }

    void clear()
    {
        delete root;
        root = NULL;
    }

    AvlTree() : root(NULL)
    {
    }

    ~AvlTree()
    {
        clear();
    }
};


struct range
{
    ll consume = 0;
    int ts = 0;
    int next = -1;
};

struct modifier
{
    typedef ll key_type;
    typedef range data_type;
    typedef std::pair<key_type, data_type> value_type;

    ll cost;
    int ts;

    modifier() : cost(0), ts(0) {}
    modifier(ll cost, int ts) : cost(cost), ts(ts) {}

    modifier operator()(const modifier &other) const
    {
        return modifier(cost + other.cost, ts + other.ts);
    }

    value_type operator()(const value_type &other) const
    {
        range r{other.second.consume + cost, other.second.ts + ts, other.second.next};
        return value_type(other.first + cost, r);
    }

    operator bool() const
    {
        return cost || ts;
    }
};

template<typename T>
static void dump_tree(T &tree)
{
    cerr << "Tree:\n";
    for (auto it = tree.begin(); it != tree.end(); ++it)
    {
        cerr << it->first << ' ' << it->second.consume << ' ' << it->second.ts << ' ' << it->second.next << '\n';
    }
}

static void solve()
{
    int N;
    cin >> N;
    vector<pii> in_tshirts(N);
    for (int i = 0; i < N; i++)
    {
        int c, q;
        cin >> c >> q;
        in_tshirts[i] = pii(-q, c);
    }
    sort(RA(in_tshirts));
    vll c(N);
    for (int i = 0; i < N; i++)
        c[i] = in_tshirts[i].second;

    AvlTree<ll, range, std::less<ll>, modifier> tree;
    tree.insert(make_pair(0, range{0, 0, N}));
    vector<bool> split(N);
    for (int i = N - 1; i >= 0; i--)
    {
        auto it = --tree.upper_bound(c[i]);
        if (it->first < c[i])
        {
            it = tree.insert(make_pair(c[i], it->second)).first;
            split[i] = true;
        }
        tree.modify(it, tree.end(), modifier(c[i], 1));
        tree.insert(make_pair(c[i], range{c[i], 1, i + 1}));
    }

    int Q;
    cin >> Q;
    vi b(Q);
    vi ans(Q);
    vector<vi> at(N + 1);
    for (int i = 0; i < Q; i++)
    {
        cin >> b[i];
        at[0].push_back(i);
    }
    for (int i = 0; i < N; i++)
    {
        for (int q : at[i])
        {
            auto it = --tree.upper_bound(b[q]);
            ans[q] += it->second.ts;
            b[q] -= it->second.consume;
            assert(it->second.next > i);
            at[it->second.next].push_back(q);
        }
        at[i].clear();
        at[i].shrink_to_fit();
        auto it = tree.lower_bound(c[i]);
        assert(it->first == c[i]);
        auto nxt = it;
        ++nxt;
        assert(nxt == tree.end() || nxt->first == 2 * c[i]);
        tree.erase(it);
        nxt.repair();
        tree.modify(nxt, tree.end(), modifier(-c[i], -1));
        if (split[i])
            tree.erase(tree.find(c[i]));
    }

    for (int i = 0; i < Q; i++)
        cout << ans[i] << ' ';
    cout << '\n';
}

int main(int argc, const char **argv)
{
    redirect(argc, argv);
    solve();

    return 0;
}