#include<iostream>
#include<string>
#include<algorithm>
#include<cstring>
#include<vector>

using namespace std;

const int MAXN = 50 + 5;
const int C = 26 + 2;

int n[2], d[MAXN][MAXN];
string s[2];
bool cv[2][MAXN][MAXN][C];
vector<string>	vec[C];

int main(){
	for (int w = 0; w < 2; w++)
		cin >> s[w], n[w] = s[w].size();

	int q;	cin >> q;
	while (q--){
		string temp;	cin >> temp;
		vec[temp[0] - 'a'].push_back(temp.substr(3));
	}
	
	for (int w = 0; w < 2; w++)
		for (int r = 1; r <= n[w]; r++)
			for (int l = r - 1; ~l; l--)
				for (int c = 0; c < 26; c++){
					if (r - l == 1)
						cv[w][l][r][c] = s[w][l] - 'a' == c;
					else
						for (string t:vec[c])
							for (int j = l; j + 1 < r; j++)
								cv[w][l][r][c] |= cv[w][l][j + 1][t[0] - 'a'] & cv[w][j + 1][r][t[1] - 'a'];
				}

	memset(d, 63, sizeof(d));
	d[0][0] = 0;
	for (int a = 1; a <= n[0]; a++)
		for (int b = 1; b <= n[1]; b++)
			for (int i = 0; i < a; i++)
				for (int j = 0; j < b; j++)
					for (int c = 0; c < 26; c++)
						if (cv[0][i][a][c] && cv[1][j][b][c])
							d[a][b] = min(d[a][b], d[i][j] + 1);

	if (d[n[0]][n[1]] > 1e8)
		cout << "-1\n";
	else
		cout << d[n[0]][n[1]] << "\n";
	return 0;
}