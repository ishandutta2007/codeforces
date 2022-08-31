#include<bits/stdc++.h>
using namespace std;
#define F0R(i,a) for(int i = 0; i < a; ++i

const int MAX=5e5+9;
vector<int> g[MAX],s[MAX];
int n;

void dfs(int v,int c,int p=0,int h=0) {
	int k=0;
	for (int u:g[v]) if (u!=p) dfs(u,c,v,h+1),k++;
	if (!k) s[c].push_back(h);
}

int main() {
	cin >> n;
	for (int i = 0; i<n-1;++i) {
		int u,v;
		scanf("%d%d",&u,&v);
		v--,u--;
		g[v].push_back(u),g[u].push_back(v);
	}
	int t=0;
	for (int i:g[0]) dfs(i,t++);
	int ans=0;
	for (int i = 0; i<t;++i) {
		int ma=-1;
		sort(s[i].begin(),s[i].end());
		for(int j = 0; j<s[i].size();++j) {
			if (s[i][j]<=ma) ma++;
			else ma=s[i][j];
		}
		ans=max(ans,ma);
	}
	cout<<ans+1;
}