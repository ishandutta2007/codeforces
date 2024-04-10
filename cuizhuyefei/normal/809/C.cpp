#pragma GCC optimize("Ofast")
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
const int mo = 1e9+7;
int kk;
ll cnt[32][2][2][2],f[31][2][2][2]; //1=   0<
inline int calc(int a, int b, int c) {return !a?0:(b>c?-1:(b==c?1:0));}
inline ll solve(int n, int m) {
	n--; m--; if (n<0||m<0) return 0;
	memset(cnt,0,sizeof(cnt)); memset(f,0,sizeof(f));
	cnt[31][1][1][1]=1;
	per(x,31,1) rep(i,0,1) rep(j,0,1) rep(k,0,1) {
		ll CNT=cnt[x][i][j][k],F=f[x][i][j][k];
		if (!CNT&&!F) continue;
		rep(ii,0,1) rep(jj,0,1) {
			int I=calc(i,ii,(n>>(x-1))&1),J=calc(j,jj,(m>>(x-1))&1),K=calc(k,ii^jj,(kk>>(x-1))&1);
			if (I<0||J<0||K<0) continue;
			(cnt[x-1][I][J][K]+=CNT)%=mo;
			(f[x-1][I][J][K]+=F+1LL*((ii^jj)<<(x-1))*CNT%mo)%=mo;
		}
	//	printf("%d %d %d %d : %lld %lld\n",x,i,j,k,CNT,F);
	}
	ll res=0; rep(i,0,1) rep(j,0,1) rep(k,0,1) res+=f[0][i][j][k]+cnt[0][i][j][k];
//	printf("%d %d : %lld\n",n,m,res%mo);
	return res%mo;
}
int main() {
	int q; read(q);
	while (q--) {
		int x1,y1,x2,y2; read(x1); read(y1); read(x2); read(y2); read(kk); kk--;
		printf("%lld\n",(solve(x2,y2)-solve(x2,y1-1)-solve(x1-1,y2)+solve(x1-1,y1-1)+mo+mo)%mo);
	}
	return 0;
}