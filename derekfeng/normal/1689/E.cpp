#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;
#define fi first
#define se second
const int inf=(1<<30)-1;
int t,n,a[2005],ans,cnt;
bool vis[2035];
vector<int>g[30];
void dfs(int x){
	if(vis[x])return;
	vis[x]=1;
	if(x<n){
		cnt++;
		for(int i=0;i<30;i++)
			if((a[x]>>i)&1)dfs(i+n);
	}else{
		x-=n;
		for(auto y:g[x])dfs(y);
	}
}
bool check(){
	for(int i=0;i<30;i++)g[i].clear(),vis[n+i]=0;
	for(int i=0;i<n;vis[i]=0,i++)
		for(int j=0;j<30;j++)if((a[i]>>j)&1)
			g[j].push_back(i);
	cnt=0,dfs(0);
	return cnt==n;
}
void sol(){
	if(check()){
		printf("%d\n",ans);
		for(int i=0;i<n;i++)printf("%d ",a[i]);
		puts("");return;
	}
	for(int i=0;i<n;i++){
		a[i]--;
		if(check()){
			printf("%d\n",ans+1);
			for(int i=0;i<n;i++)printf("%d ",a[i]);
			puts("");return;
		}
		a[i]++;
		if(a[i]==inf)continue;
		a[i]++;
		if(check()){
			printf("%d\n",ans+1);
			for(int i=0;i<n;i++)printf("%d ",a[i]);
			puts("");return;
		}
		a[i]--;
	}
	printf("%d\n",ans+2);
	int mx=0;for(int i=0;i<n;i++)mx=max(mx,a[i]&-a[i]);
	vector<int>v;for(int i=0;i<n;i++)if(mx==(a[i]&-a[i]))v.push_back(i);
	a[v[0]]--,a[v[1]]++;
	for(int i=0;i<n;i++)printf("%d ",a[i]);
	puts("");
}
int main(){
	int tc;scanf("%d",&tc);
	while(tc--){
		scanf("%d",&n),ans=0;
		for(int i=0;i<n;i++){
			scanf("%d",&a[i]);
			if(a[i]==0)ans++,a[i]=1;
		}
		sol();
	}
}