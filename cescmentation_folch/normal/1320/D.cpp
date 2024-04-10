#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pi;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<pi> vpi;
typedef vector<vpi> vvpi;


struct SF {
  pair<int, int> ord;
  int id;
  bool operator<(const SF& s) const { return ord < s.ord; }
};
// This must be filled before calling compute_suffix_array():
int N; // N = S.size()
string S;
// This is filled by compute_suffix_array():
vector<SF> A;
vector<vector<int> > B;
int step;
int lcp(int x, int y) {
  if (x == y) return N - x;
  int res = 0;
  for (int i = step - 1; i >= 0 and x < N and y < N; --i)
    if (B[i][x] == B[i][y]) { x += 1<<i; y += 1<<i; res += 1<<i; }
  return res;
}
const int MAXN = 200005;
SF L2[MAXN];
int pos[MAXN + 2], times[MAXN + 2];
void raddixSort() {
  int k = max(N, 256);
  for (int i = 0; i < k + 2; ++i) times[i] = 0;
  for (int i = 0; i < N; ++i)
    times[A[i].ord.second + 1]++;
  pos[0] = 0;
  for (int i = 1; i < k + 2; ++i)
    pos[i] = pos[i - 1] + times[i - 1];
  for (int i = 0; i < N; ++i)
    L2[pos[A[i].ord.second + 1]++] = A[i];

  for (int i = 0; i < k + 2; ++i)
    times[i] = 0;
  for (int i = 0; i < N; ++i)
    times[L2[i].ord.first + 1]++;
  pos[0] = 0;
  for (int i = 1; i < k + 2; ++i)
    pos[i] = pos[i - 1] + times[i - 1];
  for (int i = 0; i < N; ++i)
    A[pos[L2[i].ord.first + 1]++] = L2[i];
}
void compute_suffix_array() {
  A.resize(N); B.resize(1); B[0].resize(N);
  for (int i = 0; i < N; ++i) B[0][i] = S[i];
  step = 1;
  for (int b = 0, pw = 1; b < N; ++step, pw<<=1) {
    for (int i = 0; i < N; ++i) {
      A[i].ord.first = B[step - 1][i];
      A[i].ord.second = i + pw < N ? B[step - 1][i + pw] : -1;
      A[i].id = i;
    }
    raddixSort();
    B.resize(step + 1); B[step].resize(N);
    b = B[step][A[0].id] = 1;
    for (int i = 1; i < N; ++i) {
      if (A[i - 1] < A[i]) ++b;
      B[step][A[i].id] = b;
    }
  }
}


int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  string a;
  cin >> a;
  string b;
  int cont = 0;
  vi M(n);
  for (int i = 0; i < n; ++i) {
    if (a[i] == '0') {
      if (cont%2) b.push_back('1');
      cont = 0;
      M[i] = (int)b.size();
      b.push_back('0');
    }
    else ++cont;
  }
  if (cont%2) b.push_back('1');
  int sz = b.size();
  N = sz;
  S = b;
  compute_suffix_array();
  vi Z0(n), Z1(n);
  vi Z(n+1,0);
  int ant = -1;
  for (int i = 0; i < n; ++i) {
    if (a[i] == '0') {
      ant = i;
      Z[i+1] = 1;
    }
    Z[i+1] += Z[i];
    Z1[i] = ant;
  }
  ant = n;
  for (int i = n-1; i >= 0; --i) {
    if (a[i] == '0') ant = i;
    Z0[i] = ant;
  }
  int q;
  cin >> q;
  while (q--) {
    int l1, l2, len;
    cin >> l1 >> l2 >> len;
    --l1; --l2;
    //cerr << l1 << ' ' << l2 << ' ' << len << ' ';
    int r1 = l1 + len-1;
    int r2 = l2 + len-1;
    //cerr << r1 << ' '<< r2 << endl;
    int l11 = Z0[l1];
    int l22 = Z0[l2];
    int r11 = Z1[r1];
    int r22 = Z1[r2];
    if (l11 > r1 and l22 > r2) {
      cout << "Yes\n";
      continue;
    }
    else if (l11 > r1 or l22 > r2) {
      cout << "No\n";
      continue;
    }
    int llen = lcp(M[l11], M[l22]);
    if (M[l11] + llen > M[r11] and M[l22] + llen > M[r22] and (l11 - l1)%2 == (l22 - l2)%2 and (r1 - r11)%2 == (r2 - r22)%2 and Z[r1+1] - Z[l1] == Z[r2+1] - Z[l2]) cout << "Yes\n";
    else cout << "No\n";
  }
}