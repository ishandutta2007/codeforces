#include <bits/stdc++.h>

using namespace std;
using ll = long long;

void tc()
{
	vector <int> V;
	string S;
	int n, k, i, a, b, c, s;

	cin >> n >> k >> S;

	s = 0;

	for(i = 0; S[i] == 'L' && i < n; i ++);
	a = i;
	if(i == n){
		if(k == 0) cout << "0\n";
		else cout << 1 + (k - 1) * 2 << "\n";
		return;
	}

	for(c = 0; i < n; i ++){
		if(S[i] == 'W'){
			if(i != a && c == 0) s += 2;
			else s ++;
			if(c) V.push_back(c), c = 0;
		}
		else c ++;
	}
	b = c;

	sort(V.begin(), V.end());

	for(int &t: V){
		if(t <= k) k -= t, s += 2 * t + 1;
		else s += 2 * k, k = 0;
	}

	for(; k && b; k --, b --) s += 2;
	for(; k && a; k --, a --) s += 2;

	cout << s << "\n";
	return;
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int t;

	cin >> t;

	for(; t --; ){
		tc();
	}

	return 0;
}