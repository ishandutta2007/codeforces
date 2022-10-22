#include<bits/stdc++.h>

using namespace std;

const int MAXN = 100 + 3;

int n, m;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m;
	bool fl = 0;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++){
			char c;	cin >> c;
			if (c != 'W' && c != 'G' && c != 'B')
				fl = 1;
		}
	if (fl)
		cout << "#Color\n";
	else
		cout << "#Black&White\n";
	return 0;
}