#pragma GCC optimize("Ofast")
#include<cstdio>
#include<cstring>
#include<vector>
#include<string>
#include<iostream>
#include<algorithm>
#include<queue>
#include<ctime>
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
const int N = 503000;
int n,a[N];
ll l[N],r[N],sum[N],Even[N];
int main() { //freopen("1.in","r",stdin);
	read(n); rep(i,1,n-1) read(a[i]);
	rep(i,2,n) if (a[i-1]>1) l[i]=l[i-1]+a[i-1]-(a[i-1]&1);
	per(i,n-1,1) if (a[i]>1) r[i]=r[i+1]+a[i]-(a[i]&1);
	rep(i,1,n-1) {sum[i]=sum[i-1]+a[i]; Even[i]=Even[i-1]+(!(a[i]&1));}
	ll mx=0,ans=0;
//	printf("%lld %lld\n",sum[2]-sum[1],Even[2]-Even[1]);
//	printf("%lld %lld\n",l[2]-sum[1]+Even[1],r[3]+sum[2]-Even[2]);
	rep(i,1,n) {
		mx=max(mx,l[i]-sum[i-1]+Even[i-1]);
		ans=max(ans,r[i]+sum[i-1]-Even[i-1]+mx);
	//	printf("%d %lld\n",i,r[i]+sum[i-1]-Even[i-1]+mx);
	}
	printf("%lld",ans);
	return 0;
}