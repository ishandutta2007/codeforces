#include <bits/stdc++.h>
#define ll long long
#define db long double
#define x first
#define y second
#define mp make_pair
#define pb push_back
#define all(a) a.begin(), a.end()
#define dbg(a) cerr << #a << ' = ' << (a) << endl; 

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



int main(){
#ifdef LOCAL
	freopen("E_input.txt", "r", stdin);
	//freopen("E_output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);
	cin.tie(0);

  int q;cin >> q;
  while (q--) {
    int u, v;
    cin >> u >> v;

    int can = 1;

    int vu = -1;
    for (int i = 30; i >= 0; --i) {
      int a = (u >> i) & 1;
      int b = (v >> i) & 1;
      if (a != b) {
        if (a == 1) can = 0;
        vu = i;
        break;
      }
    }

    if (vu != -1 && can) {
      vector<int> w1, w2;
      for (int i = 0; i <= vu; ++i) { 
        int a = (u >> i) & 1;
        int b = (v >> i) & 1;
        if (a) w1.pb(i);
        if (b) w2.pb(i);
      }
      if (w1.size() < w2.size()) {
        can = 0;
      } else {
        for (int i = 0; i + 1 < w2.size(); ++i) if (w1[i] > w2[i]) can = 0;
      }
    }

    if (can) cout << "YES\n"; else cout << "NO\n";
  }
}