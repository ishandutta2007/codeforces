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
const int N = 23333;
int n,a[N],ans;
priority_queue<int,vector<int>,greater<int> > heap;
int main() {
	read(n); rep(i,1,n) read(a[i]); sort(a+1,a+n+1);
	rep(i,1,n) {
		/*while (!heap.empty()&&heap.top()<=a[i]) {heap.pop(); cnt++;}
		if (cnt) {cnt--;}
		else {heap.push(1);}*/
		if (!heap.empty()&&heap.top()<=a[i]) {
			int u=heap.top(); heap.pop(); heap.push(u+1);
		} else {ans++; heap.push(1);}
	}
	printf("%d",ans);
	return 0;
}