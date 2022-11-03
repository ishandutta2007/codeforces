#include <bits/stdc++.h>
#define ll long long
#define x first
#define y second
#define mp make_pair
#define pb push_back
#define all(a) a.begin(), a.end()
#define dbg(a) cerr << #a << " = " << a << endl; 
#define forn(i, n) for (int i = 0; i < (n); ++i)

using namespace std;

int n;
int a[111111];

int suka[100007];

int nxt[100007];

int main(){
#ifdef LOCAL
	freopen("C_input.txt", "r", stdin);
	//freopen("C_output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);
	cin.tie(0);

  cin >> n;

  vector<pair<int, int> > t;

  for (int i = 0; i < n; ++i) {
    cin >> a[i];
    if (t.size() == 0 || t.back().x != a[i]) {
      t.pb(mp(a[i], 1));
    } else {
      t.back().y++;
    }
  }

  map<int, int> was;
  for (int i = (int)t.size() - 1; i >= 0; --i) {

    if (was.find(t[i].x) != was.end()) {
      nxt[i] = was[t[i].x];
    } else {
      nxt[i] = -1;
    }

    was[t[i].x] = i;
  }


  int* dp = suka + 1;

  dp[0] = 1;
  for (int i = 1; i < t.size(); ++i) dp[i] = 1e9;


  for (int i = 0; i < t.size(); ++i) {
    if (nxt[i] != -1) {
      dp[nxt[i]] = min(dp[nxt[i]], dp[i] + nxt[i] - i - 1);
    }
    if (i > 0 && nxt[i - 1] != -1) {
      dp[nxt[i - 1]] = min(dp[nxt[i - 1]], dp[i] + nxt[i - 1] - i - 1); 
    }
    dp[i + 1] = min(dp[i + 1], dp[i] + 1);
  }


  int res = 1e9;

  for (int i = 0; i < t.size(); ++i) {
    res = min(res, dp[i] + (int)t.size() - i - 1);
  }

  cout << res;

}