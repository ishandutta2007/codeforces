#include <bits/stdc++.h>

using namespace std;
using ll = long long;

void tc()
{
	int n, i, a, m, s;

	cin >> n;

	m = 0; s = 0;
	for(i = 1; i <= n; i ++){
		cin >> a;
		if(m > a) continue;
		else if(m == a){
			m = a + 1; s ++;
		}
		else{
			m = a; s ++;
		}
	}

	cout << s << "\n";
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int t;
//*
	cin >> t;
/*/
	t = 1;
//*/
	for(; t --; ) tc();

	return 0;
}