#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,int> pli;
#define mp make_pair 
const int maxn=200033;
ll n,m,a[maxn],x[maxn],cnt[maxn],pos[maxn],b[maxn];
set<pli>c,d,e;
void erasing(int id){
	if(c.find(mp(x[id],id))==c.end())return ;
	while(1){
		auto it=c.lower_bound(mp(x[id]+1,-1));
		if(it==c.end())break;
		int p=it->second;
		if(x[id]+a[id]<a[p]+x[p])break;
		c.erase(it);
		d.erase(mp(x[p]+a[p],p)) ;
	}
}
void read(){
	cin>>n>>m;
	for(int i=0;i<n;i++){
		scanf("%lld%lld",&x[i],&a[i]);
		c.insert(mp(x[i],i));
		d.insert(mp(x[i]+a[i],i));
	}
	for(int i=0;i<n;i++)erasing(i);
}
void eating(int id){
	while(1){
		auto it=e.lower_bound(mp(x[id]+a[id]+1,-1));
		if(it==e.begin())break;
		it--;
		if(it->first<x[id])break;
		a[id]+=b[it->second];
		cnt[id]++;
		e.erase(it);
	}
}
int main(){
	read();
	for(int i=0;i<m;i++){
		scanf("%lld%lld",&pos[i],&b[i]);
		auto it=d.lower_bound(mp(pos[i],-1));
		if(it==d.end()||x[it->second]>pos[i]){
			e.insert(mp(pos[i],i));
			continue;
		}
		int id=it->second;
		d.erase(mp(x[id]+a[id],id));
		a[id]+=b[i];
		cnt[id]++;
		eating(id);
		d.insert(mp(x[id]+a[id],id));
		erasing(id);
	}
	for(int i=0;i<n;i++)
		cout<<cnt[i]<<' '<<a[i]<<endl;
}