#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
#include<vector>
#include<queue>
using namespace std;
typedef long long ll;

struct node{
	int val,indeg,topo_index;
	vector <int> begins;
	vector <int> goes;
	node(){
		val = indeg = topo_index = 0;
		begins.clear();
		goes.clear();
	}
}a[300005];
int n,m,u,v,topo[300005],dp[300005];
char s[300005];
queue <int> que;

bool ts(){
	while(!que.empty()) que.pop();
	for(int i=1;i<=n;i++){
		if(a[i].indeg==0) que.push(i);
	}
	int cur = 0;
	while(!que.empty()){
		int no = que.front();que.pop();
		topo[++cur] = no;
		a[no].topo_index = cur;
		for(int i=0;i<a[no].goes.size();i++){
			a[a[no].goes[i]].indeg--;
			if(a[a[no].goes[i]].indeg == 0) que.push(a[no].goes[i]);
		}
	}
	if(cur != n) return false;
	return true;
}

int main(){
	scanf("%d%d",&n,&m);
	scanf("%s",s+1);
	for(int i=1;i<=n;i++) a[i].val = s[i]-'a';
	for(int i=1;i<=m;i++){
		scanf("%d%d",&u,&v);
		a[v].begins.push_back(u);
		a[u].goes.push_back(v);
		a[v].indeg++;
	}
	bool f=ts();
	if(!f){
		printf("-1\n");
		return 0;
	}

	int ans = 0;
	for(int i=0;i<=25;i++){
		memset(dp,0,sizeof(dp));
		for(int j=1;j<=n;j++){
			int max_ = 0;
			for(int k=0;k<a[topo[j]].begins.size();k++){
				max_ = max(max_,dp[a[a[topo[j]].begins[k]].topo_index]);
			}
			dp[j] = max_ + (a[topo[j]].val == i);
			ans = max(ans,dp[j]);
		}
	}
	
	printf("%d\n",ans);
	return 0;
}