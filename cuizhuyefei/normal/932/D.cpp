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
const int N = 404000;
int pos[N][19],mx[N][19],fa[N][19];

inline void read(ll &x) {
	x=0; char c=getchar(); int f=1;
	while (c<'0'||c>'9') {if (c=='-') f=-1; c=getchar();}
	while (c>='0'&&c<='9') {x=10*x+c-'0'; c=getchar();} x*=f;
}
ll n=1,Q,dep[N],len[N],w[N],val[N][19];
int main() { //freopen("1.in","r",stdin);
	read(Q); ll lst=0; dep[1]=len[1]=1;
	while (Q--) {
		ll op,p,q; read(op); read(p); read(q);
		ll R,W,X;
		if (op==1) {
			R=p^lst; W=q^lst;
		//	printf("A %lld %lld\n",R,W);
			n++; dep[n]=dep[R]+1; w[n]=W;
			fa[n][0]=R;
			rep(i,1,18) if (dep[n]>=(1<<i))
				fa[n][i]=fa[fa[n][i-1]][i-1];
			mx[n][0]=W;
			rep(i,1,18) if (dep[n]>=(1<<i))
				mx[n][i]=max(mx[n][i-1],mx[fa[n][i-1]][i-1]);
			per(i,18,0) if (dep[R]>=(1<<i)) { //R
				if (mx[R][i]<W) R=fa[R][i];
			}
			pos[n][0]=R; //R????????????????
			len[n]=len[pos[n][0]]+1; //pos=0 : end
			rep(i,1,18) if (len[n]>=(1<<i))
				pos[n][i]=pos[pos[n][i-1]][i-1];
			val[n][0]=W;
			rep(i,1,18) if (len[n]>=(1<<i))
				val[n][i]=val[n][i-1]+val[pos[n][i-1]][i-1];
		}
		else {
			R=p^lst; X=q^lst;
		//	printf("Q %lld %lld\n",R,X);
			lst=0;
			per(i,18,0) if (len[R]>=(1<<i))
				if (val[R][i]<=X) {X-=val[R][i]; R=pos[R][i]; lst+=1<<i;}
			printf("%lld\n",lst);
		}
	}
	return 0;
}