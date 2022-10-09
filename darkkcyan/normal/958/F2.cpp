#include <bits/stdc++.h>
using namespace std;

#define llong long long 
#define ii pair<int, int>
#define xx first
#define yy second
#define len(x) ((int)x.size())
#define rep(i,n) for (int i = -1; ++ i < n; )
#define rep1(i,n) for (int i = 0; i ++ < n; )

#define maxn 201010
int n, m;
int a[maxn];
int b[maxn];

int mustgo = 0;
int colorleft;
void rem(int col) {
  --b[col];
  if (b[col] == 0) {
    colorleft --;
    return ;
  }
  if (b[col] < 0) mustgo++;
}
void add(int col) {
  ++b[col];
  if (b[col] <= 0) --mustgo;
  if (b[col] == 1) ++colorleft;
}

int main() {
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  cin >> n >> m;
  rep(i, n) cin >> a[i], --a[i];
  colorleft = m;
  rep(i, m) cin >> b[i], colorleft -= b[i] == 0;
  int r = -1;
  int ans = INT_MAX;
  rep(l, n) {
    while (r + 1 < n and colorleft > 0) rem(a[++r]);
    if (colorleft > 0) break;
    ans = min(ans, mustgo);
    add(a[l]);
  }
  if (ans == INT_MAX) ans = -1;
  cout << ans;

  return 0;
}