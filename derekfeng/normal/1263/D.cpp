#include <bits/stdc++.h>
using namespace std;
string s;
int n;
short vis[200004][26],has[26];
vector<int>g[26];
void dfs(int x){
	has[x]=1;
	for (int i=0;i<g[x].size();i++) if (!has[g[x][i]])
		dfs(g[x][i]);
}
int num[26];
int main(){
	cin>>n;
	for (int i=0;i<n;i++){
		cin>>s;
		for (int j=0;j<s.size();j++) vis[i][s[j]-'a']++,num[s[j]-'a']++;
		for (int j=0;j<26;j++) if (vis[i][j])
			for (int k=0;k<26;k++) if (k!=j && vis[i][k])
				g[j].push_back(k);
	}
	int ans=0;
	for (int i=0;i<26;i++) if (!has[i]){
		if (num[i]==0) continue;
		dfs(i);
		ans++;
	}
	cout<<ans;
}