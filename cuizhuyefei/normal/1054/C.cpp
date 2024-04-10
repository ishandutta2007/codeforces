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
const int N = 2333;
int n,l[N],r[N],a[N],s[N];
void GG(){puts("NO");exit(0);}
int main() {
	read(n);rep(i,1,n)read(l[i]);rep(i,1,n)read(r[i]);
	rep(i,1,n)a[i]=n-(l[i]+r[i]);
	rep(i,1,n){
		int p=0;rep(j,1,i-1)p+=a[j]>a[i];if(p!=l[i])GG();
		p=0;rep(j,i+1,n)p+=a[j]>a[i];if(p!=r[i])GG();
	}
	puts("YES");rep(i,1,n)printf("%d ",a[i]);
	return 0;
}