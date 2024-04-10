#include<cstdio>
#include<cstring>
#include<vector>
#include<queue>
#include<set>
#include<map>
#include<cstdlib>
#include<iostream>
#include<algorithm>
#define fi first
#define se second
#define L(i,u) for (int i=head[u]; i!=0; i=nxt[i])
#define rep(i,a,b) for (register int i=a; i<=b; i++)
#define per(i,a,b) for (register int i=a; i>=b; i--)
typedef long long ll;
using namespace std;
typedef pair<int,int> Pii;
typedef vector<int> Vi;
inline void read(int &x) {
	x=0; char c=getchar(); int f=1;
	while (!isdigit(c)) {if (c=='-') f=-1; c=getchar();}
	while (isdigit(c)) {x=x*10+c-'0'; c=getchar();} x*=f;
}
int a[1020][1202];
int n,m,mo,k;
int power(int a, int n) {
	int res=1;
	while (n) {
		if (n&1) res=1LL*res*a%mo;
		a=1LL*a*a%mo;
		n>>=1;
	}
	return res;
}
int getcnt(int m) {
	int res=0;
	rep(i,1,n) res+=a[i][m]==0;
	return res;
}
int main() { bool flag=0;
	read(n); read(m); read(k); int x,y,z; if (n>m) {swap(n,m); flag=1;}
	rep(i,1,k) {read(x); read(y); if (flag) swap(x,y); read(a[x][y]);}
	read(mo);
	if ((n-m)%2!=0) puts("0");
	else {
		int p=0,ans=0; rep(i,1,m) if (n==getcnt(i)) {p=i; break;}
		rep(i,1,m) if (i!=p) {
			int x=getcnt(i); if (x>0) ans+=x-1;
			if (x==0) {
				int res=1; rep(j,1,n) res*=a[j][i]; 
				if (res==1) {puts("0");return 0;}
			}
		}
		printf("%d",power(2,ans));
	}
	return 0;
}