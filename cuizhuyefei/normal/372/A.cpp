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
int n,a[800008]; set<int> Set;
int ck(int k) {
	rep(i,1,k) if (a[i]*2>a[i+n-k]) return 0;
	return 1;
}
int main() {
	read(n); rep(i,1,n) {read(a[i]);} sort(a+1,a+n+1);
	int ans=n;
	/*while (!Set.empty()) {
		int v=*Set.begin(); Set.erase(Set.begin());
		set<int> ::iterator it=Set.lower_bound(v*2);
		if (it!=Set.end()) {ans--; Set.erase(it);}
	}*/
	int l=1,r=n/2;
	while (l<=r) {
		int mid=(l+r)>>1;
		if (ck(mid)) ans=n-mid,l=mid+1; else r=mid-1;
	}
	cout<<ans;
	return 0;
}