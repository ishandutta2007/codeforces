#include<bits/stdc++.h>
using namespace std;
int main(){
	int g[5][5],a[5]={0,1,2,3,4},ans=0;
	for(int i=0;i<5;i++)for(int j=0;j<5;j++)cin>>g[i][j];
	do
		ans=max(ans,g[a[0]][a[1]]+g[a[2]][a[3]]+g[a[1]][a[2]]+g[a[3]][a[4]]+g[a[2]][a[3]]+g[a[3]][a[4]]+
		g[a[1]][a[0]]+g[a[3]][a[2]]+g[a[2]][a[1]]+g[a[4]][a[3]]+g[a[3]][a[2]]+g[a[4]][a[3]]);
	while(next_permutation(a,a+5));
	cout<<ans;
}
//1 2 3 4 5