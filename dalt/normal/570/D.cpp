#include <stdio.h>
#include <vector>
using std::vector;
#include <string.h>

#define LIMIT 500000

class VersionArray
{
  public:
    VersionArray(int cap)
    {
        version_ = new int[cap];
        data_ = new int[cap];
        memset(version_, 0, sizeof(int) * cap);
        now_ = 1;
    }
    int &operator[](int i)
    {
        visit(i);
        return data_[i];
    }
    void clear()
    {
        now_++;
    }

  private:
    void visit(int i)
    {
        if (version_[i] < now_)
        {
            version_[i] = now_;
            data_[i] = 0;
        }
    }
    int *version_;
    int *data_;
    int now_;
};

VersionArray g_array(LIMIT + 1);

#define SWAP(a, b, type) \
    {                    \
        type tmp = a;    \
        a = b;           \
        b = tmp;         \
    }
#define MOD(a, n) ((a) % (n) + (n)) % (n)
#define ABS(x) (x) < 0 ? -(x) : (x)
#define MIN(a, b) ((a) < (b) ? (a) : (b))
#define MAX(a, b) ((a) > (b) ? (a) : (b))
#ifdef ONLINE_JUDGE
int debug = 0;
#else
int debug = 1;
#endif
#define ASSERT(x)                                       \
    if (debug)                                          \
        if (!(x))                                       \
        {                                               \
            printf("Assert fail on %d line", __LINE__); \
            exit(1);                                    \
        }
typedef long long ll;
typedef char boolean;
//typedef __uint128_t ui128;
#define TRUE 1
#define FALSE 0

class Question
{
  public:
    int depth_;
    bool answer_;
};

class Node
{
  public:
    vector<Node *> children_;
    Node *heavy_node_;
    int size_;
    vector<Question *> questions_;
    int bit_;
    int id_;
};

void Contribute(Node *root, Node *father, int depth)
{
    for (auto &&node : root->children_)
    {
        if (node == father)
        {
            continue;
        }
        Contribute(node, root, depth + 1);
    }
    g_array[depth] ^= root->bit_;
}

void DFS(Node *root, Node *father, int depth, bool clear)
{
    for (auto &&node : root->children_)
    {
        if (node == root->heavy_node_ || node == father)
        {
            continue;
        }
        DFS(node, root, depth + 1, true);
    }
    if (root->heavy_node_ != NULL)
    {
        DFS(root->heavy_node_, root, depth + 1, false);
    }
    for (auto &&node : root->children_)
    {
        if (node == root->heavy_node_ || node == father)
        {
            continue;
        }
        Contribute(node, root, depth + 1);
    }
    g_array[depth] ^= root->bit_;
    for (auto &&q : root->questions_)
    {
        int mask = g_array[q->depth_];
        q->answer_ = mask == (mask & -mask);
    }
    if (clear)
    {
        g_array.clear();
    }
}

void HeavyLightChain(Node *root, Node *father)
{
    root->size_ = 1;
    int heavy_node_size = 0;
    for (auto &&node : root->children_)
    {
        if (node == father)
        {
            continue;
        }
        HeavyLightChain(node, root);
        root->size_ += node->size_;
        if (heavy_node_size < node->size_)
        {
            root->heavy_node_ = node;
            heavy_node_size = node->size_;
        }
    }
}

char g_s[LIMIT + 2];
Node g_nodes[LIMIT + 1];
Question g_questions[LIMIT + 1];
int main()
{
#ifndef ONLINE_JUDGE
    freopen("D:/database/testcase/code.in", "r", stdin);
    freopen("D:/database/testcase/code.out", "w", stdout);
#endif

    int n, m;
    scanf("%d %d", &n, &m);
    for(int i = 1; i <= n; i++)
    {
        g_nodes[i].id_ = i;
    }
    for(int i = 2; i <= n; i++)
    {
        int p;
        scanf("%d", &p);
        g_nodes[p].children_.push_back(&g_nodes[i]);
    }
    scanf("%s", g_s + 1);
    for(int i = 1; i <= n; i++)
    {
        g_nodes[i].bit_ = 1 << (g_s[i] - 'a');
    }
    for(int i = 1; i <= m; i++)
    {
        int v, d;
        scanf("%d %d", &v, &d);
        g_nodes[v].questions_.push_back(&g_questions[i]);
        g_questions[i].depth_ = d;
    }
    HeavyLightChain(&g_nodes[1], NULL);
    DFS(&g_nodes[1], NULL, 1, false);
    for(int i = 1; i <= m; i++)
    {
        printf("%s ", g_questions[i].answer_ ? "Yes" : "No");
    }
    return 0;
}