#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

typedef long long ll;

const int MAXM =10 + 4;
const int MAXN = 2e5 + 20;

int n, m, cn[MAXM];

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m;
	for (int i = 0; i < n; i++){
		int t;	cin >> t;
		cn[t]++;
	}

	ll ans = 0;
	for (int i = 0; i < MAXM; i++)
		for (int j = i + 1; j < MAXM; j++)
			ans += cn[i] * cn[j];
	cout << ans << "\n";
	return	0;
}