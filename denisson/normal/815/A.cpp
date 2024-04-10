#include <bits/stdc++.h>
                   
using namespace std;
           
typedef long long ll;
#define mp make_pair
#define pub push_back
#define x first
#define y second
#define all(a) a.begin(), a.end()
#define db long double

int n, m;
int a[111][111];

int main(){
    //freopen("input.txt", "r", stdin);
    //freopen("output1.txt", "w", stdout);
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n >> m;
    for (int i = 0; i < n; i++) for (int j = 0; j < m; j++) cin >> a[i][j];
    vector<pair<string, int> > ans;

	if (n < m){
		for (int i = 0; i < n; i++){
			int mi = a[i][0];
			for (int j = 0; j < m; j++) mi = min(a[i][j], mi);
			for (int s = 0; s < mi; s++) ans.pub(mp("row", i));
			for (int j = 0; j < m; j++) a[i][j] -= mi;
		}

		for (int j = 0; j < m; j++){
			int mi = a[0][j];
			for (int i = 0; i < n; i++) mi = min(mi, a[i][j]);
			for (int s = 0; s < mi; s++) ans.pub(mp("col", j));
			for (int i = 0; i < n; i++) a[i][j] -= mi;
		}
	} else {
		for (int j = 0; j < m; j++){
			int mi = a[0][j];
			for (int i = 0; i < n; i++) mi = min(mi, a[i][j]);
			for (int s = 0; s < mi; s++) ans.pub(mp("col", j));
			for (int i = 0; i < n; i++) a[i][j] -= mi;
		}

		for (int i = 0; i < n; i++){
			int mi = a[i][0];
			for (int j = 0; j < m; j++) mi = min(a[i][j], mi);
			for (int s = 0; s < mi; s++) ans.pub(mp("row", i));
			for (int j = 0; j < m; j++) a[i][j] -= mi;
		}
	}

	for (int i = 0; i < n; i++) for (int j = 0; j < m; j++) if (a[i][j] != 0) cout << -1, exit(0);

	cout << ans.size() << endl;
	for (auto c : ans) cout << c.x << ' ' << c.y + 1 << "\n";
}