#pragma GCC optimize("Ofast")
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<queue>
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
const int N = 5e5;
int n,t,l1,l2;
ll qz1[N],qz2[N];
struct ele{int a,t,index;} s[N],x[N],y[N];
int len,p[N];
inline void read(int &x) {
	x=0; char c=getchar(); int f=1;
	while (c<'0'||c>'9') {if (c=='-') f=-1; c=getchar();}
	while (c>='0'&&c<='9') {x=10*x+c-'0'; c=getchar();} x*=f;
}
bool cmp(ele x, ele y) {return x.t<y.t;}
int main() { //freopen("1.in","r",stdin);
	read(n); read(t);
	rep(i,1,n) read(s[i].a),read(s[i].t),s[i].index=i;
	int ans=0,l=1,r=n;
	while (l<=r) {
		int mid=(l+r)>>1; l1=l2=0;
		rep(i,1,n) if (s[i].a>=mid) y[++l2]=s[i];
		else x[++l1]=s[i];
	//	if (l1)sort(x+1,x+l1+1,cmp);
		if (l2)sort(y+1,y+l2+1,cmp);
	//	rep(i,1,l1) qz1[i]=qz1[i-1]+x[i].t;
		rep(i,1,l2) qz2[i]=qz2[i-1]+y[i].t;
		int i=0;
		if (l2>=mid&&qz2[mid]<=t) {
			ans=mid; l=mid+1;
			len=0; rep(j,1,ans) p[++len]=y[j].index;
		} else r=mid-1;
		/*rep(j,ans,l2) {
			if (mid-j>=0&&mid-j<=l1&&qz1[mid-j]+qz2[j]<=t) i=max(i,j);
		}
		if (i>ans) {ans=i;
			len=0; rep(j,1,mid-i) p[++len]=x[j].index;
			rep(j,1,i) p[++len]=y[j].index;
		}
		ans=max(ans,i); if (i<ans) break;*/ // printf("%d \n",x);
	}
	printf("%d\n%d\n",ans,len);
	rep(i,1,len) printf("%d ",p[i]);
	return 0;
}