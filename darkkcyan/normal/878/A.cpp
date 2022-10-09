#include <bits/stdc++.h>

using namespace std;

#define llong long long 
#define ii pair<int, int>
#define xx first
#define yy second
#define len(v) ((int)v.size())
#define rep(i,n) for (int i = -1; ++i < n; )
#define rep1(i,n) for (int i = 0; i++ < n; )

#define maxn 501010
int n;
char in[maxn];
int a[maxn];

bool eval(bool s, int b) {
  rep(i, n) {
    int t = (a[i] >> b) & 1;
    switch(in[i]) {
      case '&':
        s &= t;
        break;
      case '^':
        s ^= t;
        break;
      case '|':
        s |= t;
        break;
    }
    // clog << i << ' ' << in[i] << ' ' << s << ' ' << bitset<10>(a[i])<< ' ' << b << ' ' << bitset<10>(a[i] >> b) << ' ' << t << endl;
  }
  return s;
}

int mark[10];

int main() {
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  cin >> n;
  rep(i, n) cin >> in[i] >> a[i];
  rep(i, 10) {
    bool u = eval(1, i), v = eval(0, i);
    clog << i << ' ' << u << ' ' << v << endl;
    mark[i] = ((int)u << 1) | v;
  }
  
  cout << "3\n";
  int num = 0;
  rep(i, 10) if (mark[i] != 0) num |= 1 << i;
  cout << "& " << num << '\n';
  num = 0;
  rep(i, 10) if (mark[i] == 3) num |= 1 << i;
  cout << "| " << num << '\n';
  num = 0;
  rep(i, 10) if (mark[i] == 1) num |= 1 << i;
  cout << "^ " << num ;
  
  
  return 0;
}