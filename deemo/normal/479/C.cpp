#include<iostream>
#include<algorithm>
#include<vector>
#include<utility>

using namespace std;

const int MAXN = 5e3 + 5;

int n, pick[MAXN];
pair<int, int>	vec[MAXN];

int main(){
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> vec[i].first >> vec[i].second;
	sort(vec, vec + n);
	int ans = 0;
	for (int i = 0; i < n; i++){
		if (i == 0 || vec[i].second >= pick[i - 1])
			ans = max(ans, vec[i].second), pick[i] = vec[i].second;
		else
			ans = max(ans, vec[i].first), pick[i] = vec[i].first;
	}
	cout << ans << "\n";
	return	0;
}