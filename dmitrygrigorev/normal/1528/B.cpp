#include <bits/stdc++.h>
#define ll long long
#define db long double
#define div djkffdf
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



const int N = 1000007;
int div[N];

int main(){
#ifdef LOCAL
  freopen("B_input.txt", "r", stdin);
  //freopen("A_output.txt", "w", stdout);
#endif
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  for (int i = 1; i < N; ++i) {
    for (int j = i+i; j < N; j += i) div[j]++;
  }

  vector<int> ans;
  ans.pb(1);
  ans.pb(1);

  int sum = 2;
  for (int i = 2; i < N; ++i) {
    int tut = sum;
    add(tut, div[i]);

    ans.pb(tut);
    add(sum, tut);
  }

  int n;
  cin >> n;

  cout << ans[n];



}