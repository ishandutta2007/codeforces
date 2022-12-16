#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<ll, ll> pii;

/*
 * sequence ai is the prefix sum of bi.
 * turns out that the operation a{i+1} = (a{i}+a{i+2}-a{i+1}) is equivalent to 
 *   swapping b{i+1} and b{i+2} because a{i+2}-a{i+1} = b{i+2}
 */

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0);
	int N;
	ll last;
	cin >> N;
	vector<ll> a, b;
	ll aa, bb;
	cin >> last;
	aa = last;
	for(int i=1;i<N;++i) {
		ll v;
		cin >> v;
		a.push_back(v-last);
		last = v;
	}
	cin >> last;
	if(last != aa) {
		cout << "No" << endl;
		return 0;
	}
	for(int i=1;i<N;++i) {
		ll v;
		cin >> v;
		b.push_back(v-last);
		last = v;
	}
	sort(a.begin(),a.end());
	sort(b.begin(),b.end());
	for(int i=0;i<N-1;++i) {
		if(a[i] != b[i]) {
			cout << "No" << endl;
			return 0;
		}
	}
	cout << "Yes" << endl;
	return 0;
}