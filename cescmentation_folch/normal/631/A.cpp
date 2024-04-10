#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pi;
typedef vector<int> vi;
typedef vector<pi> vpi;

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  ll A[n+ 1];
  ll B[n+ 1];
  A[0] = B[0]= 0;
  for (int i = 1; i <= n; ++ i) {
    cin >> A[i];

  }
  for (int i = 1; i <= n; ++ i){
    cin >> B[i];

  }
  ll res = 0;
  for (int i = 0; i < n; ++i) {
    ll k = 0;
    ll kk = 0;
    for (int j = i + 1; j <= n; ++j) {
      k |= A[j];
      kk |= B[j];
      res = max(res, k+kk);
    }
  }
  cout << res << endl;
}