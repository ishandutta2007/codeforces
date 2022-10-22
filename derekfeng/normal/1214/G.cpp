#include<bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native")
using namespace std;
typedef pair<int,int> pii;
#define fi first
#define se second
set<pii>arr,ans;
bitset<2004>pre[2004],f[2004];
int n,m,q,sz[2004];
bool ok(int a,int b){
	if(a<0||b<0)return 0;
	bitset<2004>F=f[a]&f[b];
	return (F^f[a]).count()>0;
}
void upd(int i,int l,int r){
	f[i]^=pre[l-1];
	f[i]^=pre[r];
	sz[i]=f[i].count();
}
void ins(int c){
	auto it=arr.lower_bound({sz[c],c});
	int pre=-1,nxt=-1;
	if(it!=arr.end())nxt=(*it).se;
	if(it!=arr.begin())--it,pre=(*it).se;
	if(ok(pre,nxt))ans.erase({pre,nxt});
	if(ok(pre,c))ans.insert({pre,c});
	if(ok(c,nxt))ans.insert({c,nxt});
	arr.insert({sz[c],c});
}
void del(int c){
	auto it=arr.lower_bound({sz[c],c});
	auto it1=it;++it1;
	int pre=-1,nxt=-1;
	if(it1!=arr.end())nxt=(*it1).se;
	if(it!=arr.begin())--it,pre=(*it).se;
	if(ok(pre,c))ans.erase({pre,c});
	if(ok(c,nxt))ans.erase({c,nxt});
	if(ok(pre,nxt))ans.insert({pre,nxt});
	arr.erase({sz[c],c});
}
void qry(){
	if(ans.empty())puts("-1");
	else{
		auto it=ans.begin();
		int l=(*it).fi,r=(*it).se;
		if(l>r)swap(l,r);
		bitset<2004>F=f[l]&f[r];
		bitset<2004>fa=f[l]^F,fb=f[r]^F;
		int L=fa._Find_first(),R=fb._Find_first();
		if(L>R)swap(L,R);
		printf("%d %d %d %d\n",l,L,r,R);
	}
}
void init(){
	for(int i=1;i<=m;i++)pre[i]=pre[i-1],pre[i][i]=1;
	for(int i=1;i<=n;i++)ins(i);
}
int main(){
	scanf("%d%d%d",&n,&m,&q);
	init();
	while(q--){
		int c,l,r;scanf("%d%d%d",&c,&l,&r);
		del(c);
		upd(c,l,r);
		ins(c);
		qry();
	}
}