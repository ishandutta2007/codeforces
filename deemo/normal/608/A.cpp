#include<iostream>
#include<algorithm>
#include<vector>
#include<utility>

using namespace std;

int main(){
	int n, s;	cin >> n >> s;
	vector<int>	vec(2000);
	for (int i = 0; i < n; i++){
		int a, b;	cin >> a >> b;
		vec[a] = max(vec[a], b);
	}
	int cur = s, ans = 0;
	while (cur){
		ans += max(0, vec[cur] - ans);
		cur--;
		ans++;
	}
	cout << ans << endl;
	return 0;
}