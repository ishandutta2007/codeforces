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
const int N = 100030;
int n,q[N],len,f[27][N]; //0 no; else pre
bool ok[N];

inline void read(int &x) {
	x=0; char c=getchar(); int f=1;
	while (c<'0'||c>'9') {if (c=='-') f=-1; c=getchar();}
	while (c>='0'&&c<='9') {x=10*x+c-'0'; c=getchar();} x*=f;
}
void print(int k) { //f[k][n]
	per(i,k,1) {
		rep(j,1,f[i][n]) printf("%c",'a'+i-1);
		int tmp=f[i][n]*(f[i][n]-1)/2;
		n-=tmp;
	}
}
int main() {
	read(n); f[0][0]=1; len=1; q[len]=0;
	if (n==0) {printf("ab"); return 0;}
	rep(i,1,26) {
	/*rep(j,1,n) {
		if (ok[j]) continue;
		rep(k,2,2000) {
			int tmp=k*(k-1)>>1;
			if (j-tmp<0) break;
			if (ok[j-tmp]) {f[i][j]=k; ok[j]=1; break;}
		}
	}*/
		rep(j,1,len) {
			rep(k,2,2000) {
				int tmp=k*(k-1)>>1;
				if (q[j]+tmp>n) break;
				f[i][q[j]+tmp]=k;
			}
		}
		len=0;
		rep(j,1,n) if (!ok[j]&&f[i][j]>=1) {ok[j]=1; q[++len]=j;}
		if (ok[n]) {
			print(i);
			return 0;
		}
	}
}