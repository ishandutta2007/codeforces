#include<bits/stdc++.h>

using namespace std;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	string s;
	cin >> s;
	int n = s.size();
	int i = 0;
	bool fl = 0;
	while (i < n && s[i] == 'a')	i++;
	for (; i < n; i++){
		if (s[i] == 'a')	break;
		s[i]--;
		fl = 1;
	}
	if (!fl)
		s[n - 1] = 'z';
	cout << s << "\n";
	return 0;
}