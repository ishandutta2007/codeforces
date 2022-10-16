#include <iostream>
#include <cstdio> 
#include <algorithm>
#include <cstring>
#include <cmath>
#include <vector>
using namespace std;
int n,m,u[105],v[105],a[15],book[15][15];
int ans;
inline void swp(int &x,int &y){
	int t=x;
	x=y;
	y=t;
	return;
}
inline void check(){
	int s=0;
	memset(book,0,sizeof(book));
	for (int i=1;i<=m;i++){
		int uu=a[u[i]],vv=a[v[i]];
		if (uu>vv)swp(uu,vv);
		if (uu==0)continue;
		if (book[uu][vv]==1)continue;
		s++;
		book[uu][vv]=1;
	}
	ans=max(ans,s);
	return;
}
inline void dfs(int now){
	if (now>n){
		check();
		return;
	}
	a[now]=0;
	dfs(now+1);
	for (int i=1;i<=6;i++)a[now]=i,dfs(now+1);
	return;
}
signed main(){
	cin>>n>>m;
	for (int i=1;i<=m;i++)cin>>u[i]>>v[i];
	dfs(1);
	cout<<ans<<endl;
	return 0;
}