/**
 * Author: Sergey Kopeliovich (Burunduk30@gmail.com)
 */

#include <bits/stdc++.h>

using namespace std;

#define forn(i, n) for (int i = 0; i < (int)(n); i++)

typedef long long ll;

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0);
	int n, b;
	cin >> n >> b;
	ll res[n], last = 0;
	queue<ll> q;
	forn(i, n) {
		int t, d;
		cin >> t >> d;
		while (q.size() && q.front() <= t)
			q.pop();
		if ((int)q.size() <= b)
			q.push(res[i] = last = (q.size() ? last : t) + d);
		else
			res[i] = -1;
	}
	forn(i, n)
		cout << res[i] << " ";
}