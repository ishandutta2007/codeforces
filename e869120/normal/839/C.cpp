#include<bits/stdc++.h>
using namespace std;
int n,a,b;vector<int>x[100009];bool used[100009];
long double dfs(int pos){
	used[pos]=true;
	long double sum=0,cnt=0;
	for(int i=0;i<x[pos].size();i++){
		if(used[x[pos][i]]==true)continue;
		sum+=dfs(x[pos][i]);sum+=1.0L;cnt++;
	}
	if(cnt==0)return 0;
	return sum/cnt;
}
int main(){
	cin>>n;
	for(int i=0;i<n-1;i++){cin>>a>>b;x[a].push_back(b);x[b].push_back(a);}
	printf("%.12Lf\n",dfs(1));
	return 0;
}