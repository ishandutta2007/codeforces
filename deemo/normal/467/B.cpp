#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

const int MAXN = 20 + 2;
const int MAXM = 1e3 + 10;

int n, m, k, vec[MAXM];

int main(){
	cin >> n >> m >> k;
	for (int i = 0; i < m; i++)
		cin >> vec[i];
	int x;	cin >> x;
	int ans = 0;
	for (int i = 0; i < m; i++){
		int y = x ^ vec[i];
		if (__builtin_popcount(y) <= k)	ans++;
	}
	cout << ans << "\n";
	return	0;	
}