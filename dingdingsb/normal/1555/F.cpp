// Problem: F. Good Graph
// Contest: Codeforces - Educational Codeforces Round 112 (Rated for Div. 2)
// URL: https://codeforces.com/contest/1555/problem/F
// Memory Limit: 256 MB
// Time Limit: 2000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#pragma GCC optimize(2)
#include<bits/stdc++.h>
#define mp make_pair
#define chkmx(a,b) ((a)=max((a),(b)))
#define chkmn(a,b) ((a)=min((a),(b)))
using namespace std;
template<typename T>
inline void read(T &x){x=0;char c=getchar();bool f=false;for(;!isdigit(c);c=getchar())f|=c=='-';for(;isdigit(c);c=getchar())x=x*10+c-'0';if(f)x=-x;}
template<typename T ,typename ...Arg>inline void read(T &x,Arg &...args){read(x);read(args...);}
template<typename T>inline void write(T x){if(x<0)putchar('-'),x=-x;if(x>=10)write(x/10);putchar(x%10+'0');}
//#define int long long
typedef long long ll;
const int N=1e6+100;
int n,m;
#define lc c[x][0]
#define rc c[x][1]
struct Link_Cut_Tree{
    int f[N],c[N][2],v[N],s[N],sz[N];int ban[N],kk[N];
    bool r[N],bt[N],tmp[N];
    bool nroot(int x){
        return c[f[x]][0]==x||c[f[x]][1]==x;
    }
    void pushup(int x){
    	s[x]=s[lc]^v[x]^s[rc];
    	tmp[x]=tmp[lc]||tmp[rc]||x>n;
    	kk[x]=kk[lc]||kk[rc]||ban[x];
    }
    void pushr(int x){
        swap(lc,rc);
        r[x]^=1;
    }
    void pushb(int x){
    	kk[x]=tmp[x];
		if(x>n)ban[x]=1;
		bt[x]=1;
    }
    void pushdown(int x){
        if(r[x]){
            if(lc)pushr(lc);
            if(rc)pushr(rc);
            r[x]=0;
        }
        if(bt[x]){
        	if(lc)pushb(lc);
        	if(rc)pushb(rc);
        	bt[x]=0;
		}
    }
    #define get(x) (c[f[x]][1]==x)
    void rotate(int x){
        int fa=f[x],ffa=f[fa],k=get(x),w=c[x][!k];
        if(nroot(fa))c[ffa][get(fa)]=x;c[x][!k]=fa;c[fa][k]=w;
        if(w)f[w]=fa;f[fa]=x;f[x]=ffa;pushup(fa);
    }
    void splay(int x){
        int y=x,top=0;static int s[N];
        s[++top]=(y);
        while(nroot(y))s[++top]=(y=f[y]);
        while(top)pushdown(s[top--]);
        while(nroot(x)){
            int fa=f[x],ffa=f[fa];
            if(nroot(fa))
                rotate(get(x)!=get(fa)?x:fa);
            rotate(x);
        }pushup(x);
    }
    void access(int x){
        for(int y=0;x;x=f[y=x])
            splay(x),rc=y,pushup(x);
    }
    void makeroot(int x){
        access(x);splay(x);
        pushr(x);
    }
    void split(int x,int y){
        makeroot(x);
        access(y);splay(y);
    }
    bool link(int x,int y){
        makeroot(x);
		f[x]=y;
        return 0;
    }
}T;
struct DSU{
	int fa[N];
	int find(int x){return x==fa[x]?x:fa[x]=find(fa[x]);}
}D;
signed main(){
	read(n,m);
	for(int i=1;i<=n+m;i++)D.fa[i]=i;
	for(int i=1;i<=m;i++){
		int a,b;read(a,b,T.v[i+n]);T.s[i+n]=T.v[i+n];
		T.makeroot(a);
		if(D.find(a)!=D.find(b)){
			T.link(a,i+n);
			T.link(i+n,b);
			D.fa[D.find(a)]=D.find(b);
			puts("YES");
		}else{
			T.split(a,b);
			if(T.s[b]^T.v[i+n]&&T.kk[b]==0)puts("YES"),T.pushb(b);
			else puts("NO");
		}
	}
}