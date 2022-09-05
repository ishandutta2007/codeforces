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
const int N = 500000;
int n,k,a[N],cnt;
int main() {
	read(n); read(k);
	rep(i,1,k) {
		int l; read(l); rep(j,1,l) read(a[j]);
		if (a[1]==1) {rep(j,1,l) if (a[j]==j) cnt=j-1; else break;}
	}
	printf("%d",n-1+n-k-2*cnt);
	return 0;
}