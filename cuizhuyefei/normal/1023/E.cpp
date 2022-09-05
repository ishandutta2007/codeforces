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
char s[N];int n,x,y;
int ask(int a, int b, int c, int d){
	printf("? %d %d %d %d\n",a,b,c,d);
	fflush(stdout);char t[6];scanf("%s",t);
	return t[0]=='Y';
}
int main() {
	read(n);
	for(x=1,y=n;;x++,y--){if(ask(1,1,x,y)&&ask(x,y,n,n))break;}
	int p=1,a=1,b=1;
	while(p<=n-1){
		if(b+1<=y&&ask(a,b+1,n,n))b++,s[p++]='R';
		else a++,s[p++]='D';
	}
	p=2*n-2;a=n;b=n;
	while(p>=n){
		if(a-1>=x&&ask(1,1,a-1,b))a--,s[p--]='D';
		else b--,s[p--]='R';
	}
	printf("! ");rep(i,1,2*n-2)printf("%c",s[i]);fflush(stdout);
	return 0;
}