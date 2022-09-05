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
ll n,m;
ll f(ll x){return x%2?x-1:x;}
ll getans(ll n, ll m){
	if(n>m)swap(n,m);//n<=m
	if(n>=3&&m>=3)return f(1LL*n*m);
	if(n==2){
		if(m==1)return 0;
		if(m==2)return 0;
		if(m==3)return 4;
		if(m==7)return 12;
		return f(1LL*n*m);
	}
	if(m<=3)return 0;
	if(m==4)return 2;
	if(m==5)return 4;
	if(m%6<=3)return m/6*6;
	if(m%6==4)return m-2;
	return m-1;
}
int main() {
	read(n);read(m);cout<<getans(n,m);
	return 0;
}