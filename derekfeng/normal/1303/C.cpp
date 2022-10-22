#include <bits/stdc++.h>
using namespace std;
void read(string &s){
	char ch=getchar();s="";
	for (;ch==' '||ch=='\n';ch=getchar());
	for (;ch!=' '&&ch!='\n';s+=ch,ch=getchar()); 
}
void write(string s){
	for (int i=0;i<s.size();i++) putchar(s[i]);
}
vector<int>g[26];
bool vis[26];
int mp[26][26];
string ans;
bool dfs(int x){
	vis[x]=1;
	ans+=(char)(x+'a');
	int now=0;
	for (int i=0;i<g[x].size();i++){
		if (vis[g[x][i]]) now++;
		else if (!dfs(g[x][i])) return 0;
	}
	if (now>1) return 0;
	return 1;
}
int main(){
	int T;cin>>T;
	while (T--){
		memset (mp,0,sizeof(mp));
		ans="";
		bool f=0;
		string s;read(s);
		for (int i=0;i<26;i++) g[i].clear();
		for (int i=1;i<s.size();i++){
			if (mp[s[i]-'a'][s[i-1]-'a']) continue;
			mp[s[i]-'a'][s[i-1]-'a']=mp[s[i-1]-'a'][s[i]-'a']=1;
			g[s[i]-'a'].push_back(s[i-1]-'a'),g[s[i-1]-'a'].push_back(s[i]-'a');
		}
		for (int i=0;i<26;i++) if (g[i].size()>2){
			puts("NO");
			f=1;
			break;
		}
		if (f) continue;
		memset (vis,0,sizeof(vis));
		bool ok=0;
		for (int i=0;i<26;i++)if ((g[i].size()==0 || g[i].size()==1)&&!vis[i])
			if(!dfs(i)){
			puts("NO");
			ok=1;
			break;
		}
		if (ok) continue;
		for (int i=0;i<26;i++) if (!vis[i]){
			puts("NO");
			ok=1;
			break;
		}
		if (ok) continue;
		puts("YES");
		write(ans),puts("");
	}
}