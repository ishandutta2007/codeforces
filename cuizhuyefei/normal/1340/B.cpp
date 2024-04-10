#include<bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define L(i,u) for (register int i=head[u]; i; i=nxt[i])
#define rep(i,a,b) for (register int i=(a); i<=(b); i++)
#define per(i,a,b) for (register int i=(a); i>=(b); i--)
using namespace std;
typedef long double ld;
typedef long long ll;
typedef unsigned int ui;
typedef pair<int,int> Pii;
typedef pair<ll,ll> Pll;
typedef vector<int> Vi;
template<class T> inline void read(T &x){
	x=0; char c=getchar(); int f=1;
	while (!isdigit(c)) {if (c=='-') f=-1; c=getchar();}
	while (isdigit(c)) {x=x*10+c-'0'; c=getchar();} x*=f;
}
template<class T> T gcd(T a, T b){return !b?a:gcd(b,a%b);}
template<class T> inline void umin(T &x, T y){x=x<y?x:y;}
template<class T> inline void umax(T &x, T y){x=x>y?x:y;}
mt19937 R(chrono::system_clock().now().time_since_epoch().count());

const int N = 2666;
map<string,int>Map;
int n,k,g[N][11];bool dp[N][N];
int main() {
	Map["1110111"]=0;
	Map["0010010"]=1;
	Map["1011101"]=2;
	Map["1011011"]=3;
	Map["0111010"]=4;
	Map["1101011"]=5;
	Map["1101111"]=6;
	Map["1010010"]=7;
	Map["1111111"]=8;
	Map["1111011"]=9;
	read(n);read(k);
	memset(g,-1,sizeof(g));
//	memset(dp,-1,sizeof(dp));
	rep(i,1,n){
		string s;cin>>s;
		rep(j,0,(1<<7)-1){
			bool ok=1;string t=s;int cnt=0;
			rep(k,0,6)if(j>>k&1){
				ok&=t[k]=='0';t[k]='1';
				cnt++;
			}
			if(ok&&Map.count(t))umax(g[i][cnt],Map[t]);
		}
	}
	dp[n+1][0]=1;
	per(i,n,1)rep(j,0,k)if(dp[i+1][j]){
		rep(c,0,7)dp[i][j+c]|=g[i][c]>=0;
	}
	if(!dp[1][k]){puts("-1");return 0;}
	rep(i,1,n){
		int a=-1;
		rep(j,0,7)if(g[i][j]>=0&&j<=k&&dp[i+1][k-j]&&(a==-1||g[i][j]>g[i][a]))a=j;
		putchar('0'+g[i][a]);k-=a;
	}
	return 0;
}