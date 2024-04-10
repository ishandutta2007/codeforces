#include <bits/stdc++.h>
#define ll long long
#define db long double
#define x first
#define y second
#define mp make_pair
#define pb push_back
#define all(a) a.begin(), a.end()

using namespace std;

char matrix[100][100];

void solve(){
	int n, m, k;
	cin >> n >> m >> k;
	for (int i=0; i < n; ++i) for (int j=0; j < m; ++j) cin >> matrix[i][j];
	vector<char> el;
	for (int i='a'; i <= 'z'; ++i) el.push_back(i);
	for (int i='A'; i <= 'Z'; ++i) el.push_back(i);
	for (int i='0'; i <= '9'; ++i) el.push_back(i);


	int rise = 0;
	for (int i=0; i < n; ++i) for (int j=0; j < m; ++j){
		if (matrix[i][j] == 'R') rise++;
	}

	vector<int> values;
	for (int i=0; i < k; ++i){
		int rem = k-i;
		values.push_back(rise / rem);
		rise -= values.back();
	}

	int cur = 0;
	int left = values[0];
	for (int i=0; i < n; ++i){
		if (i%2 == 0){
			for (int j=0; j < m; ++j){
				if (matrix[i][j] == 'R') left--;
				matrix[i][j] = el[cur];
				if (left == 0 && cur+1 != k){
					cur++;
					left = values[cur];
				}
			}
		}
		else{
			for (int j=m-1; j >= 0; j--){
				if (matrix[i][j] == 'R') left--;
				matrix[i][j] = el[cur];
				if (left == 0 && cur+1 != k){
					cur++;
					left = values[cur];
				}
			}
		}
	}

	for (int i=0;i<n;++i){
		for (int j=0;j<m;++j) cout << matrix[i][j];
		cout << "\n";
	}
}

int main(){
#ifdef LOCAL
	freopen("P_input.txt", "r", stdin);
	//freopen("P_output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int t;
	cin >> t;
	for (int i=0; i < t; ++i) solve();

}