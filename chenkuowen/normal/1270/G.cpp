#include<bits/stdc++.h>
using namespace std;
const int MAX_N=5+1e6;
bool vis[MAX_N];
int a[MAX_N];
vector<int> ans;
int stk[MAX_N],top_stk=0;
void dfs(int x){
	if(vis[x]){
		ans.clear();
		while(stk[top_stk+1]!=x)
			ans.push_back(stk[top_stk--]);
		printf("%d\n",(int)ans.size());
		for(auto x:ans) printf("%d ",x);
		puts("");
		return;
	}
	vis[x]=1; stk[++top_stk]=x;
	dfs(x-a[x]);
}
int main(){
	int T; scanf("%d",&T);
	while(T--){
		top_stk=0;
		int n; scanf("%d",&n);
		memset(vis,0,sizeof(bool)*(n+1));
		memset(stk,0,sizeof(int)*(n+2));
		for(int i=1;i<=n;++i) scanf("%d",&a[i]);
		dfs(1);
	}
	return 0;
}