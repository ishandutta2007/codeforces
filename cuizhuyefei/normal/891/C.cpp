#include<cstdio>
#include<cstring>
#include<iostream>
#include<map>
#include<algorithm>
#define rep(i,a,b) for (int i=a; i<=b; i++)
#define per(i,a,b) for (int i=a; i>=b; i--)
typedef long long ll;
using namespace std;
typedef pair<int,int> Pii;
inline void read(int &x) {
	x=0; char c=getchar(); int f=1;
	while (!isdigit(c)) {if (c=='-') f=-1; c=getchar();}
	while (isdigit(c)) {x=x*10+c-'0'; c=getchar();} x*=f;
}
inline int max(int a, int b) {return a>b ? a : b;}
inline int min(int a, int b) {return a<b ? a : b;}
const int N = 600600;
int n,m,len,x[N],y[N],z[N],pos,f[N];
bool gg[N],mrk[N];
struct Edge {
	int a,b,c;
} s[N];
struct Que {
	int v,index;
} q[N];
map<int,int> rec;
bool cmp(Edge x, Edge y) {return x.c<y.c;}
bool cmp1(Que a, Que b) {return z[a.v]<z[b.v] || (z[a.v]==z[b.v]&&a.index<b.index);}
inline int find (int x) {
	if (f[x]==x) return x;
	rec.insert(Pii(x,f[x]));
	f[x]=find(f[x]); return f[x];
}
inline bool merge(int x, int y) {
	int fx=find(x),fy=find(y);
	if (fx!=fy) {rec.insert(Pii(fx,f[fx])); f[fx]=fy; return 1;}
	return 0;
}
inline void getans(int l, int r) {
	while (pos+1<=len && z[q[pos+1].v]==s[l].c) {
		int p=pos+1; while (pos<len && z[q[pos+1].v]==z[q[p].v] && q[pos+1].index==q[p].index) pos++;
		//[p,pos]
		rec.clear();
	//	rep(i,p,pos) if (find(x[q[i].v])==find(y[q[i].v])) mrk[i]=1; else mrk[i]=0;
		rep(i,p,pos) if (!merge(x[q[i].v],y[q[i].v])) {gg[q[i].index]=1; break;}
		for (map<int,int>::iterator i=rec.begin(); i!=rec.end(); i++) f[(*i).first]=(*i).second;
	}
	rep(i,l,r) merge(s[i].a,s[i].b);
}
int main() {
//	freopen("1.in","r",stdin);
	read(n); read(m); rep(i,1,n) f[i]=i;
	rep(i,1,m) {read(s[i].a);read(s[i].b);read(s[i].c); x[i]=s[i].a; y[i]=s[i].b; z[i]=s[i].c;}
	int Q; read(Q);
	rep(i,1,Q) {
		int x,y; read(x); rep(j,1,x) {read(y); q[++len]=(Que){y,i};}
	}
	sort(q+1,q+len+1,cmp1);
	sort(s+1,s+m+1,cmp);
	rep(i,1,m) {
		int j; for (j=i+1; j<=m; j++) if (s[j].c!=s[i].c) break;
		//[i,j-1]
		getans(i,j-1); i=j-1;
	}
	rep(i,1,Q) printf("%s\n",gg[i] ? "NO" : "YES");
	return 0;
}