#include <bits/stdc++.h>
#define ll long long
#define db long double
#define x first
#define y second
#define mp make_pair
#define pb push_back
#define all(a) a.begin(), a.end()

using namespace std;

char matrix[60][60];

void solve() {
	int n, m;
	cin >> n >> m;
	for (int i=0;i<n;++i) for (int j=0;j<m;++j) cin >> matrix[i][j];




	int cnt = 0;
	for (int i=0;i<n;++i) for (int j=0; j < m; ++j) {
		if (matrix[i][j] == 'A') cnt++;
	}
	if (cnt==0) {
		cout << "MORTAL\n";
		return;
	}





	cnt = 0;
	for (int i=0;i<n;++i) for (int j=0; j < m; ++j) {
		if (matrix[i][j] == 'P') cnt++;
	}
	if (cnt==0) {
		cout << "0\n";
		return;
	}




	int A = 0;
	for (int i=0; i < n; ++i) {
		A += (matrix[i][0] == 'A');
	}
	if (A == n) {
		cout << "1\n";
		return;
	}
	A = 0;
	for (int i=0; i < n; ++i) {
		A += (matrix[i][m-1] == 'A');
	}
	if (A == n) {
		cout << "1\n";
		return;
	}
	A = 0;
	for (int i=0; i < m; ++i) {
		A += (matrix[0][i] == 'A');
	}
	if (A == m) {
		cout << "1\n";
		return;
	}
	A = 0;
	for (int i=0; i < m; ++i) {
		A += (matrix[n-1][i] == 'A');
	}
	if (A == m) {
		cout << "1\n";
		return;
	}

	bool tet = false;
	if (matrix[0][0] == 'A' || matrix[0][m-1] == 'A' || matrix[n-1][m-1] == 'A' || matrix[n-1][0] == 'A') tet = true;
	for (int i=0; i < n; ++i) {
		int Q = 0;
		for (int j=0;j<m;++j) if (matrix[i][j] == 'A') Q++;
		if (Q==m) tet = true;
 	}
 	for (int i=0; i < m; ++i) {
		int Q = 0;
		for (int j=0;j<n;++j) if (matrix[j][i] == 'A') Q++;
		if (Q==n) tet = true;
 	}
 	if (tet) {
 		cout << "2\n";
 		return;
 	}

 	for (int i=0; i < n; ++i) for (int j=0;j<m;++j) {
 		if (i==0 || i==n-1 || j==0 || j==m-1) {
 			if (matrix[i][j] == 'A'){
 				cout << "3\n";
 				return;
 			}
 		}
 	}
 	cout << "4\n";


}

int main(){
#ifdef LOCAL
	freopen("A_input.txt", "r", stdin);
	//freopen("A_output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int t;
	cin >> t;

	for (int i=0; i < t; ++i) solve();

}