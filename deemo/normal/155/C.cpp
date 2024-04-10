#include<iostream>
#include<string>
#include<cstring>

using namespace std;

const int MAXN = 1e5 + 10;

string s;
int k;
int ss[150], d[MAXN][150];

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> s >> k;
	while (k--){
		string t;	cin >> t;
		ss[t[0]] = t[1];
		ss[t[1]] = t[0];
	}

	for (int i = 0; i < s.size(); i++)
		for (int j = 'a'; j <= 'z'; j++){
			d[i + 1][j] = d[i][j];
			if (s[i] == j){
				d[i + 1][j] = max(d[i + 1][j], 1);
				for (int w = 'a'; w <= 'z'; w++)
					if (w != ss[s[i]])
						d[i + 1][j] = max(d[i + 1][j], 1 + d[i][w]);
			}
		}
	
	int ans = 1e9;
	for (int i = 'a'; i <= 'z'; i++)
		ans = min(ans, (int)s.size() - d[s.size()][i]);
	cout << ans << "\n";
	return	0;
}