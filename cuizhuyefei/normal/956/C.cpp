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
const int N = 600000;
int n,a[N],hz[N];
int main() { //freopen("1.in","r",stdin);
	read(n); rep(i,1,n) read(a[i]);
	hz[n+1]=n; per(i,n,1) hz[i]=min(hz[i+1],i-1-a[i]);
	ll ans=0;
	for (int i=1,xt=0,kind=0; i<=n; i++) {
		if (xt+1<i&&xt+1<=hz[i]) {
			xt++; ans+=kind-a[i]-1; //printf("xt %d\n",i);
		}
		else {kind++; ans+=kind-a[i]-1;}
	}
	printf("%lld",ans);
	return 0;
}