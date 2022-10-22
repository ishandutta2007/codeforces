#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
		ios_base::sync_with_stdio(0);
		cin.tie(0);cout.tie(0);
		ll T;
		cin>>T;
		while(T--){
			ll N,M,K;
			cin>>N>>M>>K;
			vector<ll> h;
			for(ll i=0;i<N;i++){
				ll a;
				cin>>a;
				h.push_back(a);
			}
			for(ll i=0;i<N;i++){
				if(i==N-1){
					cout<<"YES"<<'\n';
					break;
				}
				int o;
				if(h[i+1]<K)o=h[i+1];
				else o=K;
        M+=h[i]-(h[i+1]-o);
				if(M>=0)continue;
				cout<<"NO"<<'\n';
				break;
			}
		}
		return 0;
}