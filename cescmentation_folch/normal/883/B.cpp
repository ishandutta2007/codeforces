#include<bits/stdc++.h>

using namespace std;

typedef vector<int> vi;
typedef pair<int, int> pi;

const int N= 200010;
vi G[N];
vi T[N];
bool cic;
int K[N];
int M[N];
int I[N];
int V[N];
int R[N];
int F[N];
int A[N];

void dfs(int x) {
  if (K[x] == 2) return;
  if (K[x] == 1) cic = true;
  if (cic) return;
  K[x] = 1;
  for (int i = 0; i < (int)G[x].size(); ++i) {
    int y = G[x][i];
    dfs(y);
  }
  K[x] = 2;
}

int main() {
//  ios_base::sync_with_stdio(false);
 // cin.tie(0);
  int n, m, k;
//  cin >> n >> m >>k;
  scanf("%d %d %d", &n, &m, &k);
  for (int i = 1; i <= n; ++i) scanf("%d", &V[i]); //cin >> V[i];
  for (int i = 0; i < m; ++i) {
    int x, y;
   // cin >> x >> y;
    scanf("%d %d", &x, &y);
    G[x].push_back(y);
    T[y].push_back(x);
    ++R[x];
    ++I[y];
  }
  queue<int> Q;
  cic = false;
  for (int i = 1; i <= n; ++i) {
    F[V[i]] = 1;
    M[i] = k;
    if (V[i] != 0) {
      Q.push(i);
      I[i] = 0;
      M[i] = V[i];
    }
    else if(I[i] == 0) Q.push(i);
    if (K[i] == 0) dfs(i);
  }
  if (cic) {
    //cout << -1 << endl;
    printf("-1\n");
    return 0;
  }
  while (!Q.empty()) {
    int x = Q.front();
    Q.pop();
    for (int i = 0; i < (int)G[x].size(); ++i) {
      int y = G[x][i];
      --I[y];
      M[y] = min(M[y], M[x] - 1);
      if (I[y] == 0) Q.push(y);
    }
  }
  priority_queue<pi> & qP = *new priority_queue<pi>;
  for (int i = 1; i <= n; ++i) {
    if (R[i] == 0) qP.push({-M[i], i});
    if (M[i] < V[i] or M[i] <= 0) {
      //cout << -1 << endl;
      printf("-1\n");
      return 0;
    }
  }
  set<int> &S = *new set<int>;
  for (int i = 1; i <= k; ++i) {
    if (F[i] == 0) S.insert(i);
  }
  for (int i = 0; i <= n; ++i) A[i] = 1;
  while (!qP.empty()) {
    int x = qP.top().second;
    qP.pop();
    if (V[x] == 0) {
      auto it = S.lower_bound(A[x]);
      if (!S.size()) V[x] = M[x];
      else if (it != S.end() and *it <= M[x]) {
	V[x] = *it;
	S.erase(it);
      }
      else V[x] = A[x];
    }
    for (int i = 0; i < (int) T[x].size(); ++i) {
      int y = T[x][i];
      A[y] = max(A[y], V[x] + 1);
      --R[y];
      if (R[y] == 0) qP.push({-M[y], y});
    }
  }
  if (S.size()) {
   //   cout << -1 << endl;
      printf("-1\n");
      return 0;
  }
  for (int i = 1; i <= n; ++i) {
    if (i - 1)printf(" "); // cout << ' ';
  //  cout << V[i] ;
    printf("%d", V[i]);
  }
  printf("\n");
 // cout << endl;
}