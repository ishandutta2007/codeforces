#include<iostream>
#include<string>
#include<cmath>
#include<algorithm>
#include<vector>

using namespace std;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	string s;	cin >> s;
	int ans = 0;
	for (int i = 0; i < s.size(); i++)
		if (s[i] == '1')	ans++;

	int cnt = 0;
	bool fl = 0;
	for (int i = 0; i < s.size();){
		int j = i;
		while (j < s.size() && s[j] == '0')	j++;
		int t = j;
		while (j < s.size() && s[j] == '1')	j++;

		if (t - i > 1)	fl = 0;
		if (j - t == 0)	break;
		if (j - t == 1)	cnt++;
		if (j - t > 1){
			if (fl == 0)	cnt++;
			cnt++;
			fl = 1;
		}
		i = j;
	}
	ans = min(ans, cnt);
	cout << ans << endl;
	return 0;
}