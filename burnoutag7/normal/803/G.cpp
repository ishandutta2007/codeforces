#include <bits/stdc++.h>
#define var auto
#define ALL(x) x.begin(), x.end()
const std::int32_t INF = 0x3f3f3f3f;
const std::int64_t INFL = 0x3f3f3f3f3f3f3f3f;
#define If(x, y, z) ((x) ? (y) : (z))
#include <bits/stdc++.h>

template <typename T, int Dimension>
struct MultiVector : public std::vector<MultiVector<T, Dimension - 1>>
{
    MultiVector(std::size_t n = 0)
        : std::vector<MultiVector<T, Dimension - 1>>(
              n, MultiVector<T, Dimension - 1>())
    {
    }
    template <typename... Args>
    MultiVector(std::size_t n, const Args &...args)
        : std::vector<MultiVector<T, Dimension - 1>>(
              n, MultiVector<T, Dimension - 1>(args...))
    {
    }
    template <typename... Args>
    void resize(std::size_t n, const Args &...args)
    {
        std::vector<MultiVector<T, Dimension - 1>>::resize(n);
        for (auto &i : (*this))
            i.resize(args...);
    }
    void resize() {}
    template <typename... Args>
    void assign(std::size_t n, const Args &...args)
    {
        std::vector<MultiVector<T, Dimension - 1>>::resize(n);
        for (auto &i : (*this))
            i.assign(args...);
    }
};
template <typename T>
struct MultiVector<T, 1> : public std::vector<T>
{
    MultiVector(std::size_t n = 0)
        : std::vector<T>(n)
    {
    }
    MultiVector(std::size_t n, const T &x)
        : std::vector<T>(n, x)
    {
    }
    void resize(std::size_t n = 0) { std::vector<T>::resize(n); }
    void resize(std::size_t n, const T &x) { std::vector<T>::resize(n, x); }
};

using namespace std;
int n;
template <typename T>
struct SparseTable
{
    static const int MAXM = 30;
    MultiVector<T, 2> f;
    vector<int> LG2;
    void build(const vector<T> &a)
    {
        f.resize(25, a.size());
        LG2.resize(a.size() + 1);
        for (int i = 0; i < a.size(); i++)
            f[0][i] = a[i];
        for (int j = 1; ((1ll << j) >> 2) < a.size(); j++)
            for (int i = 0; i < a.size() && i + (1ll << (j - 1)) < a.size();
                 i++)
            {
                f[j][i] = min(f[j - 1][i], f[j - 1][i + (1 << (j - 1))]);
            }
        for (int i = 1; i <= a.size(); i++)
            LG2[i] = log2(i);
    }
    T query(int l, int r) const
    {
        if (r - l >= n)
        {
            return min(f[LG2[n]][0], f[LG2[n]][n - (1 << LG2[n])]);
        }
        l %= n, r %= n;
        if (r <= l)
            r += n;
        return min(f[LG2[r - l]][l], f[LG2[r - l]][r - (1 << LG2[r - l])]);
    }
};
SparseTable<int> sparseTable;
struct SegTree
{
#define Mid ((l + r) >> 1)
    static const int MAXRANGE = 1 << 30;
    struct Node
    {
        int val, minVal;
        Node *leftChild, *rightChild;
        Node(int val = 0, int minVal = INF, Node *leftChild = nullptr,
             Node *rightChild = nullptr)
            : val(val), minVal(minVal), leftChild(leftChild), rightChild(rightChild)
        {
        }
    };
    Node *root, *mem;
    size_t poolsz;
    Node *alloc(int val = 0, int minVal = INF, Node *leftChild = nullptr,
                Node *rightChild = nullptr)
    {
        if (poolsz == 0)
            mem = new Node[poolsz = 114514];
        *mem = Node(val, minVal, leftChild, rightChild);
        poolsz--;
        return mem++;
    }
    void pushUp(Node *u)
    {
        u->minVal = min(u->leftChild->minVal, u->rightChild->minVal);
    }
    void assign(int a, int b, int v) { assign(a, b, v, root, 0, MAXRANGE); }
    void assign(int a, int b, int v, Node *u, int l, int r)
    {
        if (a <= l && r <= b)
        {
            u->val = v;
            u->minVal = v;
            // delete u->leftChild;
            // delete u->rightChild;
            u->leftChild = nullptr;
            u->rightChild = nullptr;
            return;
        }
        if (b <= l || r <= a)
            return;
        if (!u->leftChild)
            u->leftChild = alloc(
                u->val, If(u->val == -1, sparseTable.query(l, Mid), u->minVal));
        if (!u->rightChild)
            u->rightChild = alloc(
                u->val, If(u->val == -1, sparseTable.query(Mid, r), u->minVal));
        assign(a, b, v, u->leftChild, l, Mid);
        assign(a, b, v, u->rightChild, Mid, r);
        pushUp(u);
    }
    int query(int a, int b) { return query(a, b, root, 0, MAXRANGE); }
    int query(int a, int b, Node *u, int l, int r)
    {
        if (a <= l && r <= b)
        {
            return u->minVal;
        }
        if (b <= l || r <= a)
            return INF;
        if (!u->leftChild)
            u->leftChild = alloc(
                u->val, If(u->val == -1, sparseTable.query(l, Mid), u->minVal));
        if (!u->rightChild)
            u->rightChild = alloc(
                u->val, If(u->val == -1, sparseTable.query(Mid, r), u->minVal));
        return min(query(a, b, u->leftChild, l, Mid),
                   query(a, b, u->rightChild, Mid, r));
    }
    SegTree()
    {
        poolsz = 0;
        root = alloc(-1, sparseTable.query(0, MAXRANGE));
    }
#undef Mid
};
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int k;
    cin >> n >> k;
    vector<int> b(n);
    for (int &x : b)
        cin >> x;
    [&]()
    {
        auto t = b;
        b.insert(b.end(), ALL(t));
    }();
    sparseTable.build(b);
    SegTree segTree;
    int q;
    cin >> q;
    while (q--)
    {
        int op, l, r;
        cin >> op >> l >> r;
        l--;
        if (op == 1)
        {
            int x;
            cin >> x;
            segTree.assign(l, r, x);
        }
        else
        {
            cout << segTree.query(l, r) << '\n';
        }
    }
    return 0;
}//