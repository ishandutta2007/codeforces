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

const int INF = 1e9 + 7;

int main(){
#ifdef LOCAL
	freopen("K_input.txt", "r", stdin);
	//freopen("K_output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);
	cin.tie(0);

  int n;
  cin >> n;
  vector <int> p(2 * n);
  for (int i = 0; i < 2 * n; ++i) {
    cin >> p[i];
  }

  vector <int> sorted = p;
  sort(all(sorted));

  int res = INF;
  auto was = p;

  for (int st = 0; st < 2; ++st) {
    int now = st;
    int cnt = 0;
    p = was;
    if (p == sorted) {
      res = cnt;
      break;
    }
    do {
      assert(cnt <= 4 * n);
      if (now) {
        for (int i = 0; i < n; ++i) {
          swap(p[i], p[i + n]);
        }
      } else {
        for (int i = 0; i < 2 * n; i += 2) {
          swap(p[i], p[i + 1]);
        }
      }
      ++cnt;
     /* for (int x : p) {
        cout << x << " ";
      }
      cout << "\n";*/
      if (p == sorted) {
        res = min(res, cnt);
        break;
      }
      now ^= 1;
    } while (p != was);
  }
  cout << (res == INF ? -1 : res) << "\n";

}