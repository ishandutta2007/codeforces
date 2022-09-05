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
const int N = 5002, mo = 1e9+7;
char s[N];
int n,f[N][28],sum[N],C[N][N];


inline void LOCAL() {freopen("1.in","r",stdin);}
inline void read(int &x) {
	x=0; char c=getchar(); int f=1;
	while (c<'0'||c>'9') {if (c=='-') f=-1; c=getchar();}
	while (c>='0'&&c<='9') {x=10*x+c-'0'; c=getchar();} x*=f;
}

int main() {
	read(n); scanf("%s",s+1);
	C[0][0]=1; //1 a
	rep(i,1,n) {
		C[i][0]=C[i][i]=1;
		rep(j,1,i-1) C[i][j]=(C[i-1][j-1]+C[i-1][j])%mo;
	}
	sum[0]=1;
	rep(i,1,n) rep(j,1,n) {
		int tmp=f[j][s[i]-'a'];
		f[j][s[i]-'a']=(sum[j-1]-f[j-1][s[i]-'a']+mo)%mo;
		sum[j]=(sum[j]+f[j][s[i]-'a']-tmp)%mo;
		if (sum[j]<0) sum[j]+=mo;
	}
	int ans=0; 
	rep(i,1,n) ans=(ans+(ll)C[n-1][i-1]*sum[i]%mo)%mo;
	printf("%d",ans);
	return 0;
}