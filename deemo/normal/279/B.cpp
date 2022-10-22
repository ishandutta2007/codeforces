#include<iostream>
#include<cmath>
#include<algorithm>
#include<vector>

using namespace std;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n, t;
	cin >> n >> t;
	vector<int>	vec(n), sec;
	for (int i = 0; i < n; i++)	cin >> vec[i];
	int sum = 0;
	for (int i = 0; i < n; i++){
		sum += vec[i];
		sec.push_back(sum);
	}

	int ans = 0;
	sum = 0;
	for (int i = 0; i < n; i++){
		int temp = (upper_bound(sec.begin(), sec.end(), sum + t) - (sec.begin() + i));
		ans = max(ans, temp);
		sum += vec[i];
	}
	cout << ans << endl;
	return 0;
}