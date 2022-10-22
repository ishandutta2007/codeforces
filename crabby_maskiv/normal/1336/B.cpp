#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=100005;
const ll inf=0x3f3f3f3f3f3f3f3fll;
int n,m;
int n1,n2,n3;
set<ll> x,y,z;
int main(){
	int i,j;
	int T;cin>>T;
	while(T--){
		cin>>n1>>n2>>n3;
		ll w;
		x.clear();y.clear();z.clear();
		x.insert(inf);x.insert(-inf);
		y.insert(inf);y.insert(-inf);
		z.insert(inf);z.insert(-inf);
		for(i=1;i<=n1;i++){
			cin>>w;x.insert(w);
		}
		for(i=1;i<=n2;i++){
			cin>>w;y.insert(w);
		}
		for(i=1;i<=n3;i++){
			cin>>w;z.insert(w);
		}
		ll ans=inf;
		for(auto k:x){
			auto it1=y.upper_bound(k),it2=z.lower_bound(k);it1--;
			if((*it1)==-inf||(*it2)==inf) continue;
			ans=min(ans,((*it2)-(*it1))*((*it2)-(*it1))+((*it2)-k)*((*it2)-k)+((*it1)-k)*((*it1)-k));
		}
		for(auto k:x){
			auto it1=z.upper_bound(k),it2=y.lower_bound(k);it1--;
			if((*it1)==-inf||(*it2)==inf) continue;
			ans=min(ans,((*it2)-(*it1))*((*it2)-(*it1))+((*it2)-k)*((*it2)-k)+((*it1)-k)*((*it1)-k));
		}
		for(auto k:y){
			auto it1=x.upper_bound(k),it2=z.lower_bound(k);it1--;
			if((*it1)==-inf||(*it2)==inf) continue;
			ans=min(ans,((*it2)-(*it1))*((*it2)-(*it1))+((*it2)-k)*((*it2)-k)+((*it1)-k)*((*it1)-k));
		}
		for(auto k:y){
			auto it1=z.upper_bound(k),it2=x.lower_bound(k);it1--;
			if((*it1)==-inf||(*it2)==inf) continue;
			ans=min(ans,((*it2)-(*it1))*((*it2)-(*it1))+((*it2)-k)*((*it2)-k)+((*it1)-k)*((*it1)-k));
		}
		for(auto k:z){
			auto it1=x.upper_bound(k),it2=y.lower_bound(k);it1--;
			if((*it1)==-inf||(*it2)==inf) continue;
			ans=min(ans,((*it2)-(*it1))*((*it2)-(*it1))+((*it2)-k)*((*it2)-k)+((*it1)-k)*((*it1)-k));
		}
		for(auto k:z){
			auto it1=y.upper_bound(k),it2=x.lower_bound(k);it1--;
			if((*it1)==-inf||(*it2)==inf) continue;
			ans=min(ans,((*it2)-(*it1))*((*it2)-(*it1))+((*it2)-k)*((*it2)-k)+((*it1)-k)*((*it1)-k));
		}
		cout<<ans<<endl;
	}
	return 0;
}