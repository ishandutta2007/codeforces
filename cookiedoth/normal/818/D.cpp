#include <iostream>
#include <set>

using namespace std;

const int mx = 2000000;
int n, A, cnt[mx], clr;
set<pair<int, int> > s;

int main()
{
	cin >> n >> A;
	for (int i = 0; i < mx; ++i) {
		cnt[i] = 0;
		if (i != A && i != 0)
			s.insert({ 0, i });
	}
	for (int i = 0; i < n; ++i) {
		cin >> clr;
		if (clr != A) {
			cnt[clr]++;
			if (s.find({ cnt[clr] - 1, clr }) != s.end()) {
				s.erase({ cnt[clr] - 1, clr });
				s.insert({ cnt[clr], clr });
			}
		}
		else {
			cnt[A]++;
			while (!s.empty() && (*s.begin()).first < cnt[A])
				s.erase(s.begin());
		}
	}
	if (!s.empty())
		cout << (*s.begin()).second << endl;
	else
		cout << -1 << endl;
	return 0;
}