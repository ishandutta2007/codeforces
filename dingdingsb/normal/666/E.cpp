// Problem: CF666E Forensic Examination
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/CF666E
// Memory Limit: 750 MB
// Time Limit: 6000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include<bits/stdc++.h>
#define pb push_back
#define pc putchar
#define mp make_pair
#define fi first
#define se second
#define chkmx(a,b) ((a)=max((a),(b)))
#define chkmn(a,b) ((a)=min((a),(b)))
using namespace std;
template<typename T>
inline void read(T &x){x=0;char c=getchar();bool f=false;for(;!isdigit(c);c=getchar())f|=c=='-';for(;isdigit(c);c=getchar())x=x*10+c-'0';if(f)x=-x;}
template<typename T ,typename ...Arg>inline void read(T &x,Arg &...args){read(x);read(args...);}
template<typename T>inline void write(T x){if(x<0)putchar('-'),x=-x;if(x>=10)write(x/10);putchar(x%10+'0');}
//#define int long long
#define mid ((l+r)>>1)
typedef long long ll;
const int N=5e5+100,M=20;
int n;char s[N],t[N];int pos[N],lcs[N];
int m,q;
struct SGT{
	struct node{
		int lc,rc;
		pair<int,int>mx;
	}t[N<<5];int sz;
	SGT(){t[0].mx=mp(0,-0x3f3f3f3f);}
	void pushup(int x){t[x].mx=max(t[t[x].lc].mx,t[t[x].rc].mx);}
	int build(int l,int r,int tar){
		int x=++sz;
		if(l==r){
			t[x]={0,0,mp(1,-l)};
			return x;
		}
		if(tar<=mid)t[x].lc=build(l,mid,tar);
		else t[x].rc=build(mid+1,r,tar);
		pushup(x);return x;
	}
	int merge(int p,int q,int l,int r){
		if(!p||!q)return p|q;
		if(l==r){
			t[p].mx.fi+=t[q].mx.fi;
			return p;
		}
		t[p].lc=merge(t[p].lc,t[q].lc,l,mid);
		t[p].rc=merge(t[p].rc,t[q].rc,mid+1,r);
		pushup(p);return p;
	}
	pair<int,int>qry(int x,int l,int r,int ql,int qr){
		if(ql<=l&&r<=qr)return !x?mp(0,-l):t[x].mx;
		if(r<ql||qr<l)return mp(0,-0x3f3f3f3f);
		return max(qry(t[x].lc,l,mid,ql,qr),qry(t[x].rc,mid+1,r,ql,qr));
	}
}T;
int rt[N];vector<int>e[N];
int f[N][M];
pair<int,int>ans[N];
vector<tuple<int,int,int>>qry[N];
struct SAM{
	int l[N],fa[N],ch[N][26],sz,lst;
	SAM(){sz=lst=1;}
	void add(int c,int id){
		int cur=++sz,p=lst;rt[cur]=T.build(1,m,id);
		l[cur]=l[lst]+1;
		for(p=lst;p&&!ch[p][c];p=fa[p])
			ch[p][c]=cur;
		if(!p)fa[cur]=1;
		else{
			int q=ch[p][c];
			if(l[q]==l[p]+1)fa[cur]=q;
			else{
				int nw=++sz;
				l[nw]=l[p]+1;
				memcpy(ch[nw],ch[q],sizeof ch[q]);
				fa[nw]=fa[q];
				for(;p&&ch[p][c]==q;p=fa[p])
					ch[p][c]=nw;
				fa[cur]=fa[q]=nw;
			}
		}
		lst=cur;
	}
	void build(){
		for(int i=2;i<=sz;i++)
			f[i][0]=fa[i],e[fa[i]].pb(i);
		for(int j=1;j<M;j++)
			for(int i=1;i<=sz;i++)
				f[i][j]=f[f[i][j-1]][j-1];
	}
	void dfs(int u){
		for(auto v:e[u])
			dfs(v),rt[u]=T.merge(rt[u],rt[v],1,m);
		for(auto [l,r,id]:qry[u])
			ans[id]=T.qry(rt[u],1,m,l,r);
	}
}S;
signed main(){
	scanf("%s",s+1);n=strlen(s+1);
	read(m);for(int i=1;i<=m;i++){
		S.lst=1;scanf("%s",t+1);int l=strlen(t+1);
		for(int j=1;j<=l;j++)S.add(t[j]-'a',i);
	}
	S.build();
	int now=1,len=0;
	for(int i=1;i<=n;i++){
		int c=s[i]-'a';
		if(S.ch[now][c])now=S.ch[now][c],len++;
		else{
			for(;now&&!S.ch[now][c];now=S.fa[now]);
			if(now)len=S.l[now]+1,now=S.ch[now][c];
			else now=1,len=0;
		}
		pos[i]=now,lcs[i]=len;
	}
	read(q);for(int i=1;i<=q;i++){
		int l,r,pl,pr;read(l,r,pl,pr);
		if(lcs[pr]<pr-pl+1){
			ans[i]=mp(0,-l);
			continue;
		}
		int now=pos[pr];
		for(int j=M-1;~j;j--)if(S.l[f[now][j]]>=pr-pl+1)
			now=f[now][j];
		//printf("%d\n",now);
		qry[now].pb({l,r,i});
	}
	S.dfs(1);
	for(int i=1;i<=q;i++)
		write(-ans[i].se),pc(' '),write(ans[i].fi),pc('\n');
}