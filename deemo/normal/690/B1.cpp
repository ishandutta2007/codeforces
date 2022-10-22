#include<iostream>
#include<string>
#include<algorithm>
#include<vector>

using namespace std;

const int MAXN = 50 + 5;

int n;
string s[MAXN];

bool fit(int a, int b){return 0 <= min(a, b) && max(a, b) < n && s[a][b] == '4';}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++)	cin >> s[i];
	int cnt = 0;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			if (s[i][j] == '4')	cnt++;
	if (cnt == 0){
		cout << "No\n";
		return 0;
	}
	int minx = 100, maxx = -1, miny = 100, maxy = -1;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			if (s[i][j] == '4'){
				minx = min(minx, i);
				maxx = max(maxx, i);
				miny = min(miny, j);
				maxy = max(maxy, j);
			}
	if ((maxx - minx + 1) * (maxy - miny + 1) != cnt){
		cout << "No\n";
		return 0;
	}
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			if (s[i][j] != '4'){
				int c = s[i][j] - '0', t = 0;
				if (fit(i - 1, j - 1) || fit(i - 1, j) || fit(i, j - 1))	t++;
				if (fit(i - 1, j + 1) || fit(i - 1, j) || fit(i, j + 1))	t++;
				if (fit(i + 1, j - 1) || fit(i + 1, j) || fit(i, j - 1))	t++;
				if (fit(i + 1, j + 1) || fit(i + 1, j) || fit(i, j + 1))	t++;
				if (t != c){
					cout << "No\n";
					return 0;
				}
			}
	cout << "Yes\n";
	return 0;
}