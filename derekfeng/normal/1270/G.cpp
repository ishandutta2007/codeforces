#include <bits/stdc++.h>
using namespace std;
int n,a[1000004],T;
bool vis[1000004];
stack<int>st;
int ret,ans[1000004];
void dfs(int x){
	vis[x]=1;
	st.push(x);
	if(vis[x-a[x]]){
		while(1){
			ans[++ret]=st.top();
			st.pop();
			if(ans[ret]==x-a[x])return;
		}
	}else dfs(x-a[x]);
}
void sol(){
	scanf("%d",&n);
	while(!st.empty())st.pop();
	for(int i=1;i<=n;i++)vis[i]=0,scanf("%d",&a[i]);
	ret=0;
	dfs(1);
	printf("%d\n",ret);
	for(int i=1;i<=ret;i++)printf("%d ",ans[i]);
	puts("");
}
int main(){
	scanf("%d",&T);
	while(T--)sol();
}