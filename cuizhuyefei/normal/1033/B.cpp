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
inline void read(ll &x) {
	x=0; char c=getchar(); int f=1;
	while (!isdigit(c)) {if (c=='-') f=-1; c=getchar();}
	while (isdigit(c)) {x=x*10+c-'0'; c=getchar();} x*=f;
}
inline ui R() {
	static ui seed=416;
	return seed^=seed>>5,seed^=seed<<17,seed^=seed>>13;
}
const int N =23 ;

int main() {
	ll T;read(T);
	while(T--){
		ll a,b;read(a);read(b);
		if(a-b>1){puts("NO");continue;}
		else{
			bool bo=1;
			for(ll i=2;i*i<=b+a;i++)if((b+a)%i==0)bo=0;
			printf("%s\n",bo?"YES":"NO");
		}
	}
	
	
	return 0;
}