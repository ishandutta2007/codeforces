#include<iostream>
#include<string>

using namespace std;

const int MAXN = 1e3 + 10;

int n, m, cnt[2][MAXN], tot;
string s[MAXN];

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m;
	for (int i = 0; i < n; i++){
		cin >> s[i];
		for (int j = 0; j < m; j++)
			if (s[i][j] == '*'){
				cnt[0][i]++;
				cnt[1][j]++;
				tot++;
			}
	}
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++){
			int cc = cnt[0][i] + cnt[1][j] - bool(s[i][j] == '*');
			if (cc == tot){
				cout << "YES\n";
				cout << i + 1 << " " << j + 1 << endl;
				return 0;
			}
		}
	cout << "NO\n";
	return 0;
}