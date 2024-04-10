#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
#include<utility>
#include<cstring>

using namespace std;

#define FAILURE {cout << "NO\n"; return 0;}

const int MAXN = 3e5 + 10;
const int CC = 140;

int n, hs[CC][CC], in[MAXN], src;
string s[MAXN], ans;
vector<int>	adj[MAXN];

void get(int v){
	while (adj[v].size()){
		int u = adj[v].back();
		adj[v].pop_back();
		get(u);
	}

	if (v < n)
		ans += s[v][2];
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	for (int i = 0; i < CC; i++)
		for (int j = 0; j < CC; j++)
			hs[i][j] = i * CC + j;

	cin >> n;
	for (int i = 0; i < n; i++){
		cin >> s[i];
		adj[n + hs[s[i][0]][s[i][1]]].push_back(i), in[i]++;
		adj[i].push_back(n + hs[s[i][1]][s[i][2]]), in[n + hs[s[i][1]][s[i][2]]]++;
	}

	int c = 0;
	for (int i = 0; i < CC * CC; i++)
		if (in[n + i] != adj[n + i].size()){
			if (abs(in[n + i] - int(adj[n + i].size())) > 1)	FAILURE

			if (in[n + i] < adj[n + i].size())	src = n + i;
			c++;
		}
		else if (src == 0 && adj[n + i].size())	src = n + i;
	if (c > 2)	FAILURE
	
	get(src);

	bool fl = 0;
	for (int i = 0; !fl && i < CC; i++)
		for (int j = 0; !fl && j < CC; j++)
			if (hs[i][j] == src - n)
				ans += char(j), ans += char(i), fl = 1;
	reverse(ans.begin(), ans.end());

	if (ans.size() != n + 2)	FAILURE
	cout << "YES\n";
	cout << ans << "\n";
	return	0;
}