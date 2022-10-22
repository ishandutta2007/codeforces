#include<bits/stdc++.h>
using namespace std;
int n,m,q;
vector<vector<char> >c;
int dis[1000005];
int main(){
	cin>>n>>m;
	c.resize(n+1);
	for(int i=1;i<=n;i++)c[i].resize(m+1);
	for(int i=1;i<=n;i++)for(int j=1;j<=m;j++)cin>>c[i][j];
	for(int i=2;i<=m;i++){
		int d=0;
		for(int j=2;j<=n;j++)
			if(c[j][i-1]=='X'&&c[j-1][i]=='X')d=1;
		dis[i]=dis[i-1]+d;
	}
	cin>>q;
	while(q--){
		int x,y;
		cin>>x>>y;
		if(dis[y]-dis[x]>0)puts("NO");
		else puts("YES");
	}
}