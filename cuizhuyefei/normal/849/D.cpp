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
const int N = 100500;
int n,a,b,op[N],p[N],t[N],ansx[N],ansy[N];
vector<int> vec[(N<<1)+3];
struct Dot {
	int x,y;
} dot[N];


inline void LOCAL() {freopen("1.in","r",stdin);}
inline void read(int &x) {
	x=0; char c=getchar(); int f=1;
	while (c<'0'||c>'9') {if (c=='-') f=-1; c=getchar();}
	while (c>='0'&&c<='9') {x=10*x+c-'0'; c=getchar();} x*=f;
}
bool cmp(int a, int b) { //dot[a]<dot[b]
	int x=(op[a]==1) ? p[a] : -t[a];
	int y=(op[b]==1) ? p[b] : -t[b];
	return x<y;
}
bool cmp1(Dot a, Dot b) {
	return a.x!=b.x ? a.x<b.x : a.y>b.y;
}
int main() {
//	freopen("1.in","r",stdin);
	read(n); read(a); read(b);
	rep(i,1,n) {
		read(op[i]); read(p[i]); read(t[i]);
		vec[p[i]-t[i]+N].push_back(i);
	}
	rep(i,1,N<<1) if (vec[i].size()) {
		sort(vec[i].begin(),vec[i].end(),cmp);
		int len=vec[i].size();
		rep(j,0,len-1) {
			int pos=vec[i][j];
			if (op[pos]==1) {dot[j].x=p[pos]; dot[j].y=b;}
			else {dot[j].x=a; dot[j].y=p[pos];}
		}
		sort(dot,dot+len,cmp1);
		rep(j,0,len-1) {
			int pos=vec[i][j];
			ansx[pos]=dot[j].x; ansy[pos]=dot[j].y;
		}
	}
	rep(i,1,n) printf("%d %d\n",ansx[i],ansy[i]);
	return 0;
}