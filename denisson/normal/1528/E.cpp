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

int fup[1000007];
int pr[1000007];
int dp[1000007];

int main(){
#ifdef LOCAL
	freopen("E_input.txt", "r", stdin);
	//freopen("E_output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);
	cin.tie(0);

  int n; cin >> n;

  fup[0] = 1;
  pr[0] = 1;

  int rev2 = bp(2, mod - 2);
  int rev6 = bp(6, mod - 2);

  for (int i = 1; i <= n; ++i) {
    add(fup[i], fup[i - 1]);
    
    int now = mult(fup[i - 1], fup[i - 1]);
    add(now, fup[i - 1]);
    now = mult(now, rev2);

    add(fup[i], now);

    if (i - 2 >= 0) add(fup[i], mult(fup[i - 1], pr[i - 2]));
 //   cout << i << ' ' << fup[i] << endl;

    pr[i] = pr[i - 1];
    add(pr[i], fup[i]);
  }

  dp[0] = 1;

  for (int i = 1; i <= n; ++i) {

    dp[i] = 0;

    {

    ///    cout << "AAAAAAAAAAAAAAAAAAAAAA " << dp[i] << endl;
        
        // 1
  ///      add(dp[i], fup[i - 1]);

  ///      cout << "AAAAAAAAAAAAAAAAAAAAAA " << dp[i] << endl;
        
        // 2
        int now = mult(fup[i - 1], fup[i - 1]);
        add(now, fup[i - 1]);
        now = mult(now, rev2);
        add(dp[i], now);

     //   cout << "AAAAAAAAAAAAAAAAAAAAAA " << dp[i] << endl;

        // 3
        // 1 - 2 - 3
        now = fup[i - 1];
        int f = fup[i - 1]; add(f, -1);
        now = mult(now, f);
        add(f, -1);
        now = mult(now, f);
        now = mult(now, rev6);

        add(dp[i], now);

    //    cout << "AAAAAAAAAAAAAAAAAAAAAA " << dp[i] << endl;

        // 1 - 1 - 2
        now = fup[i - 1];
        f = fup[i - 1]; add(f, -1);
        now = mult(now, f);

        add(dp[i], now);

     //   cout << "AAAAAAAAAAAAAAAAAAAAAA " << dp[i] << endl;

        // 1 - 1 - 1
        add(dp[i], fup[i - 1]);

     //   cout << "AAAAAAAAAAAAAAAAAAAAAA " << dp[i] << endl;

        // ===============================
        if (i - 2 >= 0) {
          // 2
          add(dp[i], mult(fup[i - 1], pr[i - 2]));

      //    cout << "BBB " << dp[i] << endl;

          // 3
          int now = mult(fup[i - 1], fup[i - 1]);
          add(now, fup[i - 1]);
          now = mult(now, rev2);
          add(dp[i], mult(now, pr[i - 2]));

     //     cout << "BBB " << dp[i] << ' ' << pr[i - 2] << ' ' << now << endl;

          now = mult(pr[i - 2], pr[i - 2]);
          add(now, pr[i - 2]);
          now = mult(now, rev2);
          add(dp[i], mult(now, fup[i - 1]));

    //      cout << "BBB " << dp[i] << endl;
        }

     ///   cout << "AAAAAAAAAAAAAAAAAAAAAA " << dp[i] << endl;
 ///       add(dp[i], -1);

      } 

    dp[i] = mult(dp[i], 2);
/*
    for (int w1 = 0; w1 <= i; ++w1) {
      for (int w2 = 0; w2 <= i; ++w2) if (w1 + w2 < i) {
        {

          int p1 = 1, p2 = 1;
          if (w1 > 0) {
            p1 = mult(fup[w1 - 1], fup[w1 - 1]);
            add(p1, fup[w1 - 1]);
            p1 = mult(p1, rev2);

            if (w1 - 2 >= 0) add(p1, mult(fup[w1 - 1], pr[w1 - 2]));
          }
          if (w2 > 0) {
            p2 = mult(fup[w2 - 1], fup[w2 - 1]);
            add(p2, fup[w2 - 1]);
            p2 = mult(p2, rev2);

            if (w2 - 2 >= 0) add(p2, mult(fup[w2 - 1], pr[w2 - 2]));
          }

          add(dp[i], mult(p1, p2));
        }
      }
    }*/

  }

  int res = 0;
  for (int w1 = 0; w1 < n; ++w1) {
    int p1 = 1, p2 = 1;

    if (w1 > 0) {
      p1 = mult(fup[w1 - 1], fup[w1 - 1]);
      add(p1, fup[w1 - 1]);
      p1 = mult(p1, rev2);

      if (w1 - 2 >= 0) add(p1, mult(fup[w1 - 1], pr[w1 - 2]));
    }

    add(res, p1);

    int w2 = n - w1 - 1;

    if (w2 > 0) {
      p2 = mult(fup[w2 - 1], fup[w2 - 1]);
      add(p2, fup[w2 - 1]);
      p2 = mult(p2, rev2);

      if (w2 - 2 >= 0) add(p2, mult(fup[w2 - 1], pr[w2 - 2]));
    }

    add(dp[n], mult(res, p2));
  }  

  cout << dp[n];
}