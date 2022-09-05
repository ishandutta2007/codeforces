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
const int N = 2333, mo = 1e9+7;
int n,p[N]; ll qz[N],f[N],ans;
int main() {
	read(n); rep(i,1,n) read(p[i]);
	f[1]=2;qz[1]=2;
	rep(i,2,n) {
		f[i]=2+qz[i-1]-qz[p[i]-1]+mo; f[i]%=mo;
		qz[i]=(qz[i-1]+f[i])%mo;
	}
	ans=qz[n];
	cout<<(ans%mo+mo)%mo;
	return 0;
}