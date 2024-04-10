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
inline void read(int &x) {
	x=0; char c=getchar(); int f=1;
	while (!isdigit(c)) {if (c=='-') f=-1; c=getchar();}
	while (isdigit(c)) {x=x*10+c-'0'; c=getchar();} x*=f;
}
inline ui R() {
	static ui seed=416;
	return seed^=seed>>5,seed^=seed<<17,seed^=seed>>13;
}
const int N = 123333;
int n;ll res,a[N],cntw,cntg;bool w,g;char t[N];
int main() {
	read(n);rep(i,1,n)scanf("%lld",&a[i]),a[i]*=2,res+=a[i];
	scanf("%s",t+1);
	rep(i,1,n){
		//now+=a[i];ll mn=min(now,cntw);cntw-=mn;
		w|=t[i]=='W';if(t[i]=='W')cntw+=a[i];
		g|=t[i]=='G';if(t[i]=='G')cntg+=a[i];
		ll v=a[i];ll mn=min(v/2,cntw);v-=mn*2;cntw-=mn;res+=2*mn;
		mn=min(v/2,cntg);v-=mn*2;cntg-=mn;res+=4*mn;
		if(w)res+=3*v;else res+=5*v;
	}
	cout<<res/2;return 0;
}
//W2 G4 L