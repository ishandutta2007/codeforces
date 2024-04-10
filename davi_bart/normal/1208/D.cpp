#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
vector<ll> p;
ll sol[300000];
vector<ll> fenwick(1000000,0);
bool vis[300000];
ll prossimo[300000];
ll prox(ll pos){
	if(vis[pos]==0){
		vis[pos]=1;
		return pos;
	}
	prossimo[pos]=prox(prossimo[pos]);
}
ll presi(ll pos){
	ll tot=0;
	for(ll i=pos;i>0;i-=(i&-i)){
		tot+=fenwick[i];
	}
	return tot;
}
void upd(ll pos){
	for(ll i=pos;i<1000000;i+=(i&-i)){
		fenwick[i]+=pos;
	}
}
int main(){
		ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
		ll N;
		cin>>N;
		for(ll i=0;i<N;i++){
			ll a;
			cin>>a;
			p.push_back(a);
			prossimo[i]=i+1;
		}
		prossimo[N]=N+1;
		for(ll i=p.size()-1;i>=0;i--){
			ll sx=1,dx=N+2;
			while(sx<dx-1){
				ll d=(sx+dx)/2;
				if(d*(d-1)/2-presi(d-1)>p[i])dx=d;
				else sx=d;
			}
			ll pos=prox(sx);
			upd(pos);
			sol[i]=pos;
			vis[pos]=1;
		}
		for(ll i=0;i<N;i++)cout<<sol[i]<<" ";
		return 0;
}