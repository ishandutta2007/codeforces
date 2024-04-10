#include<iostream>
#include<algorithm>

using namespace std;

const int MAXN = 1e5 + 10;

int n, x[MAXN], y[MAXN], cx[MAXN], cy[MAXN];

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++){
		cin >> x[i] >> y[i];
		cx[x[i]]++, cy[y[i]]++;
	}
	for (int i = 0; i < n; i++){
		int ret = n - 1;
		ret += cx[y[i]];
		cout << ret << " " << 2 * (n - 1) - ret << "\n";
	}
	return	0;		
}