#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<iostream>
#include<cstring>
#include<queue>
#include<cmath>
#define MAXN 20005
#define MAXM 200050
#define INF 0x7f7f7f7f
#define ll long long
#define rep(i,a,b) for (int i=(a); i<=(b); i++)
#define clr(x) memset(x,0,sizeof(x));
using namespace std;
#define N 200005
int n,s,a[N];
int ans,ans1;
ll b[N];
inline void read(int &x) {
	x=0; int f=1; char c=getchar();
	while (c<'0'||c>'9'){if (c=='-') f=-1; c=getchar();}
	while (c>='0'&&c<='9'){x=10*x+c-'0'; c=getchar();} x*=f;
}
bool judge(int k) {
	rep(i,1,n) b[i]=a[i]+(ll)i*k;
	sort(b+1,b+n+1);
	ll tmp=0;
	rep(i,1,k) {
		tmp+=b[i];
		if (tmp>s) return 0;
	}
	ans=k; ans1=tmp;
	return 1;
}
int main()
{
	read(n); read(s);
	rep(i,1,n) read(a[i]);
	int l=0,r=n;
	while (l<=r) {
		int mid=(l+r)>>1;
		if (judge(mid)) {l=mid+1;}
		else r=mid-1;
	}
	printf("%d %d",ans,ans1);
	return 0;
}