#include <bits/stdc++.h>
#define ll long long
#define db long double
#define x first
#define y second
#define mp make_pair
#define pb push_back
#define all(a) a.begin(), a.end()

using namespace std;

int ans[500][500];

int main(){
#ifdef LOCAL
	freopen("B_input.txt", "r", stdin);
	//freopen("B_output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int r, c;
	cin >> r >> c;
	if (r==1 && c==1) {
		cout << 0;
		exit(0);
	}

	if (r < c) {
		for (int i = 1; i <= r; ++i) {
			for (int j=r+1; j <= r+c; ++j) {
				ans[i-1][j-r-1] = i*j;
			}
		}
	}
	else{
		for (int i = 1; i <= c; ++i) {
			for (int j=c+1; j <= r+c; ++j) {
				ans[j-c-1][i-1] = i*j;
			}
		}
	}

	for (int i=0;i<r;++i){
		for (int j=0;j<c;++j) cout << ans[i][j] << " ";
		cout << "\n";
	}



}