#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define per(i,a,b) for(int i=(a);i>=(b);i--)
#define REP(i,n) for(int i=0;i<(n);i++)
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

const int N=505,M=N*N;
struct node{int a,b,c,d;}e[M];
int nxt[N][2],t[N],a[N],A,n,m,V,C;
char s[N];

namespace sat{
	int dfn[N],low[N],bel[N],stk[N];
	int n,clk,res,top;
	vi e[N];
	void add(int a,int b){
		e[a].pb(b);
	}
	void init(int _n){
		n=_n,clk=res=top=0;
		rep(i,1,n){
			e[i].clear();
			dfn[i]=bel[i]=0;
		}
	}
	void tarjan(int u){
		dfn[u]=low[u]=++clk;
		stk[++top]=u;
		for(auto v:e[u])
			if(!dfn[v]){
				tarjan(v);
				low[u]=min(low[u],low[v]);
			}
			else if(!bel[v])
				low[u]=min(low[u],dfn[v]);
		if(dfn[u]!=low[u])return;
		++res;
		while(stk[top]!=u)
			bel[stk[top--]]=res;
		bel[stk[top--]]=res;
	}
	int solve(){
		rep(i,1,n)	
			if(!dfn[i])tarjan(i);
		rep(i,1,n/2)
			if(bel[i]==bel[i+n/2])return 0;
		return 1;
	}
}

int calc(int p,int c){
	if(c>=A)return 0;
	sat::init(n*2);
	rep(i,1,m){
		int u=e[i].a+e[i].b*n;
		int v=e[i].c+e[i].d*n;
		sat::add(u,v);
		u=e[i].a+(1-e[i].b)*n;
		v=e[i].c+(1-e[i].d)*n;
		sat::add(v,u);
	}
	rep(i,1,n){
		if(!V)sat::add(i,i+n);
		if(!C)sat::add(i+n,i);
	}
	a[p]=c;
	rep(i,1,p)
		sat::add(i+(1-t[a[i]])*n,i+t[a[i]]*n);
	return sat::solve();
}

int main(){
	scanf("%s",s),A=strlen(s);
	nxt[A][0]=nxt[A][1]=A;
	per(i,A-1,0){
		REP(t,2)nxt[i][t]=nxt[i+1][t];
		nxt[i][t[i]=(s[i]=='C')]=i;
		V|=!t[i],C|=t[i];
	}
	read(n),read(m);
	rep(i,1,m){
		read(e[i].a);
		e[i].b=getchar()=='C';
		read(e[i].c);
		e[i].d=getchar()=='C';
	}
	scanf("%s",s+1);
	rep(i,1,n)a[i]=s[i]-'a';
	int s=0;
	per(i,n,1){
		int u=nxt[a[i]+(i<n)][0];
		int v=nxt[a[i]+(i<n)][1];
		if(u>v)swap(u,v);
		if(calc(i,u)){s=i+1;break;}
		if(calc(i,v)){s=i+1;break;}
	}
	if(!s)return puts("-1"),0;
	rep(i,s,n){
		int u=nxt[0][0],v=nxt[0][1];
		if(u>v)swap(u,v);
		if(calc(i,u))continue;
		calc(i,v);
	}
	rep(i,1,n)putchar('a'+a[i]);
	return puts(""),0;
}