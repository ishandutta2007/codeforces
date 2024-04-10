#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<queue>
#include<vector>
#define fi first
#define se second
#define pb push_back
#define max(a,b) ((a)>(b)?(a):(b))
#define min(a,b) ((a)<(b)?(a):(b))
#define rep(i,a,b) for (int i=a; i<=b; i++)
#define per(i,a,b) for (int i=a; i>=b; i--)
#define L(i,u) for (int i=head[u]; i!=0; i=edge[i].nxt)
#define abs(a) ((a)>0 ? (a) : -(a))
#define INF 0x3f3f3f3f
using namespace std;
typedef pair<int,int> Pii;
typedef vector<int> Vi;
typedef long long ll;
typedef long double ld;
const int N = 33333;
int n,m,c,a[N];

inline void read(int &x) {
	x=0; char c=getchar(); int f=1;
	while (c<'0'||c>'9') {if (c=='-') f=-1; c=getchar();}
	while (c>='0'&&c<='9') {x=10*x+c-'0'; c=getchar();} x*=f;
}

int main() {
	read(n); read(m); read(c);
	int p1=0,p2=n+1;
	while (m--) {
		int pos,x; read(x);
		if (x<=c/2) {
			if (p1==0 || (pos=upper_bound(a+1,a+p1+1,x)-a)==p1+1) {pos=p1+1; p1++; a[p1]=x;}
			else a[pos]=x;
		}
		else {
			//(pos=lower_bound(a+p2,a+n+1,x)-a)==p2
			if (p2==n+1 || x<=a[p2]) {pos=p2-1; p2--; a[p2]=x;}
			else {pos=lower_bound(a+p2,a+n+1,x)-a-1; a[pos]=x;}
		}
		printf("%d\n",pos); fflush(stdout);
		if (p1+1>=p2) return 0;
	}
//	return 0;
}