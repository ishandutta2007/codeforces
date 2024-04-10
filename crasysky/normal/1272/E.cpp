#include <bits/stdc++.h>
#define rep0(i,r) for (int i=0,i##end=r;i<i##end;++i)
#define rep(i,l,r) for (int i=l;i<=r;++i)
#define per(i,r,l) for (int i=r;i>=l;--i)
#define pr pair<int,int>
#define mp make_pair
#define fi first
#define se second
#define ll long long
#define pb push_back
using namespace std;
const int N=1e6+6; 
int a[N],ans[N]; vector<int> G[N]; queue<int> q;
int main(){
	int n; scanf("%d",&n);
	rep(i,1,n) scanf("%d",&a[i]);
	rep(i,1,n){
		int l=i-a[i],r=i+a[i];
		if (1<=l&&l<=n){
			if ((a[l]&1)==(a[i]&1)) G[l].push_back(i);
			else q.push(i),ans[i]=1;
		}
		if (1<=r&&r<=n){
			if ((a[r]&1)==(a[i]&1)) G[r].push_back(i);
			else if (!ans[i]) q.push(i),ans[i]=1;
		}
	}
	rep(i,1,n) if (!ans[i]) ans[i]=-1;
	while (!q.empty()){
		int u=q.front(); q.pop();
		rep0(i,G[u].size()){
			int v=G[u][i];
			if (ans[v]==-1) ans[v]=ans[u]+1,q.push(v);
		}
	}
	rep(i,1,n) printf("%d ",ans[i]);
	return 0;
}