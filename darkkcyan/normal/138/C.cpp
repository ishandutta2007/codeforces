#include <bits/stdc++.h>
using namespace std;

#define llong long long 
#define xx first
#define yy second
#define len(x) ((int)x.size())
#define rep(i,n) for (int i = -1; ++ i < n; )
#define rep1(i,n) for (int i = 0; i ++ < n; )
#define all(x) x.begin(), x.end()

#define uptr unique_ptr
#define mku make_unique

// [l; r)
struct itnode {
  uptr<itnode> lchild, rchild;
  int l, r;
  long double sum, lz;

  itnode(int _l, int _r, function<long double(int)> getArr) : l(_l), r(_r), sum(getArr(_l)), lz(1) {
    if (r - l <= 1) return ;
    int mid = (l + r) / 2;
    lchild = mku<itnode>(l, mid, getArr);
    rchild = mku<itnode>(mid, r, getArr);
    sum = lchild->sum + rchild->sum;
  }

  void dolz() {
    sum *= lz;
    if (lchild) lchild->lz *= lz;
    if (rchild) rchild->lz *= lz;
    lz = 1;
  }

  void upd(int rangel, int ranger, long double val) {
    dolz();
    if (rangel >= r or l >= ranger) return;
    if (rangel <= l and r <= ranger) {
      lz *= val;
      dolz();
      return;
    }

    lchild->upd(rangel, ranger, val);
    rchild->upd(rangel, ranger, val);
    sum = lchild->sum + rchild->sum;
  }

  // no need for get
};

struct Tree {
  int x, h, probl, probr;
};

#define maxn 101010
int n, m;
Tree trees[maxn];
pair<int, int> mush[maxn];

int main(void) {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> m;
    rep(i, n) cin >> trees[i].x >> trees[i].h >> trees[i].probl >> trees[i].probr;
    rep(i, m) cin >> mush[i].xx >> mush[i].yy;
    sort(mush, mush + m);

    auto root = mku<itnode>(0, m, [](int i) { return (long double)mush[i].yy; });
    rep(i, n) {
      int rangel, ranger;

      rangel = (int)(lower_bound(mush, mush + m, make_pair(trees[i].x - trees[i].h, INT_MIN)) - mush);
      ranger = (int)(lower_bound(mush, mush + m, make_pair(trees[i].x, INT_MIN)) - mush);
      root->upd(rangel, ranger, 1.0 - trees[i].probl / 100.0);

      rangel = (int)(upper_bound(mush, mush + m, make_pair(trees[i].x, INT_MAX)) - mush);
      ranger = (int)(upper_bound(mush, mush + m, make_pair(trees[i].x + trees[i].h, INT_MAX)) - mush);
      root->upd(rangel, ranger, 1.0 - trees[i].probr / 100.0);
    }

    cout << fixed << setprecision(10) << root->sum;

    return 0;
}