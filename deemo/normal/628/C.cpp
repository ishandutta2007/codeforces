#include<iostream>
#include<string>
#include<algorithm>

using namespace std;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n, k;	cin >> n >> k;
	string s, ans;	cin >> s;	ans = s;

	for (int i = 0; i < n; i++){
		if ('z' - s[i] > s[i] - 'a'){
			ans[i] += min(k, 'z' - s[i]);
			k -= min(k, 'z' - s[i]);
		}
		else{
			ans[i] -= min(k, s[i] - 'a');
			k -= min(k, s[i] - 'a');
		}
	}
	if (k)
		cout << "-1\n";
	else
		cout << ans << "\n";
	return	0;
}