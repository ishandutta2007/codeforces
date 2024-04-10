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
int q,n;


inline void read(int &x) {
	x=0; char c=getchar(); int f=1;
	while (c<'0'||c>'9') {if (c=='-') f=-1; c=getchar();}
	while (c>='0'&&c<='9') {x=10*x+c-'0'; c=getchar();} x*=f;
}

int main() {
	read(q);
	while (q--) {
		read(n);
		if (n>15) {
			if (n%2==0) printf("%d\n",n/4);
			else printf("%d\n",1+(n-9)/4);
		}
		else {
			if (n<=3||n==5||n==7||n==11) puts("-1");
			else if (n==4||n==6||n==9) puts("1");
			else if (n==12||n==14) puts("3");
			else puts("2");
		}
	}
	return 0;
}