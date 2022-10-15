#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

void solve(ll n) {
  if (n%2) {
    cout<<"-1\n";
    return;
  }
  n/=2;
  /// n=3*x+2*y
  if (n<=1) {
    cout<<"-1\n";
    return;
  }
  ll mn,mx;
  if (n%2==0) mx=n/2;
  else mx=(n-3)/2+1;
  if (n%3==0) mn=n/3;
  if (n%3==1) mn=(n-4)/3+2;
  if (n%3==2) mn=(n-2)/3+1;
  cout<<mn<<" "<<mx<<"\n";
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  int t;
  cin>>t;
  while (t--) {
    ll n;
    cin>>n;
    solve(n);

  }


  return 0;
}