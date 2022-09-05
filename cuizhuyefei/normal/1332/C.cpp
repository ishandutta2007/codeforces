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

const int N = 1666666;
int n,k;char s[N];
int main() {
	int t;read(t);while(t--){
		read(n);read(k);scanf("%s",s+1);
		int res=n;
		for(int i=1;i<=k-i+1;i++){
			int buc[27]={0};
			for(int x=i;x<=n;x+=k){
				buc[s[x]-'a']++;
				if(i<k-i+1)buc[s[x+k-i+1-i]-'a']++;
			}
			int mx=0;rep(j,0,26)umax(mx,buc[j]);res-=mx;
		}
		printf("%d\n",res);
	}
	return 0;
}