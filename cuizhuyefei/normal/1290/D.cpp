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
typedef vector<int> Vi;
template<class T> inline void read(T &x){
	x=0; char c=getchar(); int f=1;
	while (!isdigit(c)) {if (c=='-') f=-1; c=getchar();}
	while (isdigit(c)) {x=x*10+c-'0'; c=getchar();} x*=f;
}
template<class T> T gcd(T a, T b){return !b?a:gcd(b,a%b);}
template<class T> inline void umin(T &x, T y){x=x<y?x:y;}
template<class T> inline void umax(T &x, T y){x=x>y?x:y;}
inline ui R() {
	static ui seed=613;
	return seed^=seed>>5,seed^=seed<<17,seed^=seed>>13;
}
const int N = 1<<16|3;
int n,k,gg[N];
int yzr(int x){
	printf("? %d\n",x);fflush(stdout);
	char S[66];scanf("%s",S);
	return S[0]=='Y';
}
int main() {
	read(n);read(k);
	if(k==1){
		rep(i,1,n)rep(j,i+1,n){
			yzr(i);yzr(i);gg[j]|=yzr(j);
		}
		int res=0;rep(i,1,n)res+=!gg[i];
		printf("! %d\n",res);fflush(stdout);
		return 0;
	}
	k/=2;int cnt=n/k;
	rep(d,1,cnt-1)rep(s,1,d)if(s+d<=cnt){
		puts("R");fflush(stdout);
		for(int i=s;i<=cnt;i+=d)rep(j,(i-1)*k+1,(i-1)*k+k){
			gg[j]|=yzr(j);
		}
	}
	int res=0;rep(i,1,n)res+=!gg[i];
	printf("! %d\n",res);fflush(stdout);
	return 0;
}