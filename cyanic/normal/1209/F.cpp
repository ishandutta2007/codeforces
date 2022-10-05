#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define per(i,a,b) for(int i=(a);i>=(b);i--)
#define REP(i,n) for(int i=(0);i<(n);i++)
#define fi first
#define se second
#define pb push_back
#define mp make_pair
using namespace std;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef long long ll;
 
template<class T> inline void read(T &x){
	int f=0;x=0;char ch=getchar();
	for(;!isdigit(ch);ch=getchar())f|=(ch=='-');
	for(;isdigit(ch);ch=getchar())x=x*10+ch-'0';
	if(f)x=-x;
}
 
const int mod[2]={1000000007,19260817};
const int bas[2]={10,2333};
const int N=100005,M=N*200;
int lc[M],rc[M],T[M][2],po[N*5][2],len[M],rt[N];
int vis[N],n,m,a,b,mx,sz,ans;
vector<pii> e[N];
int flag;
 
inline int ask(int u,int l,int r,int x){
	for(int mid;l<r;){
		mid=(l+r)>>1;
		if(x>mid)l=mid+1,u=rc[u];
		else r=mid,u=lc[u];
	}
	return T[u][0];
}
inline int qry(int u,int v,int l,int r){
	if(T[u][0]==T[v][0]&&T[u][1]==T[v][1])return -1;
	for(int mid;l<r;){
		mid=(l+r)>>1;
		if(T[lc[u]][0]==T[lc[v]][0]&&T[lc[u]][1]==T[lc[v]][1])
			l=mid+1,u=rc[u],v=rc[v];
		else
			r=mid,u=lc[u],v=lc[v];
	}
	return l;
}
void getval(int o,int l,int r,int x,int y){
	if(l==x&&y==r){
		//printf("@ %d %d  %d\n",l,r,T[o][0]);
		ans=((ll)ans*po[r-l+1][0]+T[o][0])%mod[0];
		return;
	}
	int mid=(l+r)>>1;
	if(x<=mid)getval(lc[o],l,mid,x,min(y,mid));
	if(mid<y)getval(rc[o],mid+1,r,max(mid+1,x),y);
}
void ins(int &o,int l,int r,int x,int y){
	lc[++sz]=lc[o],rc[sz]=rc[o];
	T[sz][0]=T[o][0],T[sz][1]=T[o][1],o=sz;
	if(l==r){
		T[o][0]=T[o][1]=y;
		return;
	}
	int mid=(l+r)>>1;
	if(x<=mid)ins(lc[o],l,mid,x,y);
	else ins(rc[o],mid+1,r,x,y);
	REP(t,2)T[o][t]=((ll)T[lc[o]][t]*po[r-mid][t]
					+T[rc[o]][t])%mod[t];
}
int comp(int a,int b){
	int p=qry(a,b,1,mx);
	//if(flag)printf("# %d  %d %d\n",p,ask(a,1,mx,p),ask(b,1,mx,p));
	return p==-1||ask(a,1,mx,p)<ask(b,1,mx,p);
}
 
struct cmp{
	inline int operator () (pii a,pii b){
		return len[a.fi]!=len[b.fi]?len[a.fi]>len[b.fi]:!comp(a.fi,b.fi);
	}
};
priority_queue<pii,vector<pii>,cmp> Q;
 
int main(){
	read(n),read(m),mx=n*5+5;
	po[0][0]=po[0][1]=1;
	rep(i,1,mx)REP(t,2)
		po[i][t]=(ll)po[i-1][t]*bas[t]%mod[t];
	rep(i,1,m){
		read(a),read(b);
		e[a].pb(mp(b,i));
		e[b].pb(mp(a,i));
	}
	rt[1]=1;
	rep(i,2,n){
		len[i]=mx;
		rt[i]=i;
	}
	sz=n;
	Q.push(mp(rt[1],1));
	while(!Q.empty()){
		int x=Q.top().se;Q.pop();
		if(vis[x])continue;vis[x]=1;
		//printf("# %d %d\n",x,len[rt[x]]);
		for(auto t:e[x]){
			int y=t.fi,num=t.se;
			int nw=rt[x],L=0,tmp=num;
			while(tmp)L++,tmp/=10;
			int p=len[rt[x]]+L;
			if(p>len[rt[y]])continue;
			rep(i,1,L){
				ins(nw,1,mx,p,num%10);
				num/=10,p--;
			}
			len[nw]=len[rt[x]]+L;
			/*
			printf("@ %d %d\n",x,y);
			if(x==6&&y==7)flag=1;
			else flag=0;
			printf("%d %d\n",len[nw],len[rt[y]]);
			*/
			if(len[nw]<len[rt[y]]||len[nw]==len[rt[y]]&&comp(nw,rt[y])){
				rt[y]=nw;
				Q.push(mp(rt[y],y));
			}
		}
	}
	rep(i,2,n){
		ans=0;
		getval(rt[i],1,mx,1,len[rt[i]]);
		printf("%d\n",ans);
	}
	return 0;
}