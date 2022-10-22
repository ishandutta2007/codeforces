#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define F first
#define S second

int n, m;
string s, t;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m;
	cin >> s >> t;

	bool fl = 0;
	for (char ch:s)
		if (ch == '*')
			fl = 1;
	if (!fl){
		if (s == t)
			cout << "YES\n";
		else
			cout << "NO\n";
	}
	else{
		int ind = 0;
		for (int i = 0; i < n; i++)
			if (s[i] == '*'){
				ind = i;
				break;
			}
		
		if (m >= n - 1 && s.substr(0, ind) == t.substr(0, ind) &&
				s.substr(ind+1) == t.substr(m - (n - ind - 1)))
			cout << "YES\n";
		else
			cout << "NO\n";
	}
	return 0;
}