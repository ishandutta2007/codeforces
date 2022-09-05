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
int n,a[N],b[N];
void ck(int x){
	rep(i,1,n)if(a[i]%x!=0&&b[i]%x!=0)return;
	printf("%d",x);exit(0);
}
int main() {
	read(n);rep(i,1,n)read(a[i]),read(b[i]);
	for(int i=2;i*i<=a[1];i++)if(a[1]%i==0){ck(i);while(a[1]%i==0)a[1]/=i;}
	for(int i=2;i*i<=b[1];i++)if(b[1]%i==0){ck(i);while(b[1]%i==0)b[1]/=i;}
	if(a[1]>1)ck(a[1]);if(b[1]>1)ck(b[1]);
	puts("-1");
	return 0;
}