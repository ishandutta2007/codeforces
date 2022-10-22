#include<iostream>
#include<algorithm>
#include<vector>
#include<string>

using namespace std;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int ans = 2e9;

	int n;	cin >> n;
	string s;	cin >> s;
	vector<int>	vec(n);
	for (int i = 0; i < n; i++)	cin >> vec[i];
	sort(vec.begin(), vec.end());
	for (int i = 0; i + 1 < n; i++){
		if (s[i] == 'R' && s[i + 1] == 'L')
			ans = min(ans, vec[i + 1] - vec[i] >> 1);
	}
	

	if (ans > 1e9)
		cout << "-1\n";
	else
		cout << ans << "\n";
	return 0;
}