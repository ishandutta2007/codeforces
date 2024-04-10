#include<iostream>
#include<cmath>
#include<vector>
#include<algorithm>

using namespace std;

int main(){
	int n, m;	cin >> m >> n;
	vector<int>	vec(n);
	for (int i = 0; i < n; i++)
		cin >> vec[i];
	sort(vec.begin(), vec.end());
	
	int ans = 1e9 + 2;
	for (int i = 0; i <= n - m; i++)
		ans = min(ans, vec[i + m - 1] - vec[i]);
	cout << ans << endl;
	return 0;
}