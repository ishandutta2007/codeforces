#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
using namespace std;
const int MAXN=1e5+10,LIM=2e6+10;
int a[MAXN],last[MAXN][25],vis[LIM],n,cnt;
vector<int>pos[MAXN];
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		if(a[i]==0 && !vis[0]){
			vis[0]=1;cnt++;
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=0;j<20;j++){
			last[i][j]=last[i-1][j];
			if(a[i] & (1<<j))last[i][j]=i;
			if(last[i][j]){
				pos[i].push_back(last[i][j]);
			}
		}
		sort(pos[i].begin(),pos[i].end());
	}
	for(int i=1;i<=n;i++){
		int sz=pos[i].size();
		int sum=a[i];
		for(int j=sz-1;j>=0;j--){
			int d=pos[i][j];
			sum |= a[d];
			if(!vis[sum])cnt++;

			vis[sum]=1;
		}
	}
	printf("%d",cnt);
	return 0;
}