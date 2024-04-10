#include<bits/stdc++.h>
#define LL long long
#define pb push_back
using namespace std;
const int N=2e5+50;
int n,k,d[N],a[N],nn,sz[N];LL ans;
vector<int>v[N];
void dfs(int x){
	sz[x]=1;
	for(int i=0,y;i<v[x].size();i++)
		if(d[y=v[x][i]]==-1)d[y]=d[x]+1,dfs(y),sz[x]+=sz[y];
	a[x]=d[x]-sz[x]+1;
}
int main(){
	scanf("%d%d",&n,&k);
	memset(d,-1,sizeof(d));
	for(int i=1,x,y;i<n;i++)
		scanf("%d%d",&x,&y),v[x].pb(y),v[y].pb(x);
	d[1]=0;dfs(1);
	sort(a+1,a+n+1);
	for(int i=1;i<=k;i++)ans+=a[n-i+1];
	cout<<ans;
	// for(int i=1;i<=nn;i++)q.push(node{a[i]-1,i});
	// for(int i=1;i<=k;i++)
	return 0;
}