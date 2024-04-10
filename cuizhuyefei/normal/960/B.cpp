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
const int N = 233333;
int n,a[N],k;
priority_queue<int> heap;
int main() {
	read(n); read(k); int k2; read(k2); k+=k2;
	rep(i,1,n) read(a[i]);
	rep(i,1,n) {int x; read(x); a[i]-=x; a[i]=a[i]>0?a[i]:-a[i]; heap.push(a[i]);}
	while (k--) {
		int u=heap.top(); heap.pop();
		int x=u>=1?u-1:1; heap.push(x);
	}
	ll ans=0;
	while (!heap.empty()) {ans+=1LL*heap.top()*heap.top(); heap.pop();}
	cout<<ans;
	return 0;
}