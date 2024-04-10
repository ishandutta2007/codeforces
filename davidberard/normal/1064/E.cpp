#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

void getColor(int& n)
{
	string s;
	cin >> s;
	n = (s[0] == 'b' ? 0 : 1);
}

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0);
	int n;
	cin >> n;
	ll lo = 0, hi = 1e9;
	cout << 0 << " " << 0 << endl;
	int tc;
	getColor(tc);
	int ic = tc;
	for(int i=1;i<n;++i)
	{
		ll m = (lo+hi)/2;
		//printAmt(m);
		cout << m << " " << m << endl;
		getColor(tc);
		if(tc == ic) {
			lo = m;
		} else {
			hi = m;
		}
	}
	int m = (lo+hi)/2;
	cout << lo << " " << hi << " " << hi << " " << lo << endl;
	return 0;
}