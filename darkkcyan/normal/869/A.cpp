#include <bits/stdc++.h>

using namespace std;

#define llong long long 
#define ii pair<int, int>
#define xx first
#define yy second
#define len(v) ((int)v.size())
#define rep(i,n) for (int i = -1; ++i < n; )
#define rep1(i,n) for (int i = 0; i++ < n; )

#define maxv (1 << 22)
#define maxn 2020
int n;
int a[maxn], b[maxn];
bool mark[maxv] = {0};

int main() {
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  cin >> n;
  rep(i, n) cin >> a[i], mark[a[i]] = 1;
  rep(i, n) cin >> b[i], mark[b[i]] = 1;
  
  int cnt = 0;
  rep(i, n) rep(f, n)
    cnt += mark[a[i] ^ b[f]];
    
  clog << cnt << endl;
  if (~cnt & 1) cout << "Karen";
  else cout << "Koyomi";
  
  return 0;
}