#include <bits/stdc++.h>
using namespace std;

inline int GetRand()
{
    return rand();
}

struct Node
{
    int cnt;
    int prior;
    int val;
    Node* left;
    Node* right;
};

const int kMaxAmountOfNodes = 2e6;

Node nodes[kMaxAmountOfNodes];
int last_node = 0;

typedef Node* PNode;

PNode NewNode(int val)
{
    nodes[last_node].cnt = 1;
    nodes[last_node].prior = rand();
    nodes[last_node].val = val;
    nodes[last_node].left = nodes[last_node].right = nullptr;
    ++last_node;
    return &nodes[last_node - 1];
}

int GetCnt(PNode tree)
{
    if (tree == nullptr) {
        return 0;
    } else {
        return tree->cnt;
    }
}

void UpdateCnt(PNode tree)
{
    tree->cnt = 1 + GetCnt(tree->left) + GetCnt(tree->right);
}

PNode Merge(PNode l, PNode r)
{
    if (l == nullptr) {
        return r;
    }
    if (r == nullptr) {
        return l;
    }
    if (l->prior > r->prior) {
        l->right = Merge(l->right, r);
        UpdateCnt(l);
        return l;
    } else {
        r->left = Merge(l, r->left);
        UpdateCnt(r);
        return r;
    }
}

// <= key, > key
void Split(PNode t, PNode& l, PNode& r, int key)
{
    if (t == nullptr) {
        l = r = nullptr;
        return;
    }
    int cur_key = 1 + GetCnt(t->left);
    if (cur_key <= key) {
        l = t;
        Split(l->right, l->right, r, key - cur_key);
        UpdateCnt(l);
    } else {
        r = t;
        Split(r->left, l, r->left, key);
        UpdateCnt(r);
    }
}

PNode Build(const vector<int>& a)
{
    PNode result = nullptr;
    for (int i = 0; i < (int) a.size(); ++i) {
        result = Merge(result, NewNode(a[i]));
    }
    return result;
}

PNode Build(int n)
{
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        a[i] = i + 1;
    }
    return Build(a);
}

int ToBeginAndGetValue(PNode& t, int key)
{
    PNode l, m, r;
    Split(t, l, r, key);
    Split(l, l, m, key - 1);
    int result = m->val;
    t = Merge(m, Merge(l, r));
    return result;
}
/*
void GetValues(PNode t, vector<int>& values)
{
    if (t->left != nullptr) {
        GetValues(t->left, values);
    }
    values.push_back(t->val);
    if (t->right != nullptr) {
        GetValues(t->right, values);
    }
}

vector<int> GetValues(PNode t)
{
    vector<int> result;
    GetValues(t, result);
    return result;
}
*/
int main()
{
/*
    freopen("input.txt", "w", stdout);
    cout << 1e6 << " " << 1e6 << endl;
    for (int i = 0; i < 1e6; ++i) {
        cout << i + 1 << " " << i + 1 << endl;
    }
    return 0;
*/
 //   freopen("input.txt", "r", stdin);
  //  freopen("output.txt", "w", stdout);

    srand(time(nullptr));

    int n, m;
    vector<int> x, y;
    scanf("%d%d", &n, &m);
    x.resize(m);
    y.resize(m);
    for (int i = 0; i < m; ++i) {
        scanf("%d%d", &x[i], &y[i]);
        --x[i];
    }

    PNode t = Build(n);

    vector<int> a(n, -1);
    vector<int> mp(n + 1, -1);
    for (int i = 0; i < m; ++i) {
        int val = ToBeginAndGetValue(t, y[i]);
        if (a[x[i]] == -1) {
            a[x[i]] = val;
            mp[val] = x[i];
        } else {
            if (mp[val] != x[i]) {
                cout << -1 << endl;
                return 0;
            }
        }
    }

    vector<bool> used_pos(n + 1, false);
    for (int i = 0; i < n; ++i) {
        if (a[i] == -1) {
            continue;
        }
        if (used_pos[a[i]]) {
            cout << -1 << endl;
            return 0;
        }
        used_pos[a[i]] = true;
    }

    vector<int> ans(n, -2);
    for (int i = 0; i < n; ++i) {
        if (a[i] != -1) {
            ans[a[i] - 1] = i;
        }
    }

    vector<bool> used_val(n, false);
    for (int i = 0; i < n; ++i) {
        if (ans[i] != -2) {
            used_val[ans[i]] = true;
        }
    }
    int last = 0;
    for (int i = 0; i < n; ++i) {
        if (ans[i] == -2) {
            while (used_val[last]) {
                ++last;
            }
            ans[i] = last;
            used_val[last] = true;
        }
    }

    for (int i = 0; i < n; ++i) {
        cout << ans[i] + 1 << " ";
    }
    cout << endl;

    return 0;
}