#include<bits/stdc++.h>

using namespace std;

const int MAXN = 200;

int sec[MAXN], sz;

int main(){
	string s;	cin >> s;
	for (int i = 0; i < s.size(); i++)
		if (s[i] == 'A' || s[i] == 'E' || s[i] == 'I' || s[i] == 'O' ||
				s[i] == 'U' || s[i] == 'Y')	sec[sz++] = i;
	int ans = 0;
	for (int i = 0; i < sz; i++)
		ans = max(ans, sec[i] - (i?sec[i - 1]:-1));
	if (sz)
		ans = max(ans, (int)s.size() - sec[sz - 1]);
	else
		ans = max(ans, (int)s.size() + 1);
	cout << ans << "\n";
	return 0;
}