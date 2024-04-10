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
const int N = 33, mo = 1e9+7;
int dp[N][N][N*N],a[N];
int power(int a, int n) {
	int res=1;
	while (n) {
		if (n&1) res=1LL*res*a%mo;
		a=1LL*a*a%mo;
		n>>=1;
	}
	return res;
}
int solve(int bit) {
	memset(dp,0,sizeof(dp));
	ll res=0; bool flag=0;
//	printf("%d : ",bit);per(i,3,0) printf("a[%d]=%d; ",i,a[i]); puts("");
	per(i,30,0) if (a[i]) {flag=1; dp[1][i][30-bit]=1; res+=power(2,31-(30-bit)); break;}
	if (!flag) {
		dp[0][bit+1][0]=1;
		rep(i,1,30) per(j,30,0) rep(s,0,i*31) if (s-(i+30-j)>=0) {
			rep(k,j+1,30) (dp[i][j][s]+=dp[i-1][k][s-(i+30-j)])%=mo;
			res+=1LL*dp[i][j][s]*power(2,i*31-s)%mo;
		//	if (dp[i][j][s]) printf("(%d,%d,%d)\n",i,j,s);
		}
		return res%mo;
	}
	rep(i,2,30) per(j,30,0) if (a[j]||j<=bit) rep(s,0,i*31) {
		int t=s-(i+30-j-(j>bit)); if (t<0) continue; int &x=dp[i][j][s];
		rep(k,j+1,30) {(x+=dp[i-1][k][t]); x=x>mo?x-mo:x;}
		if (x) res+=1LL*x*power(2,i*31-s)%mo;
	}
	return res%mo;
}
int getans(int k, int bit) {
	if (!bit) {
		int res=0; rep(i,0,1) if (i<=(k&1)) {a[bit]=i; res+=solve(bit-1);}
		return res%mo;
	}
	if ((k>>bit)&1) {
		int tmp=solve(bit-1); a[bit]=1;
		return (tmp+getans(k,bit-1))%mo;
	}
	else return getans(k,bit-1);
}
int main() { //freopen("1.in","r",stdin);
	int k; read(k);
	printf("%d",(getans(k,30)+1)%mo);
	return 0;
}