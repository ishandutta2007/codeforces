#include <bits/stdc++.h>

using namespace std;

#define llong long long 
#define ii pair<int, int>
#define xx first
#define yy second
#define len(v) ((int)v.size())
#define rep(i,n) for (int i = -1; ++i < n; )
#define rep1(i,n) for (int i = 0; i++ < n; )

#define maxn 111
int n, m;
char a[maxn][maxn];
string s; 

int sr, sc;
int er, ec;

int dr[] = {-1, 0, 1, 0};
int dc[] = {0, -1, 0, 1};
vector<int> ins = {0, 1, 2, 3};

bool ok() {
  int cr = sr, cc = sc;
  for (auto i: s) {
    cr += dr[ins[i - '0']];
    cc += dc[ins[i - '0']];
    if (cr == 0 or cc == 0 or cr == n + 1 or cc == m + 1) return false;
    if (a[cr][cc] == '#') return 0;
    if (a[cr][cc] == 'E') return 1;
  }
  return 0;
}

int main() {
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  cin >> n >> m;
  rep1(i, n) {
    cin >> (a[i] + 1);
    rep1(f, m) {
      if (a[i][f] == 'S') sr = i, sc = f;
      if (a[i][f] == 'E') er = i, ec = f;
    }
  }
  cin >> s;
  int ans = 0;
  do {
    ans += ok();
  } while (next_permutation(ins.begin(), ins.end()));
  cout << ans;
  
  return 0;
}