/*








*/
#include<bits/stdc++.h>
using namespace std;
#define int long long
#define pb push_back
const int inf=0x3f3f3f3f;
const int N=100000,LOG_N=17;
int n,m;
int a[N+1];
vector<int> nei[N+1];
bool vis[N+1];
int dep[N+1];
int ans=inf;
void bfs(int x,int y){
	queue<int> q;
	q.push(x);
	memset(vis,0,sizeof(vis));
	memset(dep,0,sizeof(dep));
	while(q.size()){
		int t=q.front();
		q.pop();
		for(int i=0;i<nei[t].size();i++){
			int z=nei[t][i];
			if(t==x&&z==y||vis[z])continue;
			dep[z]=dep[t]+1;
			if(z==y){ans=min(ans,dep[y]+1);return;}
			vis[z]=true;
			q.push(z);
		}
	}
}
signed main(){
	cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=0;i<=60;i++){
		vector<int> v;
		for(int j=1;j<=n;j++)if(a[j]&1ll<<i)v.pb(j);
//		for(int j=0;j<v.size();j++)cout<<v[j]<<" ";puts("");
		if(v.size()>=3)return puts("3"),0;
		if(v.size()==2)nei[v[0]].pb(v[1]),nei[v[1]].pb(v[0]);
	}
	for(int i=1;i<=n;i++)for(int j=0;j<nei[i].size();j++){
		int x=nei[i][j];
		if(i<x)bfs(i,x);
	}
	cout<<(ans<inf?ans:-1);
	return 0;
}
/*1
7
129 259 6 12 24 304 224
*/