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

const int N = 1e6+11;
int n,a[N],qz[N],hz[N],sta[N],top;
int main() {
	int t;read(t);while(t--){
		read(n);rep(i,1,n)read(a[i]);
		qz[0]=n+1;hz[n+1]=0;bool gg=0;sta[top=1]=a[1];
		rep(i,2,n){
			if(a[i]<sta[top])sta[++top]=a[i];
			else{
				int x=sta[top];
				while(top&&sta[top]<a[i])x=sta[top--];
				sta[++top]=x;
			}
		}
		printf("%s\n",top!=1?"NO":"YES");
	}
	return 0;
}