#include<cstdio>
#include<cstring>
#include<vector>
#include<queue>
#include<set>
#include<cmath>
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
const int N = 23333;

int main() {
	int a,b; read(a); read(b);
	rep(x,1,a-1) rep(y,1,b-1) if (x!=y) {
		int A=sqrt(a*a-x*x),B=sqrt(b*b-y*y);
		if (A*A+x*x==a*a&&B*B+y*y==b*b&&a*a+b*b==(A+B)*(A+B)+(x-y)*(x-y)) {
			puts("YES");
			printf("%d %d\n",0,0);
			printf("%d %d\n",-A,x);
			printf("%d %d\n",B,y);
			exit(0);
		}
	}
	puts("NO");
	return 0;
}