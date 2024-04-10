#include <bits/stdc++.h>
#define ll long long
#define db long double
#define x first
#define y second
#define mp make_pair
#define pb push_back
#define all(a) a.begin(), a.end()

#define dbg(a) cout << #a << "=" << (a) << endl; 

using namespace std;

const int mod = 998244353;

void add(int& a, int b) {
  a += b;
  if (a >= mod) a -= mod;
}

int sum(int a, int b) {
  add(a, b);
  return a;
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

int cnk[4084][4084];

inline int go(int a, int b) {
  if (min(a, b) < 0) return 1;
  return cnk[a + b][a];
}

int calc(int n, int m, int need) {
  int res = 0;


  for (int i = 1; i <= n - 1; ++i) {
    vector<int> down = {0};
    
    int suf_sum = 1;

    int final_sum = 0;

    for (int j = m - 1; j >= 1; --j) {


    //  cout << i << ' ' << j << endl;

      int paths_right = go(i - 1, m - j);
      
      int down_left = go(j, n - i - 1);

    //  dbg(paths_right);

      int cur_down = mult(down_left, suf_sum);

      down.pb(sum(down.back(), cur_down));

      add(suf_sum, go(n - i - 1, m - j));

      add(final_sum, mult(paths_right, down[(int)down.size() - 1 - need]));


      ///

      int paths_left = go(i - 1, j - 1);


  //    cout << "=====" << paths_left << ' ' << final_sum << endl;

      add(res, mult(final_sum, paths_left));

    }

  }

 // dbg(res);

  return mult(2, res);
}

int main(){
#ifdef LOCAL
	freopen("A_input.txt", "r", stdin);
	//freopen("A_output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);
	cin.tie(0);

  for (int i = 0; i < 4084; ++i) {
    cnk[i][0] = 1;
    for (int j = 1; j <= i; ++j) {
      add(cnk[i][j], cnk[i - 1][j]);
      add(cnk[i][j], cnk[i - 1][j - 1]);
    }
  }

  int n, m;
  cin >> n >> m;

  int res = calc(n, m, 0);
  add(res, calc(m, n, 1));

  cout << res;
}