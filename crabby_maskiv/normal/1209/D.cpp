#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=100005;
const ll inf=0x3f3f3f3fll;
int n,m;
vector<int> v[N];
bool vs[N],vg[N];
int x[N],y[N];
int ans=0;
void dfs(int cur){
	if(vg[cur]) return;
	vg[cur]=1;
	int i,j;
	if(vs[x[cur]]&&vs[y[cur]]) ans++;
	vs[x[cur]]=vs[y[cur]]=1;
	while(v[x[cur]].size()){
		auto k=v[x[cur]].back();
		if(k!=cur) dfs(k);
		if(!v[x[cur]].size()) break;
		v[x[cur]].pop_back();
	}
	while(v[y[cur]].size()){
		auto k=v[y[cur]].back();
		if(k!=cur) dfs(k);
		if(!v[y[cur]].size()) break;
		v[y[cur]].pop_back();
	}
}
int main(){
	int i,j;
	cin>>n>>m;
	for(i=1;i<=m;i++){
		cin>>x[i]>>y[i];
		v[x[i]].push_back(i);
		v[y[i]].push_back(i);
	}
	for(i=1;i<=m;i++)
		if(!vg[i]) dfs(i);
	cout<<ans;
	return 0;
}