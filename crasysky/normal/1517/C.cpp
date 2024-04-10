#include <bits/stdc++.h>
#define rep0(i,r) for (int i=0,i##end=r;i<i##end;++i)
#define rep(i,l,r) for (int i=l;i<=r;++i)
#define per(i,r,l) for (int i=r;i>=l;--i)
#define pr pair<int,int>
#define mp make_pair
#define fi first
#define se second
#define vit vector<int>::iterator
#define sit set<pr>::iterator
#define pb push_back
#define ll long long
using namespace std;
const int N=1e3+3; int n,a[N],ans[N][N],c;
void solve(int x,int y,int v){
	ans[x][y]=v; if ((--c)==0) return;
	if (y-1>=1&&!ans[x][y-1]) solve(x,y-1,v);
	if (c&&x+1<=n) solve(x+1,y,v);
}
int main(){
	scanf("%d",&n);
	rep(i,1,n) scanf("%d",&a[i]);
	rep(i,1,n) c=a[i],solve(i,i,a[i]);
	rep(i,1,n){
		rep(j,1,i) printf("%d ",ans[i][j]);
		putchar('\n');
	}
	return 0;
}