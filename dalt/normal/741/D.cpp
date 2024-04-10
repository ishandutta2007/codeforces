#include <stdio.h>
#include <string.h>
#include <vector>
#include <cmath>
using std::vector;

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

class Edge;
class Node
{
  public:
    vector<Edge *> children_;
    int dp_;
    int bit_;
    int size_;
    int id_;
    Edge *heavy_edge_;
};

class Edge{
public:
    Node *a_;
    Node *b_;
    int bit_;
    Node *another(Node *src)
    {
        return a_ == src ? b_ : a_;
    }
};

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
            data_[i] = -100000000;
        }
    }
    int *version_;
    int *data_;
    int now_;
};

class Summary
{
  public:
    Summary(int cap) : array_(cap)
    {
    }
    void record(int k, int l)
    {
        max_ = std::max(max_, l + array_[k]);
        for (int i = 1, until = 1 << ('v' - 'a'); i <= until; i <<= 1)
        {
            max_ = std::max(max_, l + array_[k ^ i]);
        }
    }
    void add(int k, int l)
    {
        int &m = array_[k];
        m = std::max(m, l);
    }
    int &max()
    {
        return max_;
    }
    void clear(){
        array_.clear();
    }

  private:
    VersionArray array_;
    int max_;
};



Node g_nodes[500000 + 1];
Edge g_edges[500000 + 1];
Summary g_summary(1 << ('v' - 'a' + 1));

void Contribute(Node *root, Node *father, int depth, int mask)
{
    for(auto && edge : root->children_)
    {
        Node *node = edge->another(root);
        if(node == father)
        {
            continue;
        }
        Contribute(node, root, depth + 1, mask ^ edge->bit_);
    }
    g_summary.add(mask, depth);
}

void Calc(Node *root, Node *father, int depth, int mask)
{
    for(auto && edge : root->children_)
    {
        Node *node = edge->another(root);
        if(node == father)
        {
            continue;
        }
        Calc(node, root, depth + 1, mask ^ edge->bit_);
    }
    g_summary.record(mask, depth);
}

void DFS(Node *root, Node *father, int depth, int mask, bool clear)
{
    for(auto && edge : root->children_)
    {
        if(edge == root->heavy_edge_)
        {
            continue;
        }
        Node *node = edge->another(root);
        if(node == father)
        {
            continue;
        }
        DFS(node, root, depth + 1, mask ^ edge->bit_, true);
    }
    if(root->heavy_edge_)
    {
        DFS(root->heavy_edge_->another(root), root, depth + 1, mask ^ root->heavy_edge_->bit_, false);
    }
    g_summary.max() = 0;
    for(auto && edge : root->children_)
    {
        if(edge == root->heavy_edge_)
        {
            continue;
        }
        Node *node = edge->another(root);
        if(node == father)
        {
            continue;
        }
        Calc(node, root, depth + 1, mask ^ edge->bit_);
        Contribute(node, root, depth + 1, mask ^ edge->bit_);
    }
    g_summary.record(mask, depth);
    g_summary.add(mask, depth);
    root->dp_ = std::max(0, g_summary.max() - 2 * depth);
    for(auto && edge : root->children_)
    {
        Node *node = edge->another(root);
        if(node == father)
        {
            continue;
        }
        root->dp_ = std::max(root->dp_, node->dp_);
    }
    
    if(clear)
    {
        g_summary.clear();
    }
}

void HeavyLightChain(Node *root, Node *father)
{
    root->size_ = 1;
    int heavy_size = 0;
    for(auto && edge : root->children_)
    {
        Node *node = edge->another(root);
        if(node == father)
        {
            continue;
        }
        HeavyLightChain(node, root);
        root->size_ += node->size_;
        if(node->size_ > heavy_size)
        {
            heavy_size = node->size_;
            root->heavy_edge_ = edge;
        }
    }
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("D:/database/testcase/code.in", "r", stdin);
    freopen("D:/database/testcase/code.out", "w", stdout);
#endif

    int n;
    scanf("%d", &n);
    for(int i = 1; i <= n; i++)
    {
        g_nodes[i].id_ = i;
    }
    for(int i = 2; i <= n; i++)
    {
        int node_index;
        char c;
        scanf("%d %c", &node_index, &c);
        Edge *edge = &g_edges[i];
        edge->a_ = &g_nodes[i];
        edge->b_ = &g_nodes[node_index];
        edge->bit_ = 1 << (c - 'a');
        g_nodes[i].children_.push_back(edge);
        g_nodes[node_index].children_.push_back(edge);
    }

    HeavyLightChain(&g_nodes[1], NULL);
    DFS(&g_nodes[1], NULL, 0, 0, false);
    for(int i = 1; i <= n; i++)
    {
        printf("%d ", g_nodes[i].dp_);
    }

    return 0;
}