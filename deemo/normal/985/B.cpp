#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define F first
#define S second

const int MAXN = 2e3 + 10;

int n, m;
string s[MAXN];
int cnt[MAXN];

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m;
	for (int i = 0; i < n; i++) cin >> s[i];
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			if (s[i][j] == '1')
				cnt[j]++;

	for (int i = 0; i < n; i++){
		bool fail = false;
		for (int j = 0; j < m; j++)
			if (s[i][j] == '1' && cnt[j] == 1)
				fail = true;
		if (!fail){
			cout << "YES\n";
			return 0;
		}
	}
	cout << "NO\n";
	return 0;
}