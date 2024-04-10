#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void disjoint(int n) {
	if(n%2 == 1) {
		cout << "NO\n";
		return;
	}
	cout << "YES\n";
	set<int> all;
	for(int i = 1; i <= n; ++i) {
		all.insert(i);
	}
	vector<int> p(n+1);
	while(all.size()) {
		int lst = *all.rbegin();
		all.erase(lst);
		int o = 0;
		for(int j = 0; (1<<j) <= lst; ++j)
			if((lst&(1<<j)) != (1<<j))
				o ^= 1<<j;
		p[lst] = o;
		p[o] = lst;
		all.erase(o);
	}
	for(int i = 1; i <= n; ++i)
		cout << p[i] << ' ';
	cout << '\n';
}

void overlap(int n) {
	if((n&(n-1)) == 0 || n == 3 || n == 5) {
		cout << "NO\n";
		return;
	}
	cout << "YES\n";
	cout << "5 3 2 6 1";
	for(int i = 6; i <= n; ++i) {
		// power of two minus 1
		if((i&(i+1)) == 0 || i == n) {
			int tmp = i;
			for(int j = 0; ; ++j) {
				const int jj = 1<<j;
				if((tmp^jj) == 0)
					break;
				else if((tmp&jj) == jj)
					tmp ^= jj;
			}
			cout << ' ' << tmp;
		} else
			cout << ' ' << i+1;
	}
	cout << '\n';
}

int main() {	
	ios::sync_with_stdio(0), cin.tie(0);
	int n;
	cin >> n;
	disjoint(n);
	overlap(n);
}