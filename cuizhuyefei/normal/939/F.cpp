#include<cstdio>
#include<cstring>
#include<vector>
#include<queue>
#include<iostream>
#include<algorithm>
#define fi first
#define se second
#define L(i,u) for (int i=head[u]; i!=0; i=nxt[i])
#define rep(i,a,b) for (int i=a; i<=b; i++)
#define per(i,a,b) for (int i=a; i>=b; i--)
typedef long long ll;
using namespace std;
typedef pair<int,int> Pii;
typedef vector<int> vec;
inline void read(int &x) {
	x=0; char c=getchar(); int f=1;
	while (!isdigit(c)) {if (c=='-') f=-1; c=getchar();}
	while (isdigit(c)) {x=x*10+c-'0'; c=getchar();} x*=f;
}
const int N = 102000;
int n,k,l[N],r[N],f[102][N];
int q[N],pos[N],F,R;
inline void push(int p, int v) {
	while (F<=R&&q[R]>=v) R--; q[++R]=v; pos[R]=p;
//	while (F<=R&&q[R]>v) R--; 
//	if (F<=R&&q[R]==v) {cnt[R]++;} else {q[++R]=v; cnt[R]=1;}
}
inline void del(int p, int v) {
	if (F<=R&&pos[F]==p) F++;
//	if (F<=R&&q[F]==v) {cnt[F]--; if (!cnt[F]) F++;}
}
int main() { //freopen("1.in","r",stdin);
	read(n); read(k);
	rep(i,1,k) read(l[i]),read(r[i]);
	l[k+1]=n*2; r[k+1]=n*2; k++;
	memset(f,0x3f3f3f3f,sizeof(f)); f[0][0]=0;
	rep(i,1,k) {
		int dis=r[i]-r[i-1],d=l[i]-r[i-1];
		rep(j,0,n) if (j-dis>=0) f[i][j]=min(f[i][j],f[i-1][j-dis]);
		F=1; R=0;
		rep(j,0,n) {
			if (j-1-dis>=0) del(j-1-dis,f[i-1][j-1-dis]);
			if (j-d>=0) push(j-d,f[i-1][j-d]);
			if (F<=R) f[i][j]=min(f[i][j],q[F]+2);
		}
		F=1; R=0;
		per(j,r[i-1]+r[i]-l[i],r[i-1]) if (j>=0&&j<=n) push(j,f[i-1][j]);
		if (F<=R) f[i][0]=min(f[i][0],q[F]+1);
		rep(j,1,n) {
			if (r[i-1]+r[i]-l[i]-(j-1)>=0) del(r[i-1]+r[i]-l[i]-(j-1),f[i-1][r[i-1]+r[i]-l[i]-(j-1)]);
			if (r[i-1]-j>=0) push(r[i-1]-j,f[i-1][r[i-1]-j]);
		//	if (i==2&&j==49) printf("<%d %d>\n",F,R);
			if (F<=R) f[i][j]=min(f[i][j],q[F]+1);
		}
	}
	if (f[k][n]<0x3f3f3f3f) printf("Full\n%d",f[k][n]); else puts("Hungry");
	return 0;
}