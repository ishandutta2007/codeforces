// : caigou
// : 2022-03-10 14:33
 
#pragma GCC optimize(2)
#include<bits/stdc++.h>
#define mp make_pair
#define mt make_tuple
#define pb push_back
#define pc putchar
#define chkmx(a,b) (a)=max((a),(b))
#define chkmn(a,b) (a)=min((a),(b))
#define fi first
#define se second
using namespace std;
template<class T>
void read(T&x){x=0;char c=getchar();bool f=0;for(;!isdigit(c);c=getchar())f^=c=='-';for(;isdigit(c);c=getchar())x=x*10+c-'0';if(f)x=-x;}
template<class T,class ...ARK>void read(T&x,ARK&...ark){read(x);read(ark...);}
template<class T>void write(T x){if(x<0)pc('-'),x=-x;if(x>=10)write(x/10);pc(x%10+'0');}
template<class T,class ...ARK>void write(T x,ARK...ark){write(x);pc(' ');write(ark...);}
template<class ...ARK>void writeln(ARK...ark){write(ark...);pc('\n');}
typedef long long ll;
const int mod=998244353;
struct mint{
	int x;mint(int o=0){x=o;}mint&operator+=(mint a){return(x+=a.x)%=mod,*this;}mint&operator-=(mint a){return(x+=mod-a.x)%=mod,*this;}
	mint&operator*=(mint a){return(x=1ll*x*a.x%mod),*this;}mint&operator^=( int b){mint a=*this;x=1;while(b)(b&1)&&(*this*=a,1),a*=a,b>>=1;return*this;}
	mint&operator/=(mint a){return*this*=(a^=mod-2);}friend mint operator+(mint a,mint b){return a+=b;}friend mint operator-(mint a,mint b){return a-=b;}
	friend mint operator*(mint a,mint b){return a*=b;}friend mint operator/(mint a,mint b){return a/=b;}friend mint operator^(mint a, int b){return a^=b;}
};
#define lowbit(x) ((x)&-(x))
#define mid ((l+r)>>1)
#define lc (x<<1)
#define rc (x<<1|1)
const int N=4e5+100;
namespace SAM{
	int ch[N][26],len[N],fa[N],cnt[N],sz=1,lst=1;
	int add(int c){
		int cur=++sz,p=lst;
		cnt[cur]=1;
		len[cur]=len[lst]+1;
		for(;p&&!ch[p][c];p=fa[p])
			ch[p][c]=cur;
		if(!p)fa[cur]=1;
		else{
			int q=ch[p][c];
			if(len[q]==len[p]+1)fa[cur]=q;
			else{
				int nw=++sz;
				len[nw]=len[p]+1;
				fa[nw]=fa[q];
				memcpy(ch[nw],ch[q],sizeof ch[nw]);
				for(;ch[p][c]==q;p=fa[p])
					ch[p][c]=nw;
				fa[q]=fa[cur]=nw;
			}
		}
		lst=cur;return lst;
	}
}
using SAM::fa;
using SAM::len;
#define cnt SAM::sz
int n,m;char s[N];
int pos[N],rev[N];
vector<int>e[N];
int l[N],r[N];
int dep[N],sz[N];
int qid[N],qmn[N],qmx[N];//
vector<int>qry[N];//
int qcnt;
int son[N];//
int cmn(int&x,int y){if(!x)x=y;else if(y)chkmn(x,y);return y;}
int cmx(int&x,int y){if(!x)x=y;else if(y)chkmx(x,y);return y;}
ll ot[N],ans[N];
//ot ansrelabel
void dfs1(int u){
	sz[u]=1;
	for(auto id:qry[u])
		cmn(qmn[u],cmx(qmx[u],qid[id]=++qcnt));
	for(auto v:e[u])
		dep[v]=dep[u]+1,dfs1(v),cmn(qmn[u],qmn[v]),cmx(qmx[u],qmx[v]),sz[u]+=sz[v];
}
void dfs2(int u){
	pair<int,int>mx=mp(0,0);
	for(auto v:e[u])chkmx(mx,mp(sz[v],v));
	son[u]=mx.se;
	for(auto v:e[u])dfs2(v);
}
struct BIT{
	ll tree[N];
	void clear(){memset(tree,0,sizeof tree);}
	void add(int x,int y){for(;x<=cnt;x+=lowbit(x))tree[x]+=y;}
	ll qry(int x){ll res=0;for(;x;x-=lowbit(x))res+=tree[x];return res;}
	ll qry(int l,int r){if(l>r)return 0;return qry(r)-qry(l-1);}
}T1,T2;
void ins(int u,int op){
	if(pos[u])T1.add(pos[u],op),T2.add(pos[u],op*pos[u]);
	for(auto v:e[u])ins(v,op);
}
namespace cdq{
	int up[N],dw[N];
	struct SCGHS{
		ll tree[N];
		void add(int x,int y){for(;x<=cnt;x=up[x])tree[x]+=y;}
		ll qry(int x){ll res=0;for(;x;x=dw[x])res+=tree[x];return res;}
	}T1,T2;
	struct node{
		int op,a,b,c,d,e;
		// op = 0 id=a l=b r=c
		// op = 1 id<=a l<=b r>=c  d+e l
		void print(){
			if(op==0)printf("Q id=%d l=%d r=%d\n",a,b,c);
			else printf("M id<=%d l<=%d r>=%d  %d%c%d l\n",a,b,c,d,(e>=0?'+':'-'),abs(e));
		}
	};
	vector<node>q;
	void addq(int op,int a,int b,int c,int d,int e){if(b>0)q.pb((node){op,a,b,c,d,e});/*q.back().print();*/}
	void cdq(int l,int r){
		//writeln(l,r);
		if(l==r)return;
		cdq(l,mid);cdq(mid+1,r);
		int i,j;
		ll T11=0,T21=0;
		for(i=l,j=mid;i<=mid;i++)if(!q[i].op){
			while(j+1<=r&&q[j+1].c<=q[i].c){
				j++;
				if(q[j].op){
					T11+=q[j].d,T1.add(q[j].b+1,-q[j].d),
					T21+=q[j].e,T2.add(q[j].b+1,-q[j].e);
				}
			}
			ans[q[i].a]+=T11+T1.qry(q[i].b),
			ans[q[i].a]+=(T21+T2.qry(q[i].b))*q[i].b;
		}
		while(j>mid){
			if(q[j].op)
				T1.add(q[j].b+1,q[j].d),
				T2.add(q[j].b+1,q[j].e);
			j--;
		}
		//sort(&q[l],&q[r]+1,[&](node&a,node&b){
		//	return a.c<b.c;
		//});
		inplace_merge(&q[l],&q[mid]+1,&q[r]+1,[&](node a,node b)->bool{return a.c<b.c;});
	}
	void work(){
		int D=18;
		for(int i=1;i<=cnt;i++){
			if(i%D==0)up[i]=up[i/D]*D,dw[i]=dw[i/D]*D;
			else up[i]=(i/D+1)*D,dw[i]=i-1;
		}
		for(int i=1;i<=m;i++)addq(0,qid[i],l[i],r[i],0,0);
		sort(q.begin(),q.end(),[&](node&a,node&b){
			if(a.a==b.a)return a.op<b.op;
			return a.a<b.a;	
		});
		//for(auto x:q)x.print();
		cdq(0,(int)q.size()-1);
	}
}
void deal(int u,int t,pair<int,int>tar){
	for(auto id:qry[u]){
		ot[id]+=T1.qry(l[id]+len[t],r[id])*len[t];
		ot[id]-=T1.qry(l[id],min(l[id]+len[t]-1,r[id]))*(l[id]-1);
		ot[id]+=T2.qry(l[id],min(l[id]+len[t]-1,r[id]));
	}
	//(x,t) 
	if(pos[u]&&tar.fi){
		//cdq::addq(1,tar.se,pos[u]-len[t],pos[u],len[t],0);
		//cdq::addq(1,tar.fi-1,pos[u]-len[t],pos[u],-len[t],0);
		
		cdq::addq(1,tar.se,pos[u],pos[u],pos[u]+1,-1);
		cdq::addq(1,tar.se,pos[u]-len[t],pos[u],-pos[u]-1+len[t],1);
		cdq::addq(1,tar.fi-1,pos[u],pos[u],-pos[u]-1,1);
		cdq::addq(1,tar.fi-1,pos[u]-len[t],pos[u],pos[u]+1-len[t],-1);
		//for(int id=tar.fi;id<=tar.se;id++){
			//if(l[id]<=pos[u]-len[t]&&r[id]>=pos[u])ans[id]+=len[t];
			//if(pos[u]-len[t]<l[id]&&l[id]<=pos[u]&&r[id]>=pos[u])ans[id]+=pos[u]-l[id]+1;
		//}
	}
}
void calc(int u,int t,pair<int,int>tar){
	deal(u,t,tar);
	for(auto v:e[u])calc(v,t,tar);
}
void dfs3(int u){
	for(auto v:e[u])if(v!=son[u])
		dfs3(v),ins(v,-1);
	if(son[u])dfs3(son[u]);
	if(pos[u])T1.add(pos[u],1),T2.add(pos[u],pos[u]);
	for(auto v:e[u])if(v!=son[u])ins(v,1);
	for(auto v:e[u])if(v!=son[u])ins(v,-1),calc(v,u,mp(qmn[son[u]],qmx[son[u]])),ins(v,1);
	deal(u,u,mp(qmn[son[u]],qmx[son[u]]));
}
signed main(){
	//freopen("1.in","r",stdin);
	//freopen("1.out","w",stdout);
	scanf("%s",s+1);n=strlen(s+1);reverse(s+1,s+1+n);
	for(int i=1;i<=n;i++)pos[rev[i]=SAM::add(s[i]-'a')]=i;
	for(int i=2;i<=cnt;i++)e[fa[i]].pb(i);
	read(m);
	for(int i=1;i<=m;i++)
		read(l[i],r[i]),l[i]=n-l[i]+1,r[i]=n-r[i]+1,
		swap(l[i],r[i]),qry[rev[r[i]]].pb(i);
	dfs1(1);
	dfs2(1);
	dfs3(1);
	cdq::work();
	for(int i=1;i<=m;i++)writeln(ot[i]+ans[qid[i]]);
}