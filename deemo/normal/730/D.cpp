#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

const int MAXN = 2e5 + 10;
const int C = 1e5 + 1;

int n;
ll k, tl[MAXN], tr[MAXN], t[MAXN], sec[MAXN], sz;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> k;
	for (int i = 0; i < n; i++)	cin >> tr[i];
	for (int i = 0; i < n; i++)	cin >> t[i];
	for (int i = 0; i < n; i++){
		if (i)
			tl[i] = tr[i - 1], tr[i] += tr[i - 1];
		if (tr[i] - tl[i] > t[i]){
			cout << "-1\n";
			return 0;
		}
	}
	
	ll pos = 0, tm = 0, left = 0;
	for (int i = 0; i < n; i++){
		ll passed = 0;

		ll g = min(left, tr[i] - tl[i]);
		left -= g;
		pos += g;
		tm += g;
		passed = g;

		while (pos < tr[i]){
			ll rem = tr[i] - pos;
			ll remT = (t[i] - passed);
			if (rem == remT){
				if (sz < C){
					sec[sz++] = tm;
					left = k;

					ll g = min(left, tr[i] - pos);
					left -= g;
					pos += g;
					tm += g;
					passed += g;
				}
				else{
					sz += rem/k + bool(rem % k);
					left = (k - rem % k) % k;
					tm += rem;
					pos += rem;
					passed += rem;
				}
			}
			else{
				ll dif = min(rem, remT - rem);
				passed += dif * 2;
				pos += dif;
				tm += dif * 2;
			}
		}
	}

	cout << sz << "\n";
	if (sz < C){
		for (int i = 0; i < sz; i++)
			cout << sec[i] << " ";
		cout << "\n";
	}
	return 0;
}