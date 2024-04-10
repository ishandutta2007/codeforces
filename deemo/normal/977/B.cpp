#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define F first
#define S second

int cnt[300][300];

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n; cin >> n;
	string s; cin >> s;
	int mx = 0;
	for (int i = 0; i + 1 < n; i++)
		mx = max(mx, ++cnt[s[i]][s[i+1]]);
	for (int i = 0; i < 200; i++)
		for (int j = 0; j < 200; j++)
			if (cnt[i][j] == mx){
				cout << char(i) << char(j) << endl;
				return 0;
			}
	return 0;
}