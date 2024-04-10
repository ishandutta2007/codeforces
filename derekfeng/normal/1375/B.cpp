#include<bits/stdc++.h>
using namespace std;
int dir[4][2]={{0,1},{0,-1},{1,0},{-1,0}};
int n,m,a[303][303];
int T,ans[303][303];
bool ok(int x,int y){
	return !(x<0||y<0||x>=n||y>=m);
}
void solve(){
	cin>>n>>m;
	for(int i=0;i<n;i++)for(int j=0;j<m;j++)cin>>a[i][j];
	for(int i=0;i<n;i++)for(int j=0;j<m;j++){
		ans[i][j]=0;
		for(int k=0;k<4;k++)ans[i][j]+=(ok(i+dir[k][0],j+dir[k][1]));
		if(ans[i][j]<a[i][j]){
			puts("NO");
			return;
		}
	}
	puts("YES");
	for(int i=0;i<n;i++,puts(""))
		for(int j=0;j<m;j++) cout<<ans[i][j]<<" ";
}
int main(){
	cin>>T;
	while(T--)solve();
}