#include<cstdio>
#include<cstring>
#include<vector>
#include<queue>
#include<set>
#include<map>
#include<cstdlib>
#include<iostream>
#include<algorithm>
#define fi first
#define se second
#define L(i,u) for (int i=head[u]; i!=0; i=nxt[i])
#define rep(i,a,b) for (register int i=a; i<=b; i++)
#define per(i,a,b) for (register int i=a; i>=b; i--)
typedef long long ll;
using namespace std;
typedef pair<int,int> Pii;
typedef vector<int> Vi;
inline void read(int &x) {
	x=0; char c=getchar(); int f=1;
	while (!isdigit(c)) {if (c=='-') f=-1; c=getchar();}
	while (isdigit(c)) {x=x*10+c-'0'; c=getchar();} x*=f;
}
const int N = 4004;
int n,f[N],a[N],g[N],pre[N];
int rec[2003][2003],len[2003];
struct seg{int l,r,index;} s[N];
bool cmp(seg a, seg b) {return a.l!=b.l ? a.l>b.l : a.r<b.r;}
int main() { //freopen("1.in","r",stdin);
	read(n); rep(i,1,n) {
		int a,b;read(a),read(b);s[i].index=i;
		s[i].l=a-b; s[i].r=a+b;
	}
	int Len=0; rep(i,1,n) a[++Len]=s[i].l,a[++Len]=s[i].r;
	sort(a+1,a+Len+1); Len=unique(a+1,a+Len+1)-a-1;
	rep(i,1,n) {
		s[i].l=lower_bound(a+1,a+Len+1,s[i].l)-a;
		s[i].r=lower_bound(a+1,a+Len+1,s[i].r)-a;
	}
	sort(s+1,s+n+1,cmp); ++n; s[n].l=1; s[n].r=Len;
//	rep(i,1,n) printf("%d : %d %d %d\n",i,s[i].l,s[i].r,s[i].index);
	f[1]=1; len[1]=1; rec[1][1]=s[1].index;
	rep(i,2,n) {
		int p=s[i].l-1; int pos=i; rep(j,1,i) g[j]=pre[j]=0;
		rep(j,1,Len) a[j]=pos;
		per(j,i-1,1) if (s[j].r<=s[i].r) {
			while (p<s[j].l) {++p; if (g[a[p]]>g[pos]) pos=a[p];}
			g[j]=g[pos]+f[j]; pre[j]=pos;
			if (s[j].r<=p) {if (g[j]>g[pos]) pos=j;}
			else {if (g[j]>g[a[s[j].r]]) a[s[j].r]=j;}
		}
		int mx=i; rep(j,1,i-1) if (g[j]>g[mx]) mx=j; int ned=g[mx];
		while (ned) {
			rep(j,1,len[mx]) rec[i][++len[i]]=rec[mx][j]; //printf("%d : %d\n",i,mx);
			ned-=f[mx]; mx=pre[mx];
		}
		rec[i][++len[i]]=s[i].index; f[i]=len[i];
	//	printf("%d --> ",len[i]);
	//	rep(j,1,len[i]) printf("%d ",rec[i][j]);
	//	puts("");
	}
	
	len[n]--; printf("%d\n",len[n]);
	rep(i,1,len[n]) printf("%d ",rec[n][i]);
	return 0;
}