#include<bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
#define SZ(x) ((int)x.size())
#define L(i,u) for (register int i=head[u]; i; i=nxt[i])
#define rep(i,a,b) for (register int i=(a); i<=(b); i++)
#define per(i,a,b) for (register int i=(a); i>=(b); i--)
using namespace std;
typedef long long ll;
typedef unsigned int ui;
typedef pair<int,int> Pii;
typedef vector<int> Vi;
template<class T> inline void read(T &x){
	x=0; char c=getchar(); int f=1;
	while (!isdigit(c)) {if (c=='-') f=-1; c=getchar();}
	while (isdigit(c)) {x=x*10+c-'0'; c=getchar();} x*=f;
}
template<class T> inline void umin(T &x, T y){x=x<y?x:y;}
template<class T> inline void umax(T &x, T y){x=x>y?x:y;}
inline ui R() {
	static ui seed=416;
	return seed^=seed>>5,seed^=seed<<17,seed^=seed>>13;
}
const int N = 233333;
int n,b[N],cnt[N],res;char S[N];
int gcd(int a, int b){return !b?a:gcd(b,a%b);}
bool ck(int k){
	rep(i,0,k-1){
		int s=0;for(int j=i;j<n;j+=k)s^=b[j];
		if(s)return 0;
	}
	return 1;
}
int main() {
	read(n);scanf("%s",S);
	rep(i,0,n-1)b[i]=S[i]-'0';
	rep(i,0,n-1)cnt[gcd(i,n)]++;
	rep(k,1,n)if(cnt[k])res+=cnt[k]*ck(k);
	cout<<res;
	return 0;
}