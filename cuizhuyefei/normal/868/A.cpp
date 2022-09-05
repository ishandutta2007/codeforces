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
const int N = 105;
int n;
char t[4],s[N][4];

inline void read(int &x) {
	x=0; char c=getchar(); int f=1;
	while (c<'0'||c>'9') {if (c=='-') f=-1; c=getchar();}
	while (c>='0'&&c<='9') {x=10*x+c-'0'; c=getchar();} x*=f;
}

int main() {scanf("%s",t+1);
	read(n); rep(i,1,n) scanf("%s",s[i]+1);
	bool ok=0;
	rep(i,1,n) if (s[i][1]==t[1] && s[i][2]==t[2]) ok=1;
	rep(i,1,n) rep(j,1,n) if (s[i][2]==t[1] && s[j][1]==t[2]) ok=1;
	printf("%s",ok?"YES":"NO");
	return 0;
}