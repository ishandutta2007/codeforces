#include<iostream>
#include<string>
#include<algorithm>
#include<cassert>
#include<vector>
#include<utility>
#include<cstring>

using namespace std;

const int MAXN = 1e3 + 2;

int n, m, ls[6];
char c[MAXN][MAXN], ss[MAXN][MAXN];
vector<int>	r[3];
int mark[400];

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m;
	for (int i = 0; i < n; i++){
		for (int j = 0; j < 6; j++)
			ls[j] = 0;
		for (int j = 0; j < m; j++){
			cin >> c[i][j];
			if (c[i][j] != '0'){
				if (ls[c[i][j] - '0'] != 0 && (j + 1) % 2 != ls[c[i][j] - '0'] % 2){
					cout << 0 << endl;
					return	0;
				}
				r[i % 2].push_back(c[i][j]);
				ls[c[i][j] - '0'] = j + 1;
			}
		}
	}

	bool fl = 1;
	for (int i = 0; i < 2; i++){
		sort(r[i].begin(), r[i].end());
		r[i].resize(unique(r[i].begin(), r[i].end()) - r[i].begin());
		if (r[i].size() > 2)
			fl = 0;
		for (int u:r[i])	mark[u]++;
	}
	for (int i = '0'; i < '6'; i++)
		if (mark[i] > 1)	fl = 0;

	if (fl){
		for (int i = 0; i < 2; i++)
			while((int)r[i].size() < 2){
				for (int z = '1'; z < '5'; z++)
					if (!mark[z]){
						mark[z] = 1;
						r[i].push_back(z);
						break;
					}
			}

		for (int i = 0; i < n; i++){
			int a = r[i % 2][0], b = r[i % 2][1];
			int fs, ind = -1;
			for (int j = 0; j < m; j++)
				if (c[i][j] != '0'){
					ind = j % 2;
					fs = c[i][j];
					break;
				}
			if (ind == -1){
				ind = 0;
				fs = b;
			}
			if (a == fs)	a = b;
			assert(a != fs);
			for (int j = 0; j < m; j++)
				if (j % 2 == ind)	
					c[i][j] = fs;
				else
					c[i][j] = a;
		}
		for (int i = 0; i < n; i++){
			for (int j = 0; j < m; j++)
				cout << c[i][j];
			cout << "\n";
		}
		return	0;
	}
	
	memset(mark, 0, sizeof(mark));
	r[0].clear();	r[1].clear();
	for (int i = 0; i < m; i++)
		for (int j = 0; j < n; j++)
			ss[m - i - 1][j] = c[j][i];
	swap(n, m);
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			c[i][j] = ss[i][j];

	for (int i = 0; i < n; i++){
		for (int j = 0; j < 6; j++)
			ls[j] = 0;
		for (int j = 0; j < m; j++){
			if (c[i][j] != '0'){
				if (ls[c[i][j] - '0'] != 0 && (j + 1) % 2 != ls[c[i][j] - '0'] % 2){
					cout << 0 << endl;
					return	0;
				}
				r[i % 2].push_back(c[i][j]);
				ls[c[i][j] - '0'] = j + 1;
			}
		}
	}

	for (int i = 0; i < 2; i++){
		sort(r[i].begin(), r[i].end());
		r[i].resize(unique(r[i].begin(), r[i].end()) - r[i].begin());
		if (r[i].size() > 2){
			cout << 0 << endl;
			return	0;
		}
		for (int u:r[i])	mark[u]++;
	}
	for (int i = '0'; i < '6'; i++)
		if (mark[i] > 1){
			cout << 0 << endl;
			return	0;
		}

	for (int i = 0; i < 2; i++)
		while((int)r[i].size() < 2){
			for (int z = '1'; z < '5'; z++)
				if (!mark[z]){
					mark[z] = 1;
					r[i].push_back(z);
					break;
				}
		}

	for (int i = 0; i < n; i++){
		int a = r[i % 2][0], b = r[i % 2][1];
		int fs, ind = -1;
		for (int j = 0; j < m; j++)
			if (c[i][j] != '0'){
				ind = j % 2;
				fs = c[i][j];
				break;
			}
		if (ind == -1){
			ind = 0;
			fs = b;
		}
		if (a == fs)	a = b;
		for (int j = 0; j < m; j++)
			if (j % 2 == ind)	
				c[i][j] = fs;
			else
				c[i][j] = a;
	}
	for (int i = 0; i < m; i++)
		for (int j = 0; j < n; j++)
			ss[i][n-j-1] = c[j][i];
	swap(n, m);

	for (int i = 0; i < n; i++){
		for (int j = 0; j < m; j++)
			cout << ss[i][j];
		cout << "\n";
	}

	return	0;
}