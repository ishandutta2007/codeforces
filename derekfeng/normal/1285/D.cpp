#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,cnt;
vector<ll>v[4000004];
ll a[100004]; 
ll dfs(int x,int depth){
	if (depth<0)
		return 0;
	bool doubleok=0;
	for (int i=1;i<v[x].size();i++){
		if ((v[x][i]&(1<<depth))!=(v[x][i-1]&(1<<depth))) doubleok=1;
	}
	if (!doubleok)
		return dfs(x,depth-1);
	for (int i=0;i<v[x].size();i++){
		if (v[x][i]&(1<<depth)) v[cnt+1].push_back(v[x][i]);
		else v[cnt+2].push_back(v[x][i]);  
	}
	int m1=cnt+1,m2=cnt+2;
	cnt+=2;
	return (1<<depth)+min(dfs(m1,depth-1),dfs(m2,depth-1));
}
int main(){
	cin>>n;cnt=1;
	for (int i=1;i<=n;i++)cin>>a[i],v[1].push_back(a[i]);
	cout<<dfs(1,30);
}