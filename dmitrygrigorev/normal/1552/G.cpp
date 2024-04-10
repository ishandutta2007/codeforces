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

int n, k;
void gen(int x, vector<vector<int> > &v, vector<int> &arr) {
  if (x == k) {
    for (auto t : arr) if (t == 2) {
      cout << "REJECTED";
      exit(0);
    }
    for (int i = 1; i < arr.size(); ++i) if (arr[i - 1] > arr[i]) {
      cout << "REJECTED";
      exit(0);
    }
    return;
  }

  int have = 0;
  auto Q = arr;
  for (auto t : v[x]) if (arr[t] == 2) {
    have++;
    Q[t] = 0;
  }

  int zs = 0;
  for (auto t : v[x]) if (Q[t] == 0) zs++;
  for (auto t : v[x]) {
    if (zs) {
      zs--;
      Q[t] = 0;
    }
    else Q[t] = 1;
  }

  int u = ((int) v[x].size()) - 1;
  while (u >= 0 && Q[v[x][u]] == 1) --u;


  for (int i = 0; i <= have; ++i) {
    gen(x + 1, v, Q);
    if (i == have) break;
    Q[v[x][u--]] = 1;
  }

}

int main(){
#ifdef LOCAL
	freopen("G_input.txt", "r", stdin);
	//freopen("G_output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);
	cin.tie(0);

  cin >> n >> k;

  if (n == 1) {
    cout << "ACCEPTED";
    exit(0);
  }

  vector<vector<int> > v(k);
  for (auto &x : v) {
    int len;
    cin >> len;

    x.assign(len, -1);
    for (auto &y : x) {
      cin >> y;
      --y;
    }
  }

  vector<int> arr(n, 2);
  gen(0, v, arr);

  cout << "ACCEPTED";

}