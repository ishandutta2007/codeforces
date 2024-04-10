#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

bool home = 1;

const int N = (int) 1e5 + 7;
int n, a, b, v[N];
map<int, int> id;
vector<int> g[N];

int t[N];

int root(int a) {
  if (t[a] == a) return a;
  return t[a] = root(t[a]);
}

void unite(int a, int b) {
  t[root(a)] = root(b);
}

bool nope[N][2];

signed main() {
  ios::sync_with_stdio(0); cin.tie(0);

  #ifdef ONLINE_JUDGE
  home = 0;
  #endif // ONLINE_JUDGE


  if (home) {
    freopen ("input", "r", stdin);
  }

  cin >> n >> a >> b;
  for (int i = 1; i <= n; i++) {
    cin >> v[i];
    id[v[i]] = i;
    t[i] = i;
  }

  for (int i = 1; i <= n; i++) {
    if (id.count(a - v[i])) {
      /// x, y sunt in ac set
      /// x e in A => trebuie neaparat ca y sa fie in A
      /// x nu e in A => trebuie neaparat ca y sa nu fie in A (pentru ca daca ar fi atunci ar trb ca si x sa fie in A, dar x e in B)
      unite(i, id[a - v[i]]);
    }
    if (id.count(b - v[i])) {
      /// ac argument
      unite(i, id[b - v[i]]);
    }
  }

  for (int i = 1; i <= n; i++) {
    if (!id.count(a - v[i])) {
      nope[root(i)][0] = 1;
    }
    if (!id.count(b - v[i])) {
      nope[root(i)][1] = 1;
    }
  }

  for (int i = 1; i <= n; i++) {
    if (nope[i][0] && nope[i][1]) {
      cout << "NO\n";
      return 0;
    }
  }


  cout << "YES\n";

  for (int i = 1; i <= n; i++) {
    int j = root(i);
    if (nope[j][0] == 0 && nope[j][1] == 0) {
      nope[j][0] = 1;
    }
    cout << nope[j][0] << " ";
  }
  cout << "\n";

  return 0;
}
/**

**/