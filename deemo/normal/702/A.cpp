#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n;	cin >> n;
	vector<int>	vec(n);
	int ans = 0, cur = 0;
	for (int i = 0; i < n; i++){
		cin >> vec[i];
		if (!i || vec[i] > vec[i - 1])	cur++;
		else	cur = 1;
		ans = max(ans, cur);
	}
	cout << ans << endl;
	return 0;
}