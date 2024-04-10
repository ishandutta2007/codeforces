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
const int N = 700000;
int n,U,a[N];
double ans=-1;
int main() {
	read(n); read(U); rep(i,1,n) read(a[i]);
	for(int i=1,k=1; i<=n; i++) {
		while (k+1<=n&&a[k+1]-a[i]<=U) k++;
		if (i+1<k) ans=max(ans,1.0*(a[k]-a[i+1])/(a[k]-a[i]));
	}
	if (ans<0) puts("-1"); else printf("%.10lf",ans);
	return 0;
}