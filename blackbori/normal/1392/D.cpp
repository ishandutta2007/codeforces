#include <bits/stdc++.h>

using namespace std;
using ll = long long;

string S;
ll D[202020];

ll calc(ll t, ll n)
{
	ll i, c;
	D[0] = 0;
	for(i = 1; i <= n; i ++){
		D[i] = 1e9;
		if(i >= 2){
			c = (S[t + i - 1] != 'R') + (S[t + i] != 'L');
			D[i] = min(D[i - 2] + c, D[i]);
		}
		if(i >= 3){
			c = (S[t + i - 2] != 'R') + (S[t + i - 1] != 'L') + (S[t + i] != 'L');
			D[i] = min(D[i - 3] + c, D[i]);

			c = (S[t + i - 2] != 'R') + (S[t + i - 1] != 'R') + (S[t + i] != 'L');
			D[i] = min(D[i - 3] + c, D[i]);
		}
		if(i >= 4){
			c = (S[t + i - 3] != 'R') + (S[t + i - 2] != 'R') + (S[t + i - 1] != 'L') + (S[t + i] != 'L');
			D[i] = min(D[i - 4] + c, D[i]);
		}
	}
	return D[n];
}


int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	ll t, n, i, s;

	cin >> t;

	for(; t --; ){
		cin >> n >> S;
		S.push_back(S[0]);
		S.push_back(S[1]);
		S.push_back(S[2]);
		s = n;
		for(i = 0; i <= 3; i ++){
			s = min(s, calc(i - 1, n));
		}
		cout << s << "\n";
	}

	return 0;
}