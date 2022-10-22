/*





D P 




 l l
*/
#include<bits/stdc++.h>
using namespace std;
#define pb push_back
const int N=100000;
int n;
vector<int> nei[N+1];
int dep[N+1];
vector<int> deps;
int root;
set<int> st;
vector<int> vv;
void dfs(int x=root,int fa=0){
	if(nei[x].size()==1&&x!=root)deps.pb(dep[x]),dep[x]!=2&&(st.insert(fa),vv.pb(fa),0);
	for(int i=0;i<nei[x].size();i++){
		int y=nei[x][i];
		if(y==fa)continue;
		dep[y]=dep[x]+1;
		dfs(y,x);
	}
}
int main(){
	cin>>n;
	for(int i=1;i<n;i++){
		int x,y;
		scanf("%d%d",&x,&y);
		nei[x].pb(y);nei[y].pb(x);
	}
	for(int i=1;i<=n;i++)if(nei[i].size()==1)root=i;
	dfs();
	int ans1=1,ans2=n-1-(vv.size()-st.size());
	for(int i=0;i<deps.size();i++)if(deps[i]&1)ans1=3;
	for(int i=0;i<deps.size();i++)ans2-=deps[i]==2;
	cout<<ans1<<" "<<ans2;
	return 0;
}