#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
		ios_base::sync_with_stdio(0);
		cin.tie(0);cout.tie(0);
		ll N,M;
		cin>>N>>M;
		ll muri=__gcd(N,M);
		ll grup1=N/muri,grup2=M/muri;
		int Q;
		cin>>Q;
		for(int i=0;i<Q;i++){
			ll a,b;
			cin>>a>>b;
			ll sector;
			if(a==1){
				sector=b/grup1;
				if(b%grup1==0)sector--;
			}else{
				sector=b/grup2;
				if(b%grup2==0)sector--;
			}
			cin>>a>>b;
			ll sector1;
			if(a==1){
				sector1=b/grup1;
				if(b%grup1==0)sector1--;
			}else{
				sector1=b/grup2;
				if(b%grup2==0)sector1--;
			}
			if(sector==sector1)cout<<"YES"<<'\n';
			else cout<<"NO"<<'\n';
		}
		return 0;
}