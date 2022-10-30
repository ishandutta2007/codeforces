#include <iostream>
#include <cstring>
#include <set>
using namespace std;



int main() {
	int n, m;
	cin >> n >> m;
	set<int> s;
	for (int i = 1; i <= n; i++) s.insert(i);
	
	int winners[300004];
	memset(winners, 0, sizeof(winners));
	for (int i = 0; i < m; i++) {
		int L, R, winner;
		cin >> L >> R >> winner;

		set<int>::iterator lit = s.lower_bound(L);
		set<int>::iterator rit = s.upper_bound(R);
		for (set<int>::iterator it = lit; it != rit; it++) {
			if (*it != winner) {
				winners[*it] = winner;
				//cout << "setting " << *it << " won by " << winner << endl;
			}
		}
		s.erase(lit, rit);
		s.insert(winner);
		//cout << "remain: " << s.size() << endl;
	}
	for (int i = 1; i <= n; i++) {
		if (i != 1) cout << " ";
		cout << winners[i];
	}
	cout << endl;

}