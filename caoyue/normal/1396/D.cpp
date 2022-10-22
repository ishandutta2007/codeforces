#include<iostream>
#include<cstring>
#include<cassert>
#include<cmath>
#include<map>
#include<set>
#include<queue>
#include<stack>
#include<cstdio>
#include<vector>
#include<time.h>
#include<algorithm>
using namespace std;
#define REP(i,x,y) for(int i=x;i<=y;i++)
#define rep(i,n) REP(i,1,n)
#define rep0(i,n) REP(i,0,n-1)
#define repG(i,x) for(int i=pos[x];~i;i=e[i].next)
#define ll long long
#define db double
const int N=2e3+7;
const ll mod=1e9+7;
int n,k,L,c1=0,c2=0;
int X[N],Y[N],c[N],w1[N],w2[N];
map<int,int>S1,S2;
set<int>g[N];
vector<int>q[N];
struct Tree{ll l,r,mx,sm,cl,lz;}tr[N*4];
bool zz[N];
void build(ll l,ll r,ll p){
	tr[p]=(Tree){l,r,0,0,0,0};
	if(l==r){
		tr[p].cl=w2[r+1]-w2[r];
		tr[p].sm=tr[p].cl*(ll)w2[r+1];
		tr[p].mx=w2[r+1];
		return;
	}
	ll mid=(l+r)>>1;
	build(l,mid,p*2);
	build(mid+1,r,p*2+1);
	tr[p].mx=max(tr[p*2].mx,tr[p*2+1].mx);
	tr[p].sm=tr[p*2].sm+tr[p*2+1].sm;
	tr[p].cl=tr[p*2].cl+tr[p*2+1].cl;
}
ll real(ll x){return (tr[x].lz)?tr[x].cl*tr[x].lz:tr[x].sm;}
void upd(ll p){
	tr[p].sm=real(p*2)+real(p*2+1);
	tr[p].mx=max(max(tr[p*2].mx,tr[p*2].lz),max(tr[p*2+1].mx,tr[p*2+1].lz));
}
void lzd(ll p){
	if(!tr[p].lz)return;
	tr[p].sm=real(p);
	tr[p].mx=tr[p].lz;
	tr[p*2].lz=tr[p].lz;
	tr[p*2+1].lz=tr[p].lz;
	tr[p].lz=0;
}
ll cv(ll p,ll v){
	if(tr[p].l==tr[p].r)return tr[p].l;
	lzd(p);
	return (max(tr[p*2].mx,tr[p*2].lz)<v)?cv(p*2+1,v):cv(p*2,v);
}
void Maxs(ll L,ll R,ll v,ll p){
	ll l=tr[p].l,r=tr[p].r;
	if(L<=l&&R>=r){
		tr[p].lz=v;
		return;
	}
	lzd(p);
	ll mid=(l+r)>>1;
	if(L<=mid)Maxs(L,R,v,p*2);
	if(R>mid)Maxs(L,R,v,p*2+1);
	upd(p);
}
void Max(ll L,ll R,ll v,ll p){
	ll t=cv(1,v);
	R=min(R,t-1);
	if(L<=R)Maxs(L,R,v,1);
}
ll check(ll L,ll R,ll p){
	ll l=tr[p].l,r=tr[p].r;
	if(L<=l&&R>=r)return real(p);
	ll mid=(l+r)>>1,ans=0;
	lzd(p);
	if(L<=mid)ans+=check(L,R,p*2);
	if(R>mid)ans+=check(L,R,p*2+1);
	return ans;
}
int main(){
	scanf("%d%d%d",&n,&k,&L);
	rep(i,n){
		scanf("%d%d%d",&X[i],&Y[i],&c[i]);
		S1[X[i]]=1;
		S2[Y[i]]=1;
	}
	for(map<int,int>::iterator s=S1.begin();s!=S1.end();s++){
		S1[s->first]=++c1;
		w1[c1]=s->first;
	}
	for(map<int,int>::iterator s=S2.begin();s!=S2.end();s++){
		S2[s->first]=++c2;
		w2[c2]=s->first;
	}
	rep(i,n){
		X[i]=S1[X[i]];
		Y[i]=S2[Y[i]];
		q[X[i]].push_back(i);
	}
	w1[0]=-1;
	w1[c1+1]=L;
	w2[0]=-1;
	w2[c2+1]=L;
	ll ans=0;
	rep0(i,c1+1){
		memset(zz,0,sizeof(zz));
		rep(j,k)g[j].clear();
		REP(j,i+1,c1){
			for(int o=0;o<q[j].size();o++){
				int id=q[j][o];
				if(g[c[id]].count(Y[id]))zz[id]=1;
				else g[c[id]].insert(Y[id]);
			}
		}
		bool fl=0;
		build(0,c2,1);
		rep(j,k){
			if(g[j].empty()){
				fl=1;
				break;
			}
			set<int>::iterator s=g[j].begin();
			Max(0,(*s)-1,w2[(*s)],1);
			set<int>::iterator ls=s;
			for(s++;s!=g[j].end();ls=s,s++)Max((*ls),(*s)-1,w2[(*s)],1);
			Max((*ls),c2,L,1);
		}
		if(fl)break;
		for(int j=c1;j>i;j--){
			ans=(ans+((ll)(w1[i+1]-w1[i])*(ll)(w1[j+1]-w1[j]))%mod*(((ll)L*(L+1)-check(0,c2,1))%mod)%mod)%mod;
			bool fg=0;
			for(int o=0;o<q[j].size();o++){
				int id=q[j][o];
				if(zz[q[j][o]])continue;
				g[c[id]].erase(Y[id]);
				set<int>::iterator t=g[c[id]].upper_bound(Y[id]);
				if(t!=g[c[id]].end()){
					if(t==g[c[id]].begin())Max(0,(*t)-1,w2[(*t)],1);
					else{
						int p=(*t);
						t--;
						Max((*t),p-1,w2[p],1);
					}
				}
				else{
					if(t==g[c[id]].begin()){
						fg=1;
						break;
					}
					else{
						t--;
						Max((*t),c2,L,1);
					}
				}
			}
			if(fg)break;
		}
	}
	cout<<ans<<endl;
	return 0;
}