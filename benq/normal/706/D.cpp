#include <bits/stdc++.h>

#define lb lower_bound
#define F0R(i, a) for (int i=0; i<a; i++)

using namespace std;

int Q;
multiset<int> ms;

int main() {
	ios_base::sync_with_stdio(false);
	cin >> Q;
	ms.insert(0);
	for (int i = 0; i < Q; i++) {
		char c; int t;
		cin >> c >> t;
		if (c == '+') ms.insert(t);
		else if (c == '-') ms.erase(ms.find(t));
		else {
			auto it = ms.begin(),ite = ms.end();
			ite = prev(ite);
			int pw = 0, j = 31;
			while(*it != *ite && j){
				j--;
				int q = (1 << j);
				if (q & t) {
					auto iter = ms.lb(pw + q);
					if (iter != ms.begin() && *it <= (*prev(iter)) && (*prev(iter)) <= *ite) ite = prev(iter);
					else pw += q;
				} else {
					auto iter = ms.lb(pw + q);
					if (iter != ms.end() && *it <= *iter && *iter <= *ite) {
						it = iter;
						pw += q;
					}
				}
			}
			cout << ((*it)^ t) << '\n';
		}
	}
}