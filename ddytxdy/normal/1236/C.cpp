#include<bits/stdc++.h>
using namespace std;
const int N=310;
int n;
vector<int>v[N];
int main(){
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		if(i&1)for(int j=1;j<=n;j++)v[j].push_back(i*n+j);
		else for(int j=n;j;j--)v[j].push_back(i*n+(n-j+1));
	}
	for(int i=1;i<=n;i++){
		for(int j=0;j<n;j++)printf("%d ",v[i][j]);
		puts("");
	}
	return 0;
}