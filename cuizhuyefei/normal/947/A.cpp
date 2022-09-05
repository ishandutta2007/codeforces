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
const int N = 1000055;
int n,ans;
int mrk[N],prime[N],len;
int qz[N],b[N];
void getp(int n) {
	rep(i,2,n) {
		if (!mrk[i]) prime[++len]=i;
		rep(j,1,len) {
			if (i*prime[j]>n) break;
			mrk[i*prime[j]]=prime[j]; if (i%prime[j]==0) break;
		}
	}
	rep(i,1,n) if (mrk[i]) {
		int t=i;
		while (mrk[t]) t/=mrk[t]; b[i]=t;
	}
}
int main() {
	read(n);getp(1000000); int zd=n; ans=n;
	for (int i=2; i<=n; i++) if (!mrk[i]&&n%i==0) {zd=min(zd,n-i+1);}
//	printf("%d\n",zd);
	rep(i,zd,n) if (mrk[i]) ans=min(ans,i-b[i]+1);
	printf("%d",ans);
	return 0;
}