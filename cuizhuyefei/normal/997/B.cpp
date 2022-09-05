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
const int N = 2333333;
bool ok[N];int n;
int f(int n) {
	memset(ok,0,4*(50*n+2));
	rep(a,0,n)rep(b,0,n-a)rep(c,0,n-a-b)rep(d,n-a-b-c,n-a-b-c)ok[a+b*5+c*10+d*50]=1;
	int res=0;rep(i,0,50*n)res+=ok[i];return res;
//	rep(i,1,min(50*n,1000))printf("%d:%d\n",i,ok[i]);
}
int main() {
	read(n);
	if(n<=15)cout<<f(n);
	else cout<<488+49LL*(n-15);
	return 0;
}