#include <bits/stdc++.h>
using namespace std;

#define llong long long 
#define ii pair<int, int>
#define xx first
#define yy second
#define len(x) ((int)x.size())
#define rep(i,n) for (int i = -1; ++ i < n; )
#define rep1(i,n) for (int i = 0; i ++ < n; )
#define lv 33

int decomb(llong* a, int n) {
  int l = 0;
  rep(r, n) {
    if (~a[r] & 1) {
      swap(a[l], a[r]);
      ++l;
    }
  }
  return l;
}

struct trie {
  trie* child[2];
  int cnt[2];
  trie() : child{0}, cnt{0} {}
  ~trie() {
    if (child[0]) {
      delete child[0];
      delete child[1];
    }
  }
};

int ans = 2;

template<bool s>
void insert(trie* root, llong num) {
  for (int i = lv; i--; ) {
    root->cnt[(num & 1) ^ s] ++;
    ans = max(ans, root->cnt[(num & 1) ^ s]);
    if (!root->child[num & 1])
      root->child[num & 1] = new trie();
    root = root->child[num & 1];
    num >>= 1;
  }
}

#define maxn 101010
int n, m;
llong a[maxn], b[maxn];
trie* root = new trie();


int main() {
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  int t;
  cin >> n >> t;
  rep(i, n) cin >> a[i];
  cin >> m >> t;
  rep(i, m) cin >> b[i];

  rep(i, n) insert<0>(root, a[i]);
  rep(i, m) insert<1>(root, b[i]);
  delete root;
  cout << ans;

  return 0;
}