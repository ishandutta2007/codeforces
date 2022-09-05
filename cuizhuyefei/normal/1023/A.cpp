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
int n,m;char s[N],t[N];
void GG(){puts("NO");exit(0);}
int main() {
	read(n);read(m);scanf("%s%s",s+1,t+1);
	int p=0;rep(i,1,n)if(s[i]=='*')p=i;
	if(p){
		if(n-1>m)GG();
		rep(i,1,p-1)if(s[i]!=t[i])GG();
		rep(i,p+1,n)if(s[i]!=t[m-(n-i)])GG();
		puts("YES");
	}
	else{
		if(n!=m)GG();
		rep(i,1,n)if(s[i]!=t[i])GG();
		puts("YES");
	}
	return 0;
}