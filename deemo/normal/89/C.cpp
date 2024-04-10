//I stand alone in the dark..

#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
#include<utility>

using namespace std;

#define F first
#define S second
#define up pu

const int MAXN = 5e3 + 10;

int n, m;
string s[MAXN];
vector<int>	le[MAXN], ri[MAXN], up[MAXN], dn[MAXN];
vector<int>	sle[MAXN], sri[MAXN], sup[MAXN], sdn[MAXN];

int get(int a, int b){
	int ret = 0;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			sle[i][j] = le[i][j]
			, sri[i][j] = ri[i][j]
			, sup[i][j] = up[i][j]
			, sdn[i][j] = dn[i][j];
	
	while (~a && ~b && a < n && b < m){
		ret++;

		if (~sle[a][b])
			sri[a][sle[a][b]] = sri[a][b];
		if (sri[a][b] < m)
			sle[a][sri[a][b]] = sle[a][b];

		if (~sup[a][b])
			sdn[sup[a][b]][b] = sdn[a][b];
		if (sdn[a][b] < n)
			sup[sdn[a][b]][b] = sup[a][b];

		if (s[a][b] == 'L')		b = sle[a][b];
		else if (s[a][b] == 'R')	b = sri[a][b]; 
		else if (s[a][b] == 'U')	a = sup[a][b];
		else if (s[a][b] == 'D')	a = sdn[a][b];
	}

	return ret;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m;
	for (int i = 0; i < n; i++){
		cin >> s[i];
		le[i].resize(m);
		ri[i].resize(m);
		up[i].resize(m);
		dn[i].resize(m);

		sle[i].resize(m);
		sri[i].resize(m);
		sup[i].resize(m);
		sdn[i].resize(m);
	}

	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++){
			le[i][j] = j - 1;
			while (~le[i][j] && s[i][le[i][j]] == '.')	le[i][j]--;
			
			ri[i][j] = j + 1;
			while (ri[i][j] < m && s[i][ri[i][j]] == '.')	ri[i][j]++;

			up[i][j] = i - 1;
			while (~up[i][j] && s[up[i][j]][j] == '.')	up[i][j]--;

			dn[i][j] = i + 1;
			while (dn[i][j] < n && s[dn[i][j]][j] == '.')	dn[i][j]++;
		}

	int mx = 0, cnt = 0;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			if (s[i][j] != '.'){
				int x = get(i, j);
				if (x > mx)
					mx = x, cnt = 1;
				else if (x == mx)
					cnt++;
			}

	cout << mx << " " << cnt << "\n";
	return 0;
}