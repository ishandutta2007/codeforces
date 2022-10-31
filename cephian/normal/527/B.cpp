#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef long long ll;

int g[26][26];
int n;
string a,b;


int main() {
	ios::sync_with_stdio(0);
	for(int i = 0; i < 26; ++i)
		fill(g[i],g[i]+26,0);
	cin >> n >> a >> b;
	int h = 0;
	for(int i = 0; i < n; ++i) {
		a[i]-='a';
		b[i]-='a';	
		if(a[i] != b[i]) {
			++h;
			g[a[i]][b[i]] = i+1;
		}
	}
	for(int i = 0; i < 26; ++i) {
		for(int j = i+1; j < 26; ++j) {
			if(g[i][j] && g[j][i]) {
				cout << h-2 << "\n" << g[i][j] << " " << g[j][i] << "\n";
				return 0;
			}
		}
	}

	for(int i = 0; i < 26; ++i) {
		for(int j = 0; j < 26; ++j) {
			if(g[i][j]) {
				for(int k = 0; k < 26; ++k) {
					if(g[j][k]) {
						cout << h-1 << "\n" << g[i][j] << " " << g[j][k] << "\n";
						return 0;
					}
				}
			}
		}
	}
	cout << h << "\n" << "-1 -1\n";
	return 0;
}