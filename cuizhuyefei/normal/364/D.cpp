#include<cstdio>
#include<cstring>
#include<vector>
#include<queue>
#include<set>
#include<ctime>
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
typedef unsigned int ui;
typedef pair<int,int> Pii;
typedef vector<int> Vi;
inline void read(ll &x) {
	x=0; char c=getchar(); int f=1;
	while (!isdigit(c)) {if (c=='-') f=-1; c=getchar();}
	while (isdigit(c)) {x=x*10+c-'0'; c=getchar();} x*=f;
}
const int N = 1020000;
ll n,a[N],s[N],cnt[N];
inline ll gcd(ll a, ll b) {return !b?a:gcd(b,a%b);}
inline ui R() {
	static ui seed=time(0);
	return seed^=seed<<13,seed^=seed>>7,seed^=seed<<17;
}
int main() {
	read(n); rep(i,1,n) read(a[i]); ll ans=1;
	while (clock()<=3.1*CLOCKS_PER_SEC) {
		int p=R()%n+1,len=0;
		for (int i=1; 1LL*i*i<=a[p]; i++) if (a[p]%i==0) {
			s[++len]=i; if (1LL*i*i!=a[p]) s[++len]=a[p]/i;
		}
		sort(s+1,s+len+1); rep(i,1,len) cnt[i]=0;
		rep(i,1,n) cnt[lower_bound(s+1,s+len+1,gcd(a[p],a[i]))-s]++;
		rep(i,1,len) {
			int tot=0; rep(j,i,len) if (s[j]%s[i]==0) tot+=cnt[j];
		//	printf("%d : %d\n",s[i],tot);
			if (tot*2>=n) ans=max(ans,s[i]);
		}
	}
	cout<<ans;
	return 0;
}