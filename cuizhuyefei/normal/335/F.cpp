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
typedef vector<ll> Vl;
template<class T> inline void read(T &x){
	x=0; char c=getchar(); int f=1;
	while (!isdigit(c)) {if (c=='-') f=-1; c=getchar();}
	while (isdigit(c)) {x=x*10+c-'0'; c=getchar();} x*=f;
}
template<class T> T gcd(T a, T b){return !b?a:gcd(b,a%b);}
template<class T> inline void umin(T &x, T y){x=x<y?x:y;}
template<class T> inline void umax(T &x, T y){x=x>y?x:y;}
inline ui R() {
	static ui seed=416;
	return seed^=seed>>5,seed^=seed<<17,seed^=seed>>13;
}
const int N = 505000;
int n;map<int,int>Map;Pii s[N];int len;ll res;
priority_queue<ll,vector<ll>,greater<ll> >heap;
int main() {
	read(n);rep(i,1,n){int x;read(x);Map[x]++;res+=x;}
	for(auto i:Map)s[++len]=Pii(i.fi,i.se);
	int sum=0;
	per(j,len,1){
		int c=min(s[j].se,sum-2*SZ(heap));
		Vl cur(c,s[j].fi);c=s[j].se-c;
		for(int i=1;i<=c;i+=2)if(!heap.empty()){
			ll t=heap.top();heap.pop();
			if(t<s[j].fi){
				cur.pb(s[j].fi);
				if(i<c)cur.pb(s[j].fi);
			}
			else{
				cur.pb(t);if(t<2*s[j].fi&&i<c)cur.pb(2*s[j].fi-t);
			}
		}
		for(auto i:cur)heap.push(i);sum+=s[j].se;
	//	printf("sz=%d %d %d\n",SZ(heap),s[j].fi,s[j].se);
	}
	while(!heap.empty())res-=heap.top(),heap.pop();cout<<res;//printf("%lld\n",heap.top()),
	return 0;
}