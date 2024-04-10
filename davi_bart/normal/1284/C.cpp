#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
vector<ll> fact;
ll N,M;
int main(){
		ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
		cin>>N>>M;
		fact.push_back(1);
		for(ll i=1;i<=N;i++)fact.push_back((fact[i-1]*i)%M);
		ll t=0;
		for(ll i=1;i<=N;i++){
      t+=((((((N-i+1)*fact[i])%M)*(N-i+1))%M)*fact[N-i])%M;
      t%=M;
		}
		cout<<t<<endl;
    return 0;
}