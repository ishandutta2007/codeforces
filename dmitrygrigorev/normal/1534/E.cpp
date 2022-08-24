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

int ask(vector<int> &v) {
  cout << "? ";
  for (auto x : v) cout << x+1 << " ";
  cout << endl;

  int t;
  cin >> t;
  return t;

}

int qqq = 0;

int main(){
#ifdef LOCAL
	//freopen("B_input.txt", "r", stdin);
	//freopen("B_output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);
	cin.tie(0);

  int n, k;
  cin >> n >> k;

  if (k % 2 == 0 && n % 2 != 0) {
    cout << -1 << endl;
    exit(0);
  }

  if (k % 2 == 0 && n % 2 != 0) {
    cout << -1 << endl;
    exit(0);
  }

  vector<int> taken(n, 0);
  int ans = 0;
  int chosen = 0;
  int Q = 0;

  while (chosen != n) {

    int to = 0, tz = 0;
    for (auto x : taken) {
      if (x == 0) to++;
      else tz++;
    }

    if (chosen + 2*k <= n || chosen + k == n || Q == 0) {
      vector<int> take;
      int rem = k;

      for (int i = 0; i < n && rem > 0; ++i) {
        if (!taken[i]) {
          taken[i] ^= 1;
          take.pb(i);
          rem--;
          chosen++;
        }
      }

      ans ^= ask(take);
    }

    else if ((chosen - n + 2*k) % 2 == 0 && (chosen - n + 2*k) / 2 <= tz) {

      int ones = (chosen - n + 2*k) / 2;
      int zeros = k - ones;

      vector<int> take;
      for (int i = 0; i < n; ++i) {
        if (!taken[i] && zeros > 0) {
          take.pb(i);
          zeros--;
          taken[i] ^= 1;
          chosen++;
        }
        else if (taken[i] && ones > 0) {
          take.pb(i);
          ones--;
          taken[i] ^= 1;
          chosen--;
        }
      }

      ans ^= ask(take);

    }

    else {

      int ones = 0, zeros = k;
      while (ones > tz || zeros > to) {
        ones++, zeros--;
      }

      if (qqq == 1) {
        ones = k, zeros = 0;
        while (ones > tz || zeros > to) {
          ones--, zeros++;
        }
      }

     // cout << ones << " " << zeros << endl;

      qqq^=1;

      vector<int> take;
      for (int i = 0; i < n; ++i) {
        if (!taken[i] && zeros > 0) {
         // cout << "=== " << i << endl;
          take.pb(i);
          zeros--;
          taken[i] ^= 1;
          chosen++;
        }
        else if (taken[i] && ones > 0) {
          //cout << "??? " << i
          take.pb(i);
          ones--;
          taken[i] ^= 1;
          chosen--;
        }
      }

      ans ^= ask(take);
    }

    Q++;

  }

  cout << "! " << ans << endl;


}