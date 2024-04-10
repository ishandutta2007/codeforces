#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
  //freopen("transform.in", "r", stdin);
  //freopen("transform.out", "w", stdout);
  ios_base::sync_with_stdio(0);
  ll a,b,c;
  cin>>a>>b>>c;
  cout<<(a+b)/c<<" ";
  ll A=a/c,B=b/c;
  if(A+B==(a+b)/c){
    cout<<0;
    return 0;
  }
  cout<<min(c-(a%c),c-(b%c));
  return 0;
}