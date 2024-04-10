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
const int N = 5555,mo=1e9+7;
int n,m,s[N],buc[N];
Pii a[N];int zuo[N],you[N];
int main() {
	read(n);read(m);
	rep(i,1,n)read(s[i]),buc[s[i]]++;
	int sz=0;rep(i,1,m){
		int x,y;read(x);read(y);
		if(buc[x]>=y)a[++sz]=Pii(x,y);
	}
	sort(a+1,a+sz+1);Pii res(0,0);
	rep(i,1,sz){
		int x=a[i].se;
		while(x)zuo[i]++,x-=s[zuo[i]]==a[i].fi;
		x=a[i].se;you[i]=n+1;
		while(x)you[i]--,x-=s[you[i]]==a[i].fi;
	}
	rep(x,0,sz){
		int ans1=0,ans2=1;
		rep(i,1,sz){
			int j=i;while(j+1<=sz&&a[j+1].fi==a[i].fi)j++;
			int A=0,b=0,c=0;
			rep(k,i,j)if(k!=x){
				bool z=zuo[k]<zuo[x],y=you[k]>zuo[x];
				if(z&&y)c++;
				else if(z)A++;
				else if(y)b++;
			}
			if(a[i].fi==a[x].fi){
				if(b+c)ans1+=2,ans2=1ll*ans2*(b+c)%mo;
				else ans1++;
			}
			else{
				if(A*(b+c)+c*(c-1+b))ans1+=2,ans2=1ll*(A*(b+c)+c*(c-1+b))%mo*ans2%mo;
				else if(A+c+b+c)ans1++,ans2=1ll*ans2*(A+c+b+c)%mo;
			}
			i=j;
		}
	//	printf("%d:%d %d\n",x,ans1,ans2);
		if(ans1>res.fi)res=Pii(ans1,ans2);
		else if(ans1==res.fi)res.se=(res.se+ans2)%mo;
	}
	printf("%d %d",res.fi,res.se);
	return 0;
}