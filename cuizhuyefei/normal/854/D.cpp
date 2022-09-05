#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<set>
#include<vector>
#define fi first
#define se second
#define pb push_back
#define max(a,b) ((a)>(b)?(a):(b))
#define min(a,b) ((a)<(b)?(a):(b))
#define rep(i,a,b) for (int i=a; i<=b; i++)
#define per(i,a,b) for (int i=a; i>=b; i--)
#define L(i,u) for (int i=head[u]; i!=0; i=edge[i].nxt)
#define abs(a) ((a)>0 ? (a) : -(a))
#define INF 0x3f3f3f3f
using namespace std;
typedef pair<int,int> Pii;
typedef vector<int> Vi;
typedef long long ll;
typedef long double ld;
const int N = 1e6+3;
int Point;
multiset<int> Set[N];
int v[N],sum,sum1;
ll sumv,sumv1;
int n,m,k,l1,l2;
struct X {
	int t,u,c;
} s1[N],s2[N];
ll ans=1e18;
inline void read(int &x) {
	x=0; char c=getchar(); int f=1;
	while (c<'0'||c>'9') {if (c=='-') f=-1; c=getchar();}
	while (c>='0'&&c<='9') {x=10*x+c-'0'; c=getchar();} x*=f;
}
bool cmp (X a, X b) {return a.t<b.t;}
void getans(int t) {
	if (sum<n||sum1<n) return;
	while (Point<=l2&&s2[Point].t<t) {
		int tmp=*(Set[s2[Point].u].begin());
		multiset<int> ::iterator it=Set[s2[Point].u].find(s2[Point].c);
		Set[s2[Point].u].erase(it); 
		if (Set[s2[Point].u].empty()) {sum1--; break;}
		else sumv1+=*(Set[s2[Point].u].begin())-tmp; Point++;
	}
	if (sum==n&&sum1==n) ans=min(ans,sumv+sumv1);
}
int main() { //freopen("1.in","r",stdin);
	read(n); read(m); read(k);
	rep(i,1,m) {
		int a,b,c,d; read(a); read(b); read(c); read(d);
		if (b==0) {s2[++l2].t=a; s2[l2].u=c; s2[l2].c=d;}
		else {s1[++l1].t=a; s1[l1].u=b; s1[l1].c=d;}
	}
	sort(s1+1,s1+l1+1,cmp);
	sort(s2+1,s2+l2+1,cmp);
//	rep(i,1,l1) printf("%d %d %d\n",s1[i].t,s1[i].u,s1[i].c); puts("");
//	rep(i,1,l2) printf("%d %d %d\n",s2[i].t,s2[i].u,s2[i].c); puts("");
	Point=1; rep(i,1,l2) {
		int tmp= Set[s2[i].u].empty() ? 0 : *Set[s2[i].u].begin();
		if (Set[s2[i].u].empty()) sum1++;
		Set[s2[i].u].insert(s2[i].c);
		sumv1+=*Set[s2[i].u].begin()-tmp;
	//	printf("(%d %d)\n",Set[1].size(),Set[2].size());
	}
//	printf("<%d %d %d %d %d %d>\n",sumv1,Point,*Set[1].begin(),*Set[2].begin(),Set[1].size(),Set[2].size());
	memset(v,0x3f3f3f3f,sizeof(v));
	rep(i,1,l1) {
		if (v[s1[i].u]==0x3f3f3f3f) {v[s1[i].u]=s1[i].c; sum++; sumv+=s1[i].c;}
		else if (s1[i].c<v[s1[i].u]) {sumv+=s1[i].c-v[s1[i].u]; v[s1[i].u]=s1[i].c;}
		getans(s1[i].t+k+1);
	//	if (sum==n&&sum1==n) printf("%d:%d %d %d %d %d\n",i,sumv,sumv1,Point,*Set[1].begin(),*Set[2].begin());
	}
	if (ans==1e18) puts("-1"); else printf("%lld",ans);
	return 0;
}