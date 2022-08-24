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

int n, m;

void dfs(vector<vector<bool> > &used, vector<vector<char> > &matrix, vector<vector<int> > &cmp, int i, int j, int index) {

  used[i][j] = true;

  if (i + 1 < n && matrix[i+1][j] == '#' && !used[i+1][j]) dfs(used, matrix, cmp, i+1, j, index);
  if (i - 1 >= 0 && matrix[i-1][j] == '#' && !used[i-1][j]) dfs(used, matrix, cmp,  i-1, j, index);
  if (j + 1 < m && matrix[i][j+1] == '#' && !used[i][j+1]) dfs(used, matrix, cmp,  i, j+1, index);
  if (j - 1 >= 0 && matrix[i][j-1] == '#' && !used[i][j-1]) dfs(used, matrix, cmp,  i, j-1, index);

  cmp[i][j] = index;

}

vector<vector<int> > gr, trans;

vector<int> order;
vector<bool> tused;
vector<int> c;

void dfs2(int vertex) {


  tused[vertex] = true;
  for (auto to : gr[vertex]) if (!tused[to]) {
    dfs2(to);
  }

  order.pb(vertex);

}

void dfs3(int vertex, int Z) {


  tused[vertex] = true;
  c[vertex] = Z;

  for (auto to : trans[vertex]) if (!tused[to]) {
    dfs3(to, Z);
  }

}

int main(){
#ifdef LOCAL
	freopen("C_input.txt", "r", stdin);
	//freopen("C_output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);
	cin.tie(0);

  cin >> n >> m;

  vector<vector<char> > matrix(n);
  vector<vector<bool> > used(n);
  vector<vector<int> > cmp(n);

  for (auto &x : matrix) x.assign(m, '.');
  for (auto &x : used) x.assign(m, false);
  for (auto &x : cmp) x.assign(m, -1);

  for (auto &x : matrix) for (auto &y: x) cin >> y;

  vector<int> v(m);
  for (auto &x : v) cin >> x;

  int index = 0;

  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      if (matrix[i][j] == '#' && !used[i][j]) {

        dfs(used, matrix, cmp, i, j, index++);

      }
    }
  }

  gr.assign(index, {});
  trans.assign(index, {});

  for (int i = 0; i < m; ++i) {
    int last = -1;
    for (int j = 0; j < n; ++j) {
      if (cmp[j][i] != -1) {
        int T = cmp[j][i];
        if (last != -1 && last != T) {
          gr[last].pb(T);
          trans[T].pb(last);
        }
        last = T;
      }

      if (i > 0 && cmp[j][i-1] != -1) {
        int T = cmp[j][i-1];
        if (last != -1 && last != T) {
          gr[last].pb(T);
          trans[T].pb(last);
        }
      }

      if (i+1 < m && cmp[j][i+1] != -1) {
        int T = cmp[j][i+1];
        if (last != -1 && last != T) {
          gr[last].pb(T);
          trans[T].pb(last);
        }
      }

    }
  }

  tused.assign(index, false);
  for (int i = 0; i < index; ++i) {

    if (!tused[i]) dfs2(i);

  }  

  reverse(all(order));

  tused.assign(index, false);
  int T = 0;
  c.assign(index, -1);

  for (auto x : order) {
    if (tused[x]) continue;
    dfs3(x, T);
    T++;
  }

  vector<bool> go(T, false);


  for (int i = 0; i < index; ++i) for (auto y : gr[i]) {
    if (c[i] != c[y]) go[c[y]] = true;
  }

  int W = 0;
  for (auto x : go) if (!x) W++;
  cout << W;




}