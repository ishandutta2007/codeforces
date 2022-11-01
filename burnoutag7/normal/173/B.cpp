#include<queue>
#include<stack>
#include<map>
#include<set>
#include<cstdio>
#include<vector>
#include<iostream>
#include<string>
#include<algorithm> 
using namespace std;
char a[1005][1005];
int dp[2005];
int main(){
	int n,m;
	cin>>n>>m;
	vector<int> e[2005];
	for(int i=0;i<n;i++){
		cin>>a[i];
		for(int j=0;j<m;j++){
			if(a[i][j]=='#'){
				e[i].push_back(j+n);
				e[j+n].push_back(i);
			}
		}
	}
	queue<int> q;
	dp[n-1]=1;
	q.push(n-1);
	while(q.size()){
		int x=q.front();
		for(int y=0;y<e[x].size();y++){
			if(!dp[e[x][y]]){
				dp[e[x][y]]=dp[x]+1;
				q.push(e[x][y]);
			}
		}
		q.pop();
	}
	cout<<dp[0]-1<<endl;
	return 0;
}