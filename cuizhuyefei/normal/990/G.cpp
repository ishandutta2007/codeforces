#include<cstdio>
#include<cstring>
#include<vector>
#include<queue>
#include<set>
#include<map>
#include<ctime>
#include<cstdlib>
#include<iostream>
#include<algorithm>
#define fi first
#define se second
#define L(i,u) for (int i=head[u]; i!=0; i=nxt[i])
#define rep(i,a,b) for (register int i=a; i<=b; i++)
#define per(i,a,b) for (register int i=a; i>=b; i--)
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
const int N = 405000;
int n,a[N],head[N],to[N],nxt[N],edgenum,L[N],R[N],num,dep[N],len,fa[N],size[N];
int s[N],v[N];
ll f[N];
Vi dot[N];
void add(int u, int v) {
	to[++edgenum]=v; nxt[edgenum]=head[u]; head[u]=edgenum;
}
void dfs(int u, int fa, int Dep) {
	L[u]=++num; dep[u]=Dep;
	L(i,u) if (to[i]!=fa) dfs(to[i],u,Dep+1);
	R[u]=num;
}
bool cmp(int a, int b) {return dep[a]!=dep[b]?dep[a]<dep[b]:L[a]<L[b];}
//bool cmp1(int a, int b) {return s[a]<s[b];}
int find(int x) {return x==fa[x]?x:fa[x]=find(fa[x]);}
void merge(int x, int y) {
	x=find(x);y=find(y);
	if (x!=y)fa[x]=y,size[y]+=size[x];
}
int prime[N],Len,mrk[N],mu[N];
void getp(int n) {
	rep(i,2,n) {
		if (!mrk[i]) prime[++Len]=i;
		rep(j,1,Len) {
			if (i*prime[j]>n) break;
			mrk[i*prime[j]]=prime[j]; if (i%prime[j]==0) break;
		}
	}
	mu[1]=1;
	rep(i,2,n) if (!mrk[i]) mu[i]=-1;
	else {
		int x=mrk[i],lst=i/x; if (lst%x==0) mu[i]=0; else mu[i]=-mu[lst];
	}
}
void getg(int p, int l, int r) {
	rep(i,l,r) {
		while (p<=l-1&&R[a[p]]<L[a[i]]) p++;
		if (p<l&&L[a[p]]<L[a[i]]) merge(p,i);
	}
}
int buc[450]; //448
void SORT(int n) { //a[1..n] sort by s[i]
	memset(buc,0,sizeof(buc));
	rep(i,1,n) buc[s[a[i]]%448]++;
	rep(i,1,448) buc[i]+=buc[i-1];
	rep(i,1,n) v[buc[s[a[i]]%448]--]=a[i];
	memset(buc,0,sizeof(buc));
	rep(i,1,n) buc[s[a[i]]/448]++;
	rep(i,1,448) buc[i]+=buc[i-1];
	per(i,n,1) a[buc[s[v[i]]/448]--]=v[i];
//	memcpy(a);
}
int main() {
	read(n);rep(i,1,n)read(a[i]); getp(200000);
	rep(i,2,n) {int u,v;read(u);read(v);add(u,v);add(v,u);}
	dfs(1,0,0);
	rep(i,1,n) for(int j=1; j*j<=a[i]; j++) if (a[i]%j==0) {
		dot[j].push_back(i); if (j*j!=a[i]) dot[a[i]/j].push_back(i);
	}
	rep(i,1,n) v[i]=i; sort(v+1,v+n+1,cmp);
	rep(i,1,n) s[v[i]]=i;
	rep(v,1,200000) {
		len=dot[v].size(); rep(i,1,len) a[i]=dot[v][i-1];
	//	sort(a+1,a+len+1,cmp1);
		SORT(len);
		rep(i,1,len) fa[i]=i,size[i]=1;
		
		rep(i,1,len) {
			int j; for (j=i+1; j<=len; j++) if(dep[a[j]]!=dep[a[i]]) break;
			//[i,j-1]
			int p=i; while (p-1>=1&&dep[a[p-1]]==dep[a[i]]-1) p--;
			getg(p,i,j-1); //if (v<=3)printf("%d %d %d\n",i,j-1,a[i]);
			i=j-1;
		}
		rep(i,1,len) if (find(i)==i) f[v]+=1LL*size[i]*(size[i]+1)>>1;
	//	if (f[v])printf("%d:%lld %d\n",v,f[v],len);
	}
	rep(i,1,200000) {
		ll res=0;
		for (int j=i; j<=200000; j+=i) res+=mu[j/i]*f[j];
		if (res) printf("%d %lld\n",i,res);
	}
	return 0;
}