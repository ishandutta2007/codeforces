#include<bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
#define SZ(x) ((int)x.size())
#define L(i,u) for (register int i=head[u]; i; i=nxt[i])
#define rep(i,a,b) for (register int i=a; i<=b; i++)
#define per(i,a,b) for (register int i=a; i>=b; i--)
using namespace std;
typedef long long ll;
typedef unsigned int ui;
typedef pair<int,int> Pii;
typedef vector<int> Vi;
inline void read(int &x) {
	x=0; char c=getchar(); int f=1;
	while (!isdigit(c)) {if (c=='-') f=-1; c=getchar();}
	while (isdigit(c)) {x=x*10+c-'0'; c=getchar();} x*=f;
}
inline ui R() {
	static ui seed=416;
	return seed^=seed>>5,seed^=seed<<17,seed^=seed>>13;
}
const int N = 32;
ll n,k,l=1,r=1e18;
bool ask(ll a, ll b){
	printf("%lld %lld\n",a,b);fflush(stdout);
	char s[6];scanf("%s",s);return s[0]=='Y';
}
int main() {
	scanf("%lld%lld",&n,&k);l=1;r=n;srand(time(0));
	while(1){
		if(r-l>=4*k+3){
			ll mid=(l+r)/2;
			if(ask(l,mid))r=mid;else l=mid+1;
			l=max(1LL,l-k);r=min(n,r+k);
		}
		else{
			ll p=l+rand()%(r-l+1);
			bool res=ask(p,p);if(res){exit(0);}
			l=max(1LL,l-k);r=min(n,r+k);
		}
	}
	return 0;
}