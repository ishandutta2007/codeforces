#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pll = pair <ll, ll>;
using plll = tuple <ll, ll, ll>;

vector <pll> V;
vector <plll> Q;
ll A[10101];
ll tc, n, s, i, t, f;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> tc;

	for(; tc --; ){
		cin >> n; s = 0;
		Q.clear(); V.clear(); f = 0;
		for(i = 1; i <= n; i ++){
			cin >> A[i];
			if(i > 1){
				t = i - A[i] % i; if(t == i) t = 0;
				Q.emplace_back(1, i, t);
				A[1] -= t; A[i] += t;
				Q.emplace_back(i, 1, A[i] / i);
				A[1] += A[i]; A[i] = 0;
			}
		}
		if(A[1] % n != 0){
			cout << "-1\n";
			continue;
		}
		s = A[1] / n;
		for(i = 2; i <= n; i ++){
			Q.emplace_back(1, i, s);
		}
		cout << Q.size() << "\n";
		for(auto &[i, j, x]: Q){
			cout << i << " " << j << " " << x << "\n";
		}
	}

	return 0;
}