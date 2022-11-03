#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int mx;
    Node* left;
    Node* right;

    Node() :
        mx(0),
        left(nullptr),
        right(nullptr)
    {
    }
};

void Change(Node* t, int tl, int tr, int pos, int x)
{
    if (tl == tr) {
        t->mx = x;
    } else {
        int tm = (0LL + tl + tr) >> 1;
        if (t->left == nullptr) {
            t->left = new Node();
        }
        if (t->right == nullptr) {
            t->right = new Node();
        }
        if (pos <= tm) {
            Change(t->left, tl, tm, pos, x);
        } else {
            Change(t->right, tm + 1, tr, pos, x);
        }
        t->mx = max(t->left->mx, t->right->mx);
    }
}

int Get(Node* t, int tl, int tr, int l, int r)
{
    if (t == nullptr) {
        return 0;
    }
    if (tl == l && tr == r) {
        return t->mx;
    } else {
        int tm = (0LL + tl + tr) >> 1;
        if (r <= tm) {
            return Get(t->left, tl, tm, l, r);
        } else if (l > tm) {
            return Get(t->right, tm + 1, tr, l, r);
        } else {
            return max(Get(t->left, tl, tm, l, tm),
                       Get(t->right, tm + 1, tr, tm + 1, r));
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);

    int n;
    cin >> n;
    vector<pair<int, int> > a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i].first >> a[i].second;
    }
    sort(a.begin(), a.end());
    Node* root = new Node();
    const int kLeftBorder = 1;
    const int kRightBorder = 2e9;
    int mx = 0;
    for (int i = 0; i < n; ++i) {
        int need = a[i].first - a[i].second;
        int max_val = 0;
        if (need >= kLeftBorder) {
            max_val = Get(root, kLeftBorder, kRightBorder, kLeftBorder, need);
        }
        Change(root, kLeftBorder, kRightBorder, a[i].first + a[i].second, max_val + 1);
    }
    cout << root->mx << endl;
    return 0;
}