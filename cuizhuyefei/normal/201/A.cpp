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


inline void read(int &x) {
	x=0; char c=getchar(); int f=1;
	while (c<'0'||c>'9') {if (c=='-') f=-1; c=getchar();}
	while (c>='0'&&c<='9') {x=10*x+c-'0'; c=getchar();} x*=f;
}

int main() {
	int n;read(n);
	if (n==1) {printf("1"); return 0;}
//	if (n==4) {printf("2"); return 0;}
	if (n==2||n==4||n==5) {printf("3"); return 0;}
	rep(i,5,10000) {
		if (i&1) {
			int l=3,r=(i*i+1)/2;
			if (n>=l&&n<=r) {printf("%d",i); return 0;}
		}
		else if (n%4==0) {
			int x=n,mx=(i-2)/2; mx=(mx*mx+1)/2; //(i-2)*(i-2)*4;
			if (mx*4>=x) {printf("%d",i); return 0;}
		}
	}
	return 0;
}