#include <bits/stdc++.h>
#define ll long long
#define db long double
#define x first
#define y second
#define mp make_pair
#define pb push_back
#define all(a) a.begin(), a.end()

using namespace std;

const int mod = 998244353;

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

const int N = 100007;
int fact[N];

struct Ans {
  vector<int> g[4];
};

class NTT{
public:
  #define db long double 
  #define ll long long
  const static int mod = 998244353;
  const static int root = 646; // 646^(2^20) == 1 (998244353)
  const static int rev_root = 208611436;
  const static int root_deg = 1 << 20;
  const static int MAX_SIZE = 1 << 21;

  void add(int &a, int b){
    a += b;
    if (a < 0) a += mod;
    if (a >= mod) a -= mod;
  }

  int sum(int a, int b){
    add(a, b);
    return a;
  }

  int mult(int a, int b){
    return a * (ll)b % mod;
  }

  int bp(int a, int n) {
    int res = 1;
    while (n) {
      if (n & 1) res = mult(res, a);
      a = mult(a, a);
      n >>= 1;
    }
    return res;
  }

  int rev(int a){
    return bp(a, mod - 2);
  }

  int n;
  int a[MAX_SIZE * 2 + 7], b[MAX_SIZE * 2 + 7];

  int getReverse(int a, int k){
    int ans = 0;
    for (int i = 0; i < k; i++) if ((a >> i) & 1) ans ^= (1 << (k - i - 1));
    return ans;
  }

  void ntt(int *a, int type){
    int k = -1;
    for (int i = 0; i < 25; i++) if ((n >> i) & 1){ 
      k = i;
      break;
    }
    for (int i = 0; i < n; i++){
      int j = getReverse(i, k);
      if (i < j) swap(a[i], a[j]);
    }
    for (int len = 2; len <= n; len *= 2){
      int w = bp(root, root_deg / len);
      if (type == -1) w = bp(rev_root, root_deg / len);
      for (int i = 0; i < n; i += len){
        int g = 1;
        for (int j = 0; j < len / 2; j++){
          int x = a[i + j];
          int y = mult(a[i + j + len / 2], g);
          a[i + j] = sum(x, y);
          a[i + j + len / 2] = sum(x, mod - y);
          g = mult(g, w);
        }
      }
    }
    if (type == -1){ 
      int rev_n = rev(n);
      for (int i = 0; i < n; i++) a[i] = mult(a[i], rev_n);
    }
  }

  vector<int> mult(vector<int> &w1, vector<int> &w2){
    n = 1;
    while(n < w1.size() + w2.size()) n *= 2;
    
    /* for (int i = 0; i < w1.size(); i++){
      a[i] = w1[i];
      a[i] %= mod;
      if (a[i] < 0) a[i] += mod;
    }
    for (int i = 0; i < w2.size(); i++){
      b[i] = w2[i];
      b[i] %= mod;
      if (b[i] < 0) b[i] += mod;
    } */

    std::copy(w1.begin(), w1.end(), a);
    std::copy(w2.begin(), w2.end(), b);
    std::fill(a + w1.size(), a + n, 0);
    std::fill(b + w2.size(), b + n, 0);

    ntt(a, 1);
    ntt(b, 1);
    for (int i = 0; i < n; i++) a[i] = mult(a[i], b[i]);
    ntt(a, -1);
    vector<int> ans(n);
    for (int i = 0; i < n; i++) ans[i] = a[i];
    while(ans.size() && ans.back() == 0) ans.pop_back();
    return ans;
  }
};

//////////// (0,0) (0,1) (1,0) (1,1)

vector<int> add(vector<int> a, vector<int> b) {

  vector<int> c(max(a.size(), b.size()), 0);
  for (int i = 0; i < a.size(); ++i) add(c[i], a[i]);
  for (int i = 0; i < b.size(); ++i) add(c[i], b[i]);

  return c;

}

NTT fft;

Ans solve(vector<int> &v, int l, int r) {

  if (l == r) {
    vector<int> a = {0, (v[l] > 1) + 1};
    vector<int> b = {0, 2};
    vector<int> c = {1};
    vector<int> d = {1};
    Ans ans;
    ans.g[0] = a, ans.g[1] = b, ans.g[2] = c, ans.g[3] = d;
    return ans;
  }

  int mid = (l+r)/2;
  auto A = solve(v, l, mid), B = solve(v, mid + 1, r);

  Ans ans;
  ans.g[0] = add(fft.mult(A.g[0], B.g[0]), fft.mult(A.g[1], B.g[2]));
  ans.g[1] = add(fft.mult(A.g[0], B.g[1]), fft.mult(A.g[1], B.g[3]));
  ans.g[2] = add(fft.mult(A.g[2], B.g[0]), fft.mult(A.g[3], B.g[2]));
  ans.g[3] = add(fft.mult(A.g[2], B.g[1]), fft.mult(A.g[3], B.g[3]));

  //cout << l << " " << r << " " << ans.g[0].size() << endl;

  return ans;


}

int main(){
#ifdef LOCAL
	freopen("N_input.txt", "r", stdin);
	//freopen("N_output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);
	cin.tie(0);

  fact[0] = 1;
  for (int i = 1; i < N; ++i) fact[i] = mult(i, fact[i - 1]);

  int n;
  cin >> n;

  vector<int> v(n);
  for (auto &x : v) cin >> x;

  int start = 0;
  vector<int> arr;

  while (start < n) {
    if (start + v[start] > n) {
      cout << 0;
      exit(0);
    }
    for (int i = 0; i < v[start]; ++i) {
      if (v[i + start] != v[start]) {
        cout << 0;
        exit(0);
      }
    }

    arr.pb(v[start]);
    start += v[start];
  }

  int ans = 0;

  auto res = solve(arr, 0, arr.size() - 1).g[0];
  for (int i = 0; i <= arr.size(); ++i) {
    int viol = arr.size() - i;
    if (viol % 2 == 0) add(ans, mult(fact[i], res[i]));
    else add(ans, -mult(fact[i], res[i]));
  }

  cout << ans;

}