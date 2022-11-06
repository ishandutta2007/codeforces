#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<bits/stdc++.h>
using namespace std;
#pragma GCC optimize("O2")
#define eb emplace_back
#define pb push_back
#define pw(x) ((1LL)<<(x))
#define buli(x) (__builtin_popcountll(x))
typedef long long ll;
typedef double db;
const int inf=1e9;
const int md=1e9+7;
const int maxn=1000000+10;
const db eps=1e-6;
inline void rd(long long &x){
	int sign=1;char c;while(((c=getchar())<'0'||c>'9')&&c!='-');c=='-'?(sign=-1,x=0):(x=c-'0');
	while((c=getchar())>='0'&&c<='9')x=x*10+c-'0';x*=sign;
}
inline void rd(double&x){scanf("%lf",&x);}
inline void rd(int &x){ll y=0;rd(y);x=y;}
inline void upd(int &a,int b){a+=b;if(a>=md)a-=md;}
int n,m,T,x,y,z,nk,nq;

int s,t,ds,dt;
vector<tuple<int,int> >e,ans;
vector<int> es,et;
int vs[maxn],vt[maxn],id[maxn],f[maxn];
int ms,mt;
bool judge(int x,int y){
	int k1=0,k2=0;

	if(x==s || y==s) k1=1;
	if(x==t || y==t) k2=1;
	if(!k1 && !k2) return false;
	if(k1 && k2) return false;

	if(k1){
		if(x!=s)swap(x,y);
		if(id[y]==2) return false;
	}
	if(k2){
		if(x!=t)swap(x,y);
		if(id[y]==1) return false;
	}
	return true;
}
int find(int x){
	if(x==f[x]) return x;
	return f[x]=find(f[x]);
}
int main(){
	#ifdef GJY
		freopen("t.in","r",stdin);
	#endif
	rd(n);rd(m);
	for(int i=1;i<=n;i++) f[i]=i;
	for(int i=1;i<=m;i++){
		rd(x);rd(y);
		if(x>y)swap(x,y);
		e.eb(x,y);
	}
	rd(s);rd(t);rd(ds);rd(dt);
	for(int i=0;i<e.size();i++){
		int x,y;
		tie(x,y)=e[i];
		if(x==s && y==t) continue;
		if(y==s && x==t) continue;
		if(x==s || y==s){
			if(x==s) es.pb(y);
			else es.pb(x);
		}else if(x==t || y==t){
			if(x==t) et.pb(y);
			else et.pb(x);
		}else{
			int fx=find(x);
			int fy=find(y);
			if(fx!=fy){
				f[fx]=fy;
				ans.eb(x,y);
			}
			
		}
	}
	for(int i=0;i<es.size();i++){
		int x=find(es[i]);
		if(!vs[x]){
			vs[x]=1;
		}
	}
	for(int i=0;i<et.size();i++){
		int x=find(et[i]);
		if(!vt[x]){
			vt[x]=1;
		}
	}
	vector<int> g;
	for(int i=1;i<=n;i++) if(find(i)==i && i!=s & i!=t)  g.pb(i);
	for(int i=0;i<g.size();i++){
		int x=g[i];
		if(vs[x] && !vt[x]) id[x]=1,ds--;
		if(vt[x] && !vs[x]) id[x]=2,dt--;
	}
	
	for(int i=0;i<g.size();i++){
		int x=g[i];
		if(id[x]>0) continue;
		if(ds>dt) ds--,id[x]=1;
		else dt--,id[x]=2;
	}
	
	if(ds<0 || dt<0){
		puts("No");
		return 0;
	}
	//	for(int i=1;i<=n;i++) printf("%d %d\n",id[i],i);
	for(int i=1;i<=n;i++) id[i]=id[find(i)];
//	for(int i=1;i<=n;i++) printf("%d %d\n",id[i],i);
	for(int i=0;i<e.size();i++){
		int x,y;tie(x,y)=e[i];
		if(!judge(x,y)) continue;
		int fx=find(x),fy=find(y);	
		if(fx!=fy){
			f[fx]=fy;
			ans.eb(x,y);
		}
	}

	if(ans.size()<n-1){
		for(int i=0;i<e.size();i++){
			int x,y;tie(x,y)=e[i];
			int k1=1,k2=1;
			if(x!=s && y!=s)k1=0;
			if(x!=t && y!=t)k2=0;
			if(k1==0 && k2==0) continue;
			if(x==t || y==t) if(dt==0) continue;
			if(x==s || y==s) if(ds==0) continue;	
			int fx=find(x),fy=find(y);
		
			if(fx!=fy){
				f[fx]=fy;
				ans.eb(x,y);
			}
			if(ans.size()==n-1) break;
		}
	}
	if(ans.size()<n-1){
		puts("No");
		return 0;
	}
	puts("Yes");	
	for(int i=0;i<ans.size();i++){
		int x,y;tie(x,y)=ans[i];
		printf("%d %d\n",x,y);
	}
			
}