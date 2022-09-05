#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
#define rep(i,a,b) for (int i=a; i<=b; i++)
#define per(i,a,b) for (int i=a; i>=b; i--)
typedef long long ll;
using namespace std;
inline void read(int &x) {
	x=0; char c=getchar(); int f=1;
	while (!isdigit(c)) {if (c=='-') f=-1; c=getchar();}
	while (isdigit(c)) {x=x*10+c-'0'; c=getchar();} x*=f;
}
inline int max(int a, int b) {return a>b ? a : b;}
inline int min(int a, int b) {return a<b ? a : b;}
const int N = 2004;
int n,a[N],f[N][N],ans=1e9;
inline int gcd(int a, int b) {return !b ? a : gcd(b,a%b);}
inline int getans(int p) {
	
}
int main() {
	read(n); rep(i,1,n) read(a[i]); int num=0; rep(i,1,n) num+=(a[i]==1);
	if (num>0) {printf("%d",n-num); return 0;}
	rep(i,1,n) {
		f[i][i-1]=a[i];
		rep(j,i,n) {
			f[i][j]=gcd(f[i][j-1],a[j]);
			if (f[i][j]==1) ans=min(ans,j-i);
		}
	}
	if (f[1][n]>1) {puts("-1"); return 0;}
	printf("%d",n-1+ans);
//	rep(i,1,n) ans=min(ans,getans(i));
	return 0;
}