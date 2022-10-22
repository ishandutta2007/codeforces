#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define F first
#define S second

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	string s; cin >> s;
	int c0 = 0, c1 = 0;
	for (char c:s)
		if (c == 'o')
			c0++;
		else
			c1++;
	if (c0 < 2)
		cout << "YES\n";
	else{
		if (c1 % c0 == 0)
			cout << "YES\n";
		else
			cout << "NO\n";
	}
	return 0;
}