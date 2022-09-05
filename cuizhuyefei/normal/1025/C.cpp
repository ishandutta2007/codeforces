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
int n,f[N],res;char s[N];
int main() {
	scanf("%s",s+1);n=strlen(s+1);f[1]=1;res=max(res,1);
	rep(i,2,n){
		f[i]=1+(s[i]!=s[i-1]?f[i-1]:0);res=max(res,f[i]);
	}
	if(s[1]!=s[n]){
		int a=f[n],b=1;
		for(;b<=n-a;b++)if(s[b]==s[b-1])break;b--;
		res=max(res,a+b);
	}
	cout<<res;
	return 0;
}