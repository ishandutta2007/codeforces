#include <bits/stdc++.h>
using namespace std;

#define llong long long 
#define ii pair<int, int>
#define xx first
#define yy second
#define len(x) ((int)x.size())
#define rep(i,n) for (int i = -1; ++ i < n; )
#define rep1(i,n) for (int i = 0; i ++ < n; )

#define maxlen 32

struct trie {
  trie* c[2];
  int cnt;
  trie() {
    c[0] = c[1] = 0;
    cnt = 0;
  }

  void add(llong num, int p = maxlen - 1) {
    ++cnt;
    if (p < 0) return;
    bool b = (num >> p) & 1;
    if (!c[b]) c[b] = new trie();
    c[b]->add(num, p - 1);
  }
  
  void del(llong num, int p = maxlen - 1) {
    --cnt;
    if (p < 0) return;
    bool b = (num >> p) & 1;
    assert(c[b]);
    c[b]->del(num, p - 1);
  }

  llong findmin(llong num, int p = maxlen - 1) {
    if (p < 0) return 0;
    bool b = (num >> p) & 1;
    if (c[b] && c[b]->cnt != 0) return c[b]->findmin(num, p - 1);
    else return (1ll << p) | c[!b]->findmin(num, p - 1);
  }

  void print(llong num = 0, int p = maxlen - 1) {
    if (p < 0) {
      //clog << bitset<maxlen>(num) << ' ' << cnt << endl;
      return ;
    }
    if (c[0]) c[0]->print(num << 1, p - 1);
    if (c[1]) c[1]->print(num << 1 | 1, p - 1);
  }
};

#define maxn 301010
trie* root = new trie();
int n;
int a[maxn];
int b[maxn];

int main() {
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  cin >> n;
  rep(i, n) cin >> a[i];
  rep(i, n) cin >> b[i], root->add(b[i]);
  //rep(i, n) clog << b[i] << ' ' << bitset<maxlen>(b[i]) << endl;
  //root->print();
  //clog << endl;
  rep(i, n) {
    llong x = root->findmin(a[i]);
    cout << x << ' ';
    //clog << (a[i] ^ x) << endl;
    root->del(a[i] ^ x);
    //root->print();
    //clog << endl;
  }

  return 0;
}