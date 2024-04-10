#pragma GCC optimize("Ofast")
#include<bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
#define SZ(x) ((int)x.size())
#define L(i,u) for (register int i=head[u]; i; i=nxt[i])
#define rep(i,a,b) for (register int i=(a); i<=(b); i++)
#define per(i,a,b) for (register int i=(a); i>=(b); i--)
using namespace std;
typedef long long ll;
typedef unsigned int ui;
typedef pair<int,int> Pii;
typedef vector<int> Vi;
inline void read(int &x) {
	x=0; char c=getchar(); int f=1;
	while (!isdigit(c)) {if (c=='-') f=-1; c=getchar();}
	while (isdigit(c)) {x=x*10+c-'0'; c=getchar();} x*=f;
}
const int N = 303000, S = 480, inf = 0x3f3f3f3f;
int n,q,bg[N],ed[N],a[N],bel[N],len;bool gg;
Vi mrk[N];int qaq[N],pos[N];
inline void init(){
	rep(i,0,len+1)bel[i]=0;
	gg=0;rep(i,0,n+1)mrk[i].clear();len=0;
}
//inline void upd(Pii &u, int x){u=Pii((1LL*u.fi*b1+x)%mo1,(1LL*u.se*b2+x)%mo2);}
inline bool solve(int p){
	int mx=0,now=inf;bool gg=0;
	per(i,ed[p],bg[p]){
		now=!pos[a[i]]?inf:(pos[a[i]]+1==pos[a[i+1]]?now:pos[a[i]]);
		mx=max(mx,pos[a[i]]);gg|=mx>now;
	}
	return gg;
}
int main() {
	int T;read(T);
	while(T--){
		read(n);read(q);init();
		rep(i,1,q){
			int l,x;read(l);bg[i]=len+1;
			rep(j,1,l)read(x),a[++len]=x,bel[len]=i;ed[i]=len;
		}
		rep(i,1,len)if(ed[i]-bg[i]<=S)mrk[a[i]].pb(i);
		rep(i,1,n)if(!gg){
			per(j,SZ(mrk[i])-1,0){
				int s=mrk[i][j];
				for(register int k=s+1;k-s<=S&&bel[k]==bel[s];k++){
					gg|=qaq[a[k]]&&qaq[a[k]]!=a[k-1];qaq[a[k]]=a[k-1];
				}
			}
			per(j,SZ(mrk[i])-1,0){
				int s=mrk[i][j];
				for(register int k=s+1;k-s<=S&&bel[k]==bel[s];k++)qaq[a[k]]=0;
			}
		}
		rep(i,1,q)if(ed[i]-bg[i]>=S&&!gg){
			rep(j,bg[i],ed[i])pos[a[j]]=j;
			rep(j,1,q)if(i!=j)gg|=solve(j);
			rep(j,bg[i],ed[i])pos[a[j]]=0;
		}
		if(gg)puts("Human");else puts("Robot");
	}
	return 0;
}