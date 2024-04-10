#include <bits/stdc++.h>
#define ll long long
#define db long double
#define x first
#define y second
#define mp make_pair
#define pb push_back
#define all(a) a.begin(), a.end()

using namespace std;

const int N = 107;

db dp[N][20*N];
db mv[N][20*N];

const int REPEAT = 2;
const int ADD = 2*REPEAT;
const int SPEND = 2*REPEAT+1;

ll money = 1;
ll gM;

void start() {
  money = 1;
  gM = 99999999999808;
}

string ask(ll x) {
  cout << "? " << x << endl;
  string q;
  cin >> q;
  return q;
}

void solve() {

  int rem = 105;

  ll L = 0, R = 100000000000001;
  ll have = 1;

  while (true) {
    if (have >= R) {
      break;
    }
    rem--;
    string s = ask(have);

    if (s == "Lucky!") {
      L = have;
      have += have;
    }
    else {
      R = have;
      have = 0;
      break;
    }
  }

  for (int i = 0; i < REPEAT; ++i) {
    if (R-L==1) break;
    ll M = (L+R)/2;

    while (have < M) {
      rem--;
      string s = ask(L);
      have += L;
    } 

    rem--;
    string s = ask(M);

    if (s == "Lucky!") {
      L = M;
      have += M;
    }
    else {
      R = M;
      have -= M;
      break;
    }
  }

  while (R-L>1 && rem > 0) {
    ll coins = min((ll)18*N, have / L * ADD);
    db opt = mv[rem][coins];

    if (opt < 0.) {
      string s = ask(L);

      rem--;
      have += L;
    }

    else {
      ll M = (db) L + (db) (R - L) / opt;
      if (M==L) M++;
      if (M==R) M--;

      while (have < M) {
        rem--;
        string s = ask(L);
        have += L;
      } 

      rem--;
      string s = ask(M);

      if (s == "Lucky!") {
        L = M;
        have += M;
      }
      else {
        R = M;
        have -= M;
      }

    }

  } 

  cout << "! " << L << endl;


}

int main(){
#ifdef LOCAL
  //freopen("E_input.txt", "r", stdin);
  //freopen("E_output.txt", "w", stdout);
#endif
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  srand(time(0));

  for (int i = 0; i < 20*N; ++i) {
    dp[0][i] = 1.;
  }

  for (int i = 1; i < N; ++i) {
    for (int coins = 0; coins <= 19*N; ++coins) {
      for (db k = 1.01; k <= 30; k *= 1.03) {
        db fm = k;
        db sm = (db) k / (db) (k - 1);

        if (coins >= SPEND) {
          if (min(fm * dp[i-1][coins - SPEND], sm * dp[i-1][coins + ADD]) >= dp[i][coins]) {
            dp[i][coins] = min(fm * dp[i-1][coins - SPEND], sm * dp[i-1][coins + ADD]);
            mv[i][coins] = k;
          }
        }

        if (dp[i-1][coins + ADD] >= dp[i][coins]) {
          dp[i][coins] = dp[i-1][coins + ADD];
          mv[i][coins] = -1;
        }
      }
    }
  }

  int t;
  cin >> t;

  while (t--) {
    solve();
  }

}