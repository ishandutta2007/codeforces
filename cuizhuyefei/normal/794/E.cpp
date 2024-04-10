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
const int N = 505000;
int n,a[N],ans[N];
int main() {
	read(n); rep(i,1,n) read(a[i]);
	rep(i,0,n-2) {
		if ((n-i)&1) ans[i]=max(min(a[(1+n-i)/2],max(a[(1+n-i)/2+1],a[(1+n-i)/2-1])),min(a[(1+n+i)/2],max(a[(1+n+i)/2+1],a[(1+n+i)/2-1])));
		else ans[i]=max(a[(n-i+1)/2],a[(n+i+2)/2]);
		if ((n&1)&&i==1) ans[i]=max(ans[i],a[n/2+1]);
		if (i-2>=0) ans[i]=max(ans[i],ans[i-2]);
	}
	rep(i,1,n) ans[n-1]=max(ans[n-1],a[i]);
	rep(i,0,n-1) printf("%d ",ans[i]);
	return 0;
}