#include<bits/stdc++.h>
using namespace std;
const int MAXN = 100005;
vector<int> E[MAXN];
int deep[MAXN];
void dfs(int node,int father){
	for (int des :E[node]){
		if (des==father){
			continue;
		}
		deep[des] = deep[node]+1;
		dfs(des,node);
	}
}
double solve(int node,int father){
	double ans =0;
	int cnt=0;
	for (int des :E[node]){
		if (des==father){
			continue;
		}
		cnt++;
		ans+=solve(des,node);
	}
	if (node!=1&&E[node].size()==1){
		return 1.0*deep[node];
	}else{
		return ans/cnt;
	}
}
int n;
int main(){
	scanf("%d",&n);
	if(n==1){
		printf("0.000000000\n");
		return 0;
	}
	for (int i=0;i<n-1;i++){
		int u,v;
		scanf("%d%d",&u,&v);
		E[u].push_back(v);
		E[v].push_back(u);
	}
	memset(deep,0,sizeof deep);
	dfs(1,0);
	long long sum =0;
	long long cnt =0;
	printf("%.9f\n",solve(1,0));
	return 0;
}