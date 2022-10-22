#include<iostream>
#include<string>
#include<cmath>
#include<algorithm>

using namespace std;

int cnt[200];

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n;	cin >> n;
	string s;	cin >> s;
	for (int i = 0; i < n; i++)
		cnt[s[i]]++;

	int ans = 0;
	for (int i = 0; i < n; i++)
		if (s[i] != 'F'){
			cnt[s[i]]--;
			if (cnt['I'] == 0)	ans++;
			cnt[s[i]]++;
		}
	cout << ans << endl;
	return 0;	
}