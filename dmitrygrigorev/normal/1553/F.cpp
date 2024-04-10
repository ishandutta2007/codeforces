#include <bits/stdc++.h>
#define ll long long
#define db long double
#define x first
#define y second
#define mp make_pair
#define pb push_back
#define all(a) a.begin(), a.end()

using namespace std;

const int mod = 1000000007;

void add(int& a, int b) {
  a += b;
  if (a >= mod) a -= mod;
  if (a < 0) a += mod;
}

int mult(int a, int b) {
  return a * (ll)b % mod;
}

int bp(int a, int b) {
  int res = 1;
  while (b > 0) {
    if (b & 1) res = mult(res, a);
    a = mult(a, a);
    b >>= 1;
  }
  return res;
}

const int N = 400007;
const int MAGIC = 600;
const int LEN = 600;

ll sum[N];
int cnt[N];

void solve() {
  
  int n;
  cin >> n;

  ll ans = 0;

  vector<int> spec;
  for (int i = 0; i < n; ++i) {
    int x;
    cin >> x;
    for (auto t : spec) {
      ans += (x % t);
      ans += (t % x);
    }

    ans += (ll) x * (cnt[N - 1] - cnt[x]);

    for (int i = 1; i < MAGIC; ++i) {
      int tut = cnt[i] - cnt[i - 1];
      if (i < x) ans += (ll) (x % i) * tut; 
    }

    for (int i = MAGIC - 1; i > 0; --i) {
      int R = x / i;
      int L = 1;

      L = (x / (i + 1)) + 1;

      L = max(L, MAGIC);
      R = min(R, x - 1);

      if (L <= R) {
        ans += (ll) x * (cnt[R] - cnt[L - 1]) - (ll) i * (sum[R] - sum[L - 1]);
      }
    }
    for (int times = 1; times * x < N; ++times) {
      int L = times * x, R = min(N - 1, (times + 1) * x - 1);
      ans += (ll) (sum[R] - sum[L - 1]) - (ll) times * x * (cnt[R] - cnt[L - 1]);
    }

    ans += sum[x - 1];

    spec.pb(x);

    if (spec.size() == LEN) {
      for (int i = N-1; i > 0; --i) {
        sum[i] = sum[i] - sum[i-1];
        cnt[i] = cnt[i] - cnt[i-1];
      }
    

      for (auto x : spec) {
        sum[x] += x;
        cnt[x]++;
      }

      spec.clear();
      for (int i = 1; i < N; ++i) {
        sum[i] += sum[i - 1];
        cnt[i] += cnt[i - 1];
      }

    }

    cout << ans << ' ';
  }

}

int main(){
#ifdef LOCAL
	freopen("A_input.txt", "r", stdin);
	//freopen("A_output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);
	cin.tie(0);

  int t = 1;

  for (int i = 0; i < t; ++i) {
    
    solve();

  }

}