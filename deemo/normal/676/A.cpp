#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

int main(){
	int n;	cin >> n;
	vector<int>	vec(n), pos(n);
	for (int i = 0; i < n; i++)
		cin >> vec[i], vec[i]--, pos[vec[i]] = i;
	
	int ans = 0;
	ans = max(pos[0], pos[n - 1]);
	ans = max(ans, n - 1 - pos[0]);
	ans = max(ans, n - 1 - pos[n - 1]);
	cout << ans << endl;
	return 0;
}