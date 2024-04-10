#include<iostream>
#include<string>
#include<vector>
#include<cmath>
#include<algorithm>

using namespace std;

typedef long long ll;

const int MAX = 100 + 20;
const int INF = 1e9 + 1;

string s, t, v;
int d[MAX + 2][MAX + 2][MAX + 2], f[MAX], nxt[MAX][30];
pair<pair<int, int>, int>	par[MAX+2][MAX+2][MAX+2];
bool mark[MAX+2][MAX+2][MAX+2];

void init(){
	int k = 0;
	for (int i = 1; i < v.size(); i++){
		while (k && v[i] != v[k])	k = f[k];
		if (v[i] == v[k])	k++;
		f[i + 1] = k;
	}	
	
	for (int i = 0; i <= v.size(); i++)
		for (int j = 0; j < 26; j++)
			if (i < v.size() && char(j + 'A') == v[i])
				nxt[i][j] = i + 1;
			else
				nxt[i][j] = nxt[f[i]][j];

	for (int i = 0; i < MAX; i++)
		for (int j = 0; j < MAX; j++)
			for (int k = 0; k < MAX; k++)
				d[i][j][k] = -INF;
	d[0][0][0] = 0;
}

void show(pair<pair<int, int>, int> z){
	if(z.first.first == 0 || z.first.second == 0)	return;
	show(par[z.first.first][z.first.second][z.second]);

	//pair<pair<int, int>, int>	p = par[z.first.first][z.first.second][z.second];
	if (mark[z.first.first][z.first.second][z.second])
		cout << s[z.first.first-1];
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> s >> t >> v;
	init();
	
	int ans = 0;
	pair<pair<int, int>, int>	ind;
	for (int i = 0; i <= s.size(); i++)
		for (int j = 0; j <= t.size(); j++)	
			for (int k = 0; k < v.size(); k++){
				if (d[i+1][j][k] < d[i][j][k]){
					mark[i+1][j][k] = 0;
					d[i+1][j][k] = d[i][j][k];
					par[i+1][j][k] = {{i, j}, k};
				}

				if (d[i][j+1][k] < d[i][j][k]){
					d[i][j+1][k] = d[i][j][k];
					par[i][j+1][k] = {{i, j}, k};
					mark[i][j+1][k] = 0;
				}		

				if (s[i] == t[j] && nxt[k][s[i] - 'A'] != v.size()){	
					int g = nxt[k][s[i]-'A'];
					if (d[i+1][j+1][g] < d[i][j][k] + 1){
						d[i+1][j+1][g] = d[i][j][k] + 1;
						par[i+1][j+1][g] = {{i, j}, k};
						mark[i+1][j+1][g] = 1;
					}	
				}

				if (ans < d[i][j][k]){
					ans = d[i][j][k];
					ind = {{i, j}, k};
				}
			}
	if (ans == 0){
		cout << 0 << endl;
		return 0;
	}
	show(ind);
	cout << endl;
	return 0;
}