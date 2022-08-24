#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define x first
#define y second
#define mp make_pair
#define db double
#define pb push_back
#define all(a) a.begin(), a.end()
char matrix[1000][1000];
int sum[5];
main(){
    srand(time(NULL));
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    for (int i=0; i < n; i++) for (int j=0; j < m; j++) cin >> matrix[i][j];
    int ans = 0;
	for (int i=0; i < m; i++){
		for (int j=0; j < 5; j++) sum[j]=0;
		for (int j=0;j<n;j++) sum[matrix[j][i]-'A']++;
		int mx = 0;
		for (int j=0; j < 5; j++) mx = max(mx, sum[j]);
		int t;
		cin >> t;
		ans += mx*t;
	}
	cout << ans;
}