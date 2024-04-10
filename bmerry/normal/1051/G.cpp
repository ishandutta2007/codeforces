//#pragma GCC optimize("O3")
//#pragma GCC optimize("-fcx-limited-range")
//#pragma GCC target("avx,avx2")
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

template<typename Key, typename Data, typename Compare = std::less<Key>>
class AvlTree
{
    friend class TestAvlTree;
public:
    typedef Key key_type;
    typedef Data data_type;
    typedef std::pair<Key, Data> value_type;
    typedef Compare key_compare;

private:
    struct Node
    {
        value_type value;
        data_type total;   // sum of data for this subtree
        std::size_t size;  // size of subtree
        std::size_t height;
        Node *child_[2];
        Node *parent;

        ~Node()
        {
            delete child_[0];
            delete child_[1];
        }

        Node() : value(), total(), height(0), parent(NULL)
        {
            child_[0] = NULL;
            child_[1] = NULL;
        }

        Node *&child(int side)
        {
            assert(side == 0 || side == 1);
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
    };

private:
    int height(Node *node)
    {
        return node ? node->height : -1;
    }

    data_type total(Node *node)
    {
        return node ? node->total : data_type();
    }

    std::size_t size(Node *node)
    {
        return node ? node->size : 0;
    }

    void fix_height(Node *node)
    {
        int lheight = height(node->left());
        int rheight = height(node->right());
        node->height = std::max(lheight, rheight) + 1;
        node->total = total(node->left()) + total(node->right()) + node->value.second;
        node->size = size(node->left()) + size(node->right()) + 1;
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
        assert(node->child_[0] == old_child || node->child_[1] == old_child);
        node->child_[node->child_[1] == old_child] = new_child;
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
        n->total = v.second;
        n->size = 1;
        *pos = n;
        while (parent != NULL)
        {
            parent = fix(parent);
            parent = parent->parent;
        }
        return std::make_pair(iterator(this, n), true);
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

    std::size_t index(iterator it)
    {
        if (it.node == NULL)
            return size(root);
        std::size_t ans = size(root->left());
        while (it.node != root)
        {
            if (it.node->parent->left() == it.node)
                ans -= size(it.node->right()) + 1;
            else
                ans += size(it.node->left()) + 1;
            it.node = it.node->parent;
        }
        return ans;
    }

    data_type total(iterator it)
    {
        data_type ans = total(root);
        if (it.node == NULL)
            return ans;
        while (it.node != root)
        {
            if (it.node->parent->left() == it.node)
                ans -= total(it.node->right()) + it.node->value.second;
            else
                ans += total(it.node->left()) + it.node->parent->value.second;
            it.node = it.node->parent;
        }
        ans += total(root->left());
        ans -= total(root);
        return ans;
    }

    AvlTree() : root(NULL)
    {
    }

    AvlTree(AvlTree &&other) : root(other.root), comp(std::move(other.comp))
    {
        other.root = nullptr;
    }

    ~AvlTree()
    {
        clear();
    }
};

struct island
{
    ll base = -1;
    ll size = 0;
    ll score = 0;
    ll b_sum = 0;
    vector<pair<ll, ll>> items;
    AvlTree<ll, ll> tree;

    bool operator<(const island &other) const
    {
        return base < other.base;
    }

    bool operator<(ll x) const
    {
        return base < x;
    }

    void add(ll a, ll b);
};

bool operator<(ll x, const island &is)
{
    return x < is.base;
}

void island::add(ll a, ll b)
{
    size++;
    b_sum += b;
    score -= (a - base) * b;
    auto pos = tree.lower_bound(-b);
    ll right = tree.total(tree.end()) - tree.total(pos);
    ll idx = tree.index(pos);
    score += right + idx * b;
    tree.insert(make_pair(-b, b));
    items.emplace_back(a, b);
}

static void solve()
{
    int N;
    cin >> N;
    set<island, less<>> islands;
    ll grand = 0;
    for (int i = 0; i < N; i++)
    {
        ll a, b;
        cin >> a >> b;
        auto pos = islands.upper_bound(a);
        if (pos == islands.begin() || prev(pos)->base + prev(pos)->size < a)
        {
            island ni;
            ni.base = a;
            ni.add(a, b);
            pos = islands.insert(move(ni)).first;
        }
        else
        {
            --pos;
            auto &curi = const_cast<island &>(*pos);
            grand -= curi.score;
            curi.add(a, b);
            grand += curi.score;
        }
        if (next(pos) != islands.end() && pos->base + pos->size == next(pos)->base)
        {
            auto nxth = islands.extract(next(pos));
            auto curh = islands.extract(pos);
            island *curi = &curh.value();
            island *nxti = &nxth.value();
            grand -= curi->score + nxti->score;
            ll diff = nxti->base - curi->base;
            nxti->base -= diff;
            nxti->score -= nxti->b_sum * diff;
            if (nxti->size > curi->size)
            {
                swap(nxti, curi);
                swap(nxth, curh);
            }
            for (const auto &item : nxti->items)
                curi->add(item.first, item.second);
            grand += curi->score;
            islands.insert(move(curh));
        }

        cout << grand << '\n';
    }
}

int main(int argc, const char **argv)
{
    redirect(argc, argv);
    solve();

    return 0;
}