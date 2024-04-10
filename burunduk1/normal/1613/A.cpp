/**
 * Sergey Kopeliovich (burunduk30@gmail.com)
 */

#include <bits/stdc++.h>

using namespace std;

#define forn(i, n) for (int i = 0; i < (int)(n); i++)
#define all(a) (a).begin(), (a).end()

const double EPS = 1e-9;

void solve() {
	int x1, p1, x2, p2;
	cin >> x1 >> p1 >> x2 >> p2;
	int m = min(p1, p2);
	p1 -= m, p2 -= m;
	p1 = min(p1, 100);
	p2 = min(p2, 100);
	string s1 = to_string(x1) + string(p1, '0');
	string s2 = to_string(x2) + string(p2, '0');
	if (s1.size() > s2.size() || (s1.size() == s2.size() && s1 > s2)) puts(">");
	else if (s1.size() < s2.size() || (s1.size() == s2.size() && s1 < s2)) puts("<");
	else puts("=");
}

int main() {
	int tn;
	cin >> tn;
	while (tn--)
		solve();
}