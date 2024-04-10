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

int n;

vector<int> ask(int x) {
  cout << "? " << x+1 << endl;
  vector<int> v(n);

  for (auto &x : v) cin >> x;
  return v;

}

void add(int vertex, vector<int> &v, set<pair<int, int> > &ms) {
  for (int i = 0; i < n; ++i) if (v[i] == 1) {
    if (i < vertex) ms.insert(mp(i, vertex));
    if (vertex < i) ms.insert(mp(vertex, i));
  }
}

void print(set<pair<int, int> > &ms) {
  cout << "!" << endl;
  for (auto p : ms) {
    cout << p.x+1 << " " << p.y+1 << endl;
  }
}

int main(){
#ifdef LOCAL
	//freopen("B_input.txt", "r", stdin);
	//freopen("B_output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);
	cin.tie(0);

  cin >> n;

  auto A = ask(0);
  set<pair<int, int> > edges;

  add(0, A, edges);
  int ev = 0, odd = 0;
  for (auto x : A) {
    if (x == 0) continue;
    if (x%2==0) ev++;
    else odd++;
  }

  if (ev < odd) {
    for (int i = 0; i < n; ++i) {
      if (A[i] == 0 || A[i] % 2 != 0) continue;
      auto B = ask(i);
      add(i, B, edges);
    }
  }

  else {
    for (int i = 0; i < n; ++i) {
      if (A[i] == 0 || A[i] % 2 == 0) continue;
      auto B = ask(i);
      add(i, B, edges);
    }
  }

  print(edges);

}