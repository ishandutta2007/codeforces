#include<cstdio>
#include<cstring>
#include<vector>
#include<queue>
#include<bitset>
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
const int N = 10200;
int n,l,r,sum,ans;
int a[N],b[N],qz[N];
bitset<N> f,t;

int main() {
	read(n); int L,R; read(L); read(R);
	rep(i,1,n) read(a[i]),sum+=a[i];
	rep(i,1,n) read(b[i]);
	if (L>=sum) {puts("0"); return 0;}
	R=min(R,sum-1);
	f[0]=1; l=sum-R; r=sum-L;
	rep(i,1,n) if (!b[i]) f|=f<<a[i];
	int len=0; rep(i,1,n) if (b[i]) {a[++len]=a[i];} n=len;
	sort(a+1,a+n+1); rep(i,1,n) qz[i]=qz[i-1]+a[i];
	int p=r+1; per(i,r,l) if (f[i]) {p=i; f[i]=0;}
	if (p<=r) {rep(i,1,n) if (qz[i]<=r-p) ans=i;}
	rep(i,l,r-qz[n]) t[i]=1;
	per(i,n,1) {
		f|=f<<a[i]; rep(j,r-qz[i],r-qz[i-1]) if (j>=l) t[j]=1;
		if ((f&t).count()>0) {ans=max(ans,i); break;}
	}
	printf("%d",ans);
	return 0;
}