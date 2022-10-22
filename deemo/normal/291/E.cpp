#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>
#include<utility>
#include<string>

using namespace std;

const int max_n = 1e6 + 10;

int ans, n, psize;
string pat, s[max_n];
vector<int>	child[max_n];
int f[max_n], nxt[max_n][30];

void dfs(int v, int k){
	for (int u:child[v]){
		int kk = k;
		for (int i = 0; i < s[u].size(); i++){
			kk = nxt[kk][s[u][i] - 'a'];
			if (kk == psize)	ans++, kk = f[kk];
		}
		dfs(u, kk);
	}
}

void init(){
	psize = pat.size();
	int k = f[1] = 0;
	for (int i = 1; i < pat.size(); i++){
		while(k && pat[i] != pat[k])	k = f[k];
		if (pat[k] == pat[i])	k++;
		f[i + 1] = k;
	}

	for (int i = 0; i < psize; i++)
		for (int j = 0; j < 26; j++){
			if (i == 0){
				if (pat[0] - 'a' == j)	nxt[i][j] = 1;
			}
			else{
				if (pat[i] - 'a' == j)	nxt[i][j] = i + 1;
				else	nxt[i][j] = nxt[f[i]][j];
			}		
		}
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	for (int i = 1; i < n; i++){
		int par;	cin >> par;	par--;
		cin >> s[i];
		child[par].push_back(i);
	}
	cin >> pat;
	init();
	dfs(0, 0);
	cout << ans << endl;
	return 0;
}