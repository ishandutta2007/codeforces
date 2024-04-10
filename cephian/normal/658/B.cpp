#include <iostream>
#include <set>

using namespace std;
typedef pair<int,int> pii;

int n,k,q;
set<pii> s;
int l[150005];

int main() {
	ios::sync_with_stdio(0);
	cin >> n >> k >> q;
	for(int i = 1; i <= n; ++i) {
		cin >> l[i];
	}

	for(int i = 0; i < q; ++i) {
		int t,id;
		cin >> t >> id;
		pii p(l[id],id);
		if(t==1) {
			s.insert(p);
			if(s.size() > k)
				s.erase(s.begin());
		} else {
			if(s.count(p))
				cout << "YES\n";
			else cout << "NO\n";
		}
	}
	return 0;
}