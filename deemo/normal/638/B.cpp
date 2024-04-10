#include<iostream>
#include<string>
#include<algorithm>
#include<vector>

using namespace std;

const int MAXN = 100 + 2;

int n, cnt[MAXN];
bool del[MAXN], vis[MAXN], mark[200];
string s[MAXN];
vector<string>	ans;
vector<int>	adj[MAXN];

bool check(string a, string b){
	int sz = a.size();
	for (int i = 0; i <= b.size() - sz; i++)
		if (a == b.substr(i, sz))	return	true;
	return	false;
}

void dfs(int v){
	if (vis[v])	return;
	vis[v] = 1;
	for (int u:adj[v])
		dfs(u);
	ans.push_back(s[v]);
}

bool nxt(string a, string b){
	int sa = a.size(), sb = b.size();
	for (int i = 0; i < sa; i++){
		string ss = a.substr(i);
		string tt = b.substr(0, sa - i);
		if (ss == tt)	return	true;
	}		
	return	false;
}

int main(){
	cin >> n;	for (int i = 0; i < n; i++)	cin >> s[i];
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			if (i ^ j && !del[j] && s[i].size() <= s[j].size() && check(s[i], s[j])){
				del[i] = 1;
				break;
			}
	for (int i = 0; i < n; i++)
		if (!del[i])
			for (int j = 0; j < n; j++)
				if (!del[j] && i^j && nxt(s[i], s[j]))
					adj[i].push_back(j), cnt[j]++;
	for (int i = 0; i < n; i++)
		if (!del[i] && !cnt[i])	dfs(i);
	reverse(ans.begin(), ans.end());
	for (string s:ans)
		for (char c:s)
			if (!mark[c])	cout << c, mark[c] = 1;
	cout << "\n";
	return	0;
}