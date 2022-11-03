#include <bits/stdc++.h>
using namespace std;

struct Data
{
    int suff_len;
    int pref_len;
    int ans;

    Data() :
        suff_len(0),
        pref_len(0),
        ans(0)
    {
    }
};

struct SegTree
{
    Data data;

    SegTree* left;
    SegTree* right;

    SegTree() :
        data(),
        left(nullptr),
        right(nullptr)
    {
    }
};

Data Unite(Data left, Data right, int left_len, int right_len)
{
    Data res;
    if (left.pref_len == left_len) {
        res.pref_len = left_len + right.pref_len;
    } else {
        res.pref_len = left.pref_len;
    }
    if (right.suff_len == right_len) {
        res.suff_len = right_len + left.suff_len;
    } else {
        res.suff_len = right.suff_len;
    }
    res.ans = max(left.ans, max(right.ans, left.suff_len + right.pref_len));
    return res;
}

SegTree* IncVal(SegTree* tree, int tree_left, int tree_right, int pos)
{
    SegTree* res = new SegTree();
    if (tree_left == tree_right) {
        res->data.suff_len = res->data.pref_len = res->data.ans = 1;
    } else {
        int tree_middle = (tree_left + tree_right) >> 1;

        if (pos <= tree_middle) {
            res->left = IncVal(tree->left, tree_left, tree_middle, pos);
            res->right = tree->right;
        } else {
            res->left = tree->left;
            res->right = IncVal(tree->right, tree_middle + 1, tree_right, pos);
        }

        res->data = Unite(res->left->data, res->right->data, tree_middle - tree_left + 1,
                                                             tree_right - (tree_middle + 1) + 1);
    }
    return res;
}

Data GetAns(SegTree* tree, int tree_left, int tree_right, int left, int right)
{
    if (tree_left == left && tree_right == right) {
        return tree->data;
    } else {
        int tree_middle = (tree_left + tree_right) >> 1;

        if (right <= tree_middle) {
            return GetAns(tree->left, tree_left, tree_middle, left, right);
        } else if (left > tree_middle) {
            return GetAns(tree->right, tree_middle + 1, tree_right, left, right);
        } else {
            return Unite(GetAns(tree->left, tree_left, tree_middle, left, tree_middle),
                         GetAns(tree->right, tree_middle + 1, tree_right, tree_middle + 1, right),
                         tree_middle - left + 1,
                         right - (tree_middle + 1) + 1);
        }
    }
}

SegTree* Build(int left, int right)
{
    SegTree* res = new SegTree();
    if (left != right) {
        int middle = (left + right) >> 1;

        res->left = Build(left, middle);
        res->right = Build(middle + 1, right);
    }
    return res;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    vector<pair<int, int> > b(n);
    for (int i = 0; i < n; ++i) {
        b[i].first = a[i];
        b[i].second = i;
    }
    sort(b.begin(), b.end());

    vector<SegTree*> c(n);
    c[n - 1] = Build(0, n - 1);
    c[n - 1] = IncVal(c[n - 1], 0, n - 1, b[n - 1].second);
    for (int i = n - 2; i >= 0; --i) {
        c[i] = IncVal(c[i + 1], 0, n - 1, b[i].second);
    }

    int q;
    cin >> q;
    for (int itr = 0; itr < q; ++itr) {
        int l, r, w;
        cin >> l >> r >> w;
        --l;
        --r;

        int bl = 0;
        int br = n - 1;
        int ba = 0;
        while (bl <= br) {
            int bm = (bl + br) >> 1;

            int ans = GetAns(c[bm], 0, n - 1, l, r).ans;
            if (ans >= w) {
                ba = bm;
                bl = bm + 1;
            } else {
                br = bm - 1;
            }
        }
        cout << b[ba].first << endl;
    }


    return 0;
}