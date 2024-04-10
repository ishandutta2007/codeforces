#include <bits/stdc++.h>
#define ll long long
#define db long double

using namespace std;
main(){
#ifdef LOCAL
	freopen("H_input.txt", "r", stdin);
	//freopen("B_output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n;
	string s;
	cin >> n >> s;
	int open = 0, close = 0;
	for (int i=0;i<n;++i){
		if (s[i] == '(') open++;
		else close++;
	}
	if (open != close){
		cout << "No";
		return 0;
	}
	int min_bal = 0, bal = 0;
	for (int i=0; i < n; ++i){
		if (s[i] == '(') bal++;
		else bal--;
		min_bal = min(min_bal, bal);
	}
	if (min_bal < -1){
		cout << "No";
	}
	else cout << "Yes";
}