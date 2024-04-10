// Problem: CF441C Valera and Tubes
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/CF441C
// Memory Limit: 250 MB
// Time Limit: 1000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m,k;vector<pair<int,int>>p;
signed main(){
	cin>>n>>m>>k;
	for(int i=1;i<=n;i++){
		if(i&1)for(int j=1;j<=m;j++)p.push_back({i,j});
		else   for(int j=m;j>=1;j--)p.push_back({i,j});
	}
	while(k--){
		if(k==0){
			printf("%d ",p.size());
			for(auto [x,y]:p)
				printf("%d %d ",x,y);
		}else{
			printf("2 ");
			printf("%d %d ",p.back().first,p.back().second);p.pop_back();
			printf("%d %d ",p.back().first,p.back().second);p.pop_back();
			puts("");
		}
	}
}