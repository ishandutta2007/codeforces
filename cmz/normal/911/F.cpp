#include<bits/stdc++.h>
#define ll long long
using namespace std;
vector<int>G[202000];
struct P {
	int x,y;
};
vector<P>aa;
int n,x,y,mx,z,rt,fa[202000],dep[202000],in[202000];
ll ans;
void dfs(int x,int fff) {
	dep[x]=dep[fa[x]=fff]+1;
	if (dep[x]>mx) mx=dep[x], z=x;
	for (auto y:G[x]) if (y-fff) dfs(y,x);
}
void D(int x,int dis,int fr,int fl=0) {
	in[x]=1;
	for (auto y:G[x]) if (!in[y]) D(y,dis+1,fr,1);
	if (fl) ans+=dis, aa.push_back(P {fr,x});
}
int main() {
	cin.tie(0); cout.tie(0); cin>>n;
	for (int i=1; i<n; ++i) cin>>x>>y, G[x].push_back(y), G[y].push_back(x);
	mx=0;
	dfs(1,0);
	mx=0;
	rt=z;
	dfs(rt,0);
	ans=(ll)mx*(mx-1)/2;
	for (int t=z; t; t=fa[t]) in[t]=1;
	for (int t=z; t; t=fa[t]) {
		if (dep[t]-1>dep[z]-dep[t]) D(t,dep[t]-1,rt);
		else D(t,dep[z]-dep[t],z);
	}
	cout<<ans<<endl;
	for (int i=0; i<aa.size(); ++i) printf("%d %d %d\n",aa[i].x,aa[i].y,aa[i].y);
	for (int t=z; t-rt; t=fa[t]) printf("%d %d %d\n",rt,t,t);
}