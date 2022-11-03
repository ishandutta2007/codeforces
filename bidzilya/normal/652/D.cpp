#include <vector>
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

#ifdef LOCAL
    #define LLD_SPEC "%lld"
#else
    #define LLD_SPEC "%I64d"
#endif

struct TNode {
    TNode* Left;
    TNode* Right;
    int Sum;
};

class TSegmentTree {
public:
    void Init(int mn, int mx) {
        Min = mn;
        Max = mx;
        Root = new TNode{nullptr, nullptr, 0};
    }

    void Add(int val) {
        Add(Root, Min, Max, val);
    }

    int Get(int l, int r) {
        l = max(l, Min);
        r = min(r, Max);
        if (l > r) {
            return 0;
        }
        return Get(Root, Min, Max, l, r);
    }
private:
    TNode* Root;
    int Min;
    int Max;

    void Add(TNode* root, int tl, int tr, int pos) {
        if (tl == tr) {
            ++root->Sum;
        } else {
            int tm = (tl + tr) >> 1;

            if (pos <= tm) {
                if (root->Left == nullptr) {
                    root->Left = new TNode{nullptr, nullptr, 0};
                }
                Add(root->Left, tl, tm, pos);
            } else {
                if (root->Right == nullptr) {
                    root->Right = new TNode{nullptr, nullptr, 0};
                }
                Add(root->Right, tm + 1, tr, pos);
            }
            ++root->Sum;
        }
    }

    int Get(TNode* root, int tl, int tr, int l, int r) {
        if (root == nullptr) {
            return 0;
        }
        if (l == tl && r == tr) {
            return root->Sum;
        } else {
            int tm = (tl + tr) >> 1;

            if (r <= tm) {
                return Get(root->Left, tl, tm, l, r);
            } else if (l > tm) {
                return Get(root->Right, tm + 1, tr, l, r);
            } else {
                return Get(root->Left, tl, tm, l, tm) + Get(root->Right, tm + 1, tr, tm + 1, r);
            }
        }
    }
};

const int MIN = -1e9;
const int MAX = 1e9;

struct TBox {
    int Left;
    int Right;
    int Id;
};

bool operator < (const TBox& lhs, const TBox& rhs) {
    return lhs.Left < rhs.Left;
}

int main() {
    int n;
    scanf("%d", &n);

    vector<TBox> a(n);
    for (int i = 0; i < n; ++i) {
        scanf("%d%d", &a[i].Left, &a[i].Right);
        a[i].Id = i;
    }

    sort(a.begin(), a.end());

    vector<int> result(n);

    TSegmentTree st;
    st.Init(MIN, MAX);
    for (int i = n - 1; i >= 0; --i) {
        result[a[i].Id] = st.Get(a[i].Left + 1, a[i].Right - 1);
        st.Add(a[i].Right);
    }

    for (int v : result) {
        printf("%d\n", v);
    }

    return 0;
}