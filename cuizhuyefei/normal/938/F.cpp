#include<cstdio>
#include<cstring>
#include<vector>
#include<cmath>
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
typedef vector<int> vec;
inline void read(int &x) {
	x=0; char c=getchar(); int f=1;
	while (!isdigit(c)) {if (c=='-') f=-1; c=getchar();}
	while (isdigit(c)) {x=x*10+c-'0'; c=getchar();} x*=f;
}
const int N = 5005;
int n,rk[N][N],pre[N][N],K,a[N];
char s[N],t[N]; int top;
int main() { //freopen("1.in","r",stdin);
	scanf("%s",s+1); n=strlen(s+1); K=log(n)/log(2.0);
	rep(i,0,N-1) rk[0][i]=1; rep(i,0,(1<<K)-1) rk[0][i]=0;
	rep(i,1,n-(1<<K)+1) {
		rep(j,0,(1<<K)-1) {
			rk[i][j]=rk[i-1][j]*26+s[i+j]-'a'; pre[i][j]=0;
			for (register int k=1; k<=j; k<<=1)
				if ((j&k)&&rk[i][j^k]<rk[i][j]) {
					rk[i][j]=rk[i][j^k]; pre[i][j]=k;
				}
		}
	//	rep(j,0,(1<<K)-1) printf("%d ",rk[i][j]); puts("");
		int len=0;
		rep(j,0,(1<<K)-1) a[++len]=rk[i][j]; sort(a+1,a+len+1);
		int tot=1; rep(j,2,len) if (a[i]!=a[i-1]) a[++tot]=a[i]; len=tot;
		rep(j,0,(1<<K)-1) rk[i][j]=lower_bound(a+1,a+len+1,rk[i][j])-a;
	}
	int x=n-(1<<K)+1,y=(1<<K)-1;
	while (x) {
		if (!pre[x][y]) {t[x]=s[x+y]; x--; continue;}
		y-=pre[x][y];
	}
	rep(i,1,n-(1<<K)+1) printf("%c",t[i]);
	return 0;
}