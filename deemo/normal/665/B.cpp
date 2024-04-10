#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

const int MAXN = 100 + 5;

int n, m, k, ans;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m >> k;
	vector<int>	a(k);
	for (int i = 0; i < k; i++)
		cin >> a[i], a[i]--;
	for (int i = 0; i < n * m; i++){
		int x;	cin >> x, x--;
		int pos = 0;
		while (a[pos] != x)	pos++;
		
		ans += pos + 1;
		a.erase(a.begin() + pos);
		a.insert(a.begin(), x);
	}
	cout << ans << "\n";
	return 0;
}