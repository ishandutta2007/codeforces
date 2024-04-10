#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
typedef long long ll;

int main() {
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	ll a, b;
	cin >> a >> b;
	ll sum = 0;
	ll notes = 0;
	while(sum+notes+1 <= a+b) {
		++notes;
		sum += notes;
	}
	set<int> possible;
	for(int i = 1; i <= notes; ++i)
		possible.insert(i);

	vector<int> read_a;
	while(a && possible.size()) {
		if(*possible.rbegin() < a) {
			int take = *possible.rbegin();
			a -=take;
			possible.erase(take);
			read_a.push_back(take);
		} else {
			possible.erase(a);
			read_a.push_back(a);
			a = 0;
		}
	}

	cout << read_a.size() << "\n";
	for(int x : read_a)
		cout << x << " ";
	cout << "\n";

	cout << possible.size() << "\n";
	for(int x : possible)
		cout << x << " ";
	cout << "\n";
	
}