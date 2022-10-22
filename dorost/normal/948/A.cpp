#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
#define F first
#define S second
const int N = 512;
string s[N];

int32_t main(){
	int n, m;
	cin >> n >> m;
	bool f = true;
	for (int i = 0; i < n; i++){
		cin >> s[i];
		for (int j = 1; j < m; j++){
			if ((s[i][j] == 'S' && s[i][j - 1] == 'W') || (s[i][j] == 'W' && s[i][j - 1] == 'S')){
				f = false;
			}
		}
	}
	for (int i = 0; i < m; i++){
		for (int j = 1; j < n; j++){
			if ((s[j][i] == 'W' && s[j - 1][i] == 'S') || (s[j][i] == 'S' && s[j - 1][i] == 'W')){
				f = false;
			}
		}
	}
	if (f){
		cout << "Yes\n";
		for (int i = 0; i < n; i++){
			for (int j = 0; j < m; j++){
				if (s[i][j] == '.')
					cout << "D";
				else
					cout << s[i][j];
			}
			cout << endl;
		}
	}else
		cout << "No\n";
}