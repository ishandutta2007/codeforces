#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define F first
#define S second

const int MAXN = 1500 + 5;

int n, d[30][MAXN];
string s;
vector<int> vec[30];

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> s;
	for (int i = 0; i < n; i++)
		vec[s[i]-'a'].push_back(i);

	for (int w = 0; w < 26; w++){
		for (int m = 0; m <= n; m++) d[w][m] = m;

		for (int i = 0; i < vec[w].size(); i++)
			for (int j = i; j < vec[w].size(); j++){
				int cur = j-i+1;
				int bad = vec[w][j] - vec[w][i] + 1 - cur;
				d[w][bad] = max(d[w][bad], vec[w][j]-vec[w][i]+1);
			}

		for (int m = 1; m <= n; m++) d[w][m] = max(d[w][m], d[w][m-1]+1);
		for (int m = 0; m <= n; m++) d[w][m] = min(d[w][m], n);
	}

	int q;	cin >> q;
	while (q--){
		int m; char c; cin >> m >> c;
		cout << d[c-'a'][m] << "\n";
	}
	return 0;
}