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



int main(){
#ifdef LOCAL
	freopen("B_input.txt", "r", stdin);
	//freopen("B_output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);
	cin.tie(0);

  int n;
  cin >> n;
  map<int, int> was;
  map<pair<int, int>, int> kek;
  ll res = 0;
  for (int i = 0; i < n; ++i) { 
    int w1, w2; cin >> w1 >> w2;

    res += was[w1];
    if (w1 != w2) res += was[w2];
    was[w1]++;
    if (w1 != w2) was[w2]++;

    if (w1 != w2) {
      if (w1 > w2) swap(w1, w2);
      res -= kek[mp(w1, w2)];
      kek[mp(w1, w2)]++;
    }
  }

  cout << res;

}