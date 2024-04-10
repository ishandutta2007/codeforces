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
 
const int N = 2e6+11;
int n,p[N];char s[N],a[N];
void manacher(int n, char *s){
	rep(i,0,n)p[i]=0;
	for(int i=1,id=0;i<=n;i++){
		if(id+p[id]>i)p[i]=min(id+p[id]-i,p[2*id-i]);
		while(i+p[i]<=n&&i-p[i]>=1&&s[i+p[i]]==s[i-p[i]])p[i]++;
		if(i+p[i]>id+p[id])id=i;
	}
}
bool ck(int l, int r){
	return p[l+r-1]+l+r-1-1>=2*r-1;
}
int main() {
//	ios::sync_with_stdio(0);cin.tie(0);
	int t;scanf("%d",&t);while(t--){
		scanf("%s",s+1);n=strlen(s+1);
		rep(i,1,n)a[2*i-1]=s[i],a[2*i]='#';
		manacher(2*n-1,a);
		int l=0;
		while(2*(l+1)<=n&&s[l+1]==s[n-l])l++;
		per(d,n-2*l,0){
			if(!d||ck(l+1,l+d)){
				rep(i,1,l+d)putchar(s[i]);
				rep(i,n-l+1,n)putchar(s[i]);
				puts("");
				break;
			}
			if(ck(n-l-d+1,n-l)){
				rep(i,1,l)putchar(s[i]);
				rep(i,n-l-d+1,n)putchar(s[i]);
				puts("");
				break;
			}
		}
	}
	return 0;
}