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
const int N = 1020000;
int v[N],p[N],n;
void add(int p) {while (p<=n) v[p]++,p+=p&-p;}
int que(int p) {int res=0; while (p) res+=v[p],p-=p&-p; return res;}
int main() {
	read(n);rep(i,1,n)read(p[i]);ll res=0;
	per(i,n,1){res+=que(p[i]); add(p[i]);}
	if ((n&1)^(res&1)) puts("Um_nik");
	else puts("Petr");
	return 0;
}