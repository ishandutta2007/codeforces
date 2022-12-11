#include<bits/stdc++.h>
#define pb push_back
using namespace std;
const int N=2e5+50;
vector<int>v[N];
int n,c[N],cnt[3];
void dfs(int x){
	for(int i=0;i<v[x].size();i++)
		if(!c[v[x][i]])c[v[x][i]]=3-c[x],dfs(v[x][i]);
}
int main(){
	scanf("%d",&n);
	for(int i=1,x,y;i<n;i++){
		scanf("%d%d",&x,&y);
		v[x].pb(y);v[y].pb(x);
	}
	c[1]=1;dfs(1);
	for(int i=1;i<=n;i++)cnt[c[i]]++;
	cout<<min(cnt[1],cnt[2])-1;
	return 0;
}