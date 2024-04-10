#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
vector<ll> sol(300000);
int main(){
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
		ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
		ll N;
		cin>>N;
		ll s=(2*N*(2*N+1)/2);
		if(s%2==0){
			cout<<"NO";
			return 0;
		}
		for(ll i=1;i<=N;i++){
			sol[i]=2*i-1;sol[i+N]=2*i;
			if(i%2==0)swap(sol[i],sol[i+N]);
		}
		cout<<"YES"<<endl;
		for(ll i=1;i<=2*N;i++)cout<<sol[i]<<" ";
		return 0;
}