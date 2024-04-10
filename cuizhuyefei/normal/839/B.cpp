#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<queue>
#include<vector>
#define fi first
#define se second
#define pb push_back
#define max(a,b) ((a)>(b)?(a):(b))
#define min(a,b) ((a)<(b)?(a):(b))
#define rep(i,a,b) for (int i=a; i<=b; i++)
#define per(i,a,b) for (int i=a; i>=b; i--)
#define L(i,u) for (int i=head[u]; i!=0; i=edge[i].nxt)
#define abs(a) ((a)>0 ? (a) : -(a))
#define INF 0x3f3f3f3f
using namespace std;
typedef pair<int,int> Pii;
typedef vector<int> Vi;
typedef long long ll;
typedef long double ld;
const int N = 10005;
int n,k,a[N],x; //4*n
int x4,x2,x1;
int a1,a2,a3;
 
 
inline void read(int &x) {
	x=0; char c=getchar(); int f=1;
	while (c<'0'||c>'9') {if (c=='-') f=-1; c=getchar();}
	while (c>='0'&&c<='9') {x=10*x+c-'0'; c=getchar();} x*=f;
}
inline bool judge() {
	int sum=0; x4=n; x2=n+n;
	rep(i,1,k) {
		int x=a[i];
		while (x>=4) {
			if (x4>0) {x4--; x-=4;}
			if (x4==0) break;
		}
		a[i]=x;
		if (!x4) break;
	}
	if (!x4) {
		rep(i,1,k) x2-=(a[i]+1)/2;
		return x2>=0;
	}
	rep(i,1,k) 
		if (a[i]==1) a1++;
		else if (a[i]==2) a2++;
		else if (a[i]==3) a3++;
	int tmp=min(a3,x4); a3-=tmp; x4-=tmp;
	if (x4==0) {
		x2-=(a1+a2+a3*2);
		return x2>=0;
	}
	else {
		tmp=min(a2,x2); x2-=tmp; a2-=tmp;
		tmp=min(a1,x4); a1-=tmp; x4-=tmp; x2+=tmp;
		if (!x4) {
			x2-=(a1+a2); return x2>=0;
		}
		else {
			a2-=x2; a2-=x4; x1=x4;
			a2-=x1/2; return a2<=0;
		}
	}
	return 1;
}
int main() {
	read(n); read(k);
	rep(i,1,k) read(a[i]);
	printf("%s",judge()?"YES":"NO");
	return 0;
}