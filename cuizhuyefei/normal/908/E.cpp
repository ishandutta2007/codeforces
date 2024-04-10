#include<cstdio>
#include<cstring>
#include<vector>
#include<map>
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
const int N = 2002, mo = 1e9+7;
int n,m,a[55][N];
char s[N];
map<ll,int> S;
ll B[N],C[N][N];
int main() {
	read(n); read(m);
	rep(i,0,n) {
		C[i][0]=C[i][i]=1;
		rep(j,1,i-1) C[i][j]=(C[i-1][j-1]+C[i-1][j])%mo;
	}
	B[0]=1; rep(i,1,n) {rep(j,0,i-1) B[i]+=B[j]*C[i-1][j]%mo; B[i]%=mo;}
	rep(i,1,m) {
		scanf("%s",s+1);
		rep(j,1,n) a[i][j]=s[j]-'0';
	}
	rep(j,1,n) {ll res=0; rep(i,1,m) res+=(1ll*a[i][j])<<i; S[res]++;}
	ll ans=1;
	while (!S.empty()) {
		int x=(*S.begin()).se; S.erase(S.begin());
		ans=ans*B[x]%mo;
	}
	printf("%lld",ans);
	return 0;
}