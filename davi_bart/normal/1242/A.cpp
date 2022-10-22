#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
		ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    ll N;
    cin>>N;
    ll s=N;
    for(ll i=2;i<=sqrt(N);i++){
      if(N%i==0){
        s=__gcd(s,i);
        s=__gcd(s,N/i);
      }
    }
    cout<<s;
		return 0;
}