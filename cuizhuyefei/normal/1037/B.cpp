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
const int N = 666666;
int n,s,a[N];
int main() {
	read(n);read(s);rep(i,1,n)read(a[i]),a[i]-=s;sort(a+1,a+n+1);
	int mid=(n+1)/2;int mx=0,mn=0;ll res=a[mid]>0?a[mid]:-a[mid];
	rep(i,mid+1,n){res+=a[i]>mx?0:mx-a[i];mx=max(mx,a[i]);}
	per(i,mid-1,1){res+=a[i]<mn?0:a[i]-mn;;mn=min(mn,a[i]);}
	cout<<res;
	return 0;
}