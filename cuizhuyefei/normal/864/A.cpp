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
const int N = 500050;
int n,A[N],buc[N];
int x=-1,a=-1,b=-1,num;

inline void read(int &x) {
	x=0; char c=getchar(); int f=1;
	while (c<'0'||c>'9') {if (c=='-') f=-1; c=getchar();}
	while (c>='0'&&c<='9') {x=10*x+c-'0'; c=getchar();} x*=f;
}

int main() {
	read(n); rep(i,1,n) read(A[i]), buc[A[i]]++;
	rep(i,1,100) {
		num+=(buc[i]>0); 
		if (buc[i]>0) {
			if (a==-1) {x=buc[i]; a=i;} else b=i;
		}
	}
	if (num==2&&x*2==n) printf("YES\n%d %d",a,b);
	else puts("NO");
	return 0;
}