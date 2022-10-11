#include<bits/stdc++.h>
using namespace std;
vector<long long>x[300000],y[300000],vec;
long long n,k,a[300000],dist[300000],dp[300000];
void bfs(){
	for(int i=0;i<300000;i++)dist[i]=999999;
	queue<int>Q;Q.push(1);dist[1]=0;vec.push_back(1);
	while(!Q.empty()){
		int a1=Q.front();Q.pop();
		for(int i=0;i<x[a1].size();i++){
			if(dist[x[a1][i]]==999999){dist[x[a1][i]]=dist[a1]+1;Q.push(x[a1][i]);vec.push_back(x[a1][i]);}
		}
	}
}
int main(){
	cin>>n>>k;long long cnt=0;
	for(int i=0;i<2*k;i++){int b;cin>>b;a[b]=1;}
	for(int i=1;i<n;i++){int c,d;cin>>c>>d;x[c].push_back(d);x[d].push_back(c);}bfs();
	for(int i=1;i<=n;i++){for(int j=0;j<x[i].size();j++){if(dist[i]<dist[x[i][j]])y[i].push_back(x[i][j]);}}
	for(int i=vec.size()-1;i>=0;i--){
		int sum=0;int to=vec[i];if(a[to]==1)sum=1;
		for(int j=0;j<y[to].size();j++){sum+=dp[y[to][j]];}dp[to]=sum;
	}
	for(int i=1;i<=n;i++){
		for(int j=0;j<y[i].size();j++){
			if(dist[i]<dist[y[i][j]])cnt+=min(dp[y[i][j]],2*k-dp[y[i][j]]);
			if(dist[i]>dist[y[i][j]])cnt+=min(dp[i],2*k-dp[i]);
		}
	}
	cout<<cnt<<endl;
	return 0;
}