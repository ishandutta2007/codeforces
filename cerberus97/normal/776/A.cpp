/*
Hanit Banga
*/

#include <iostream>
#include <vector>
#include "set"

using namespace std;

#define pb push_back
#define fast_cin() ios_base::sync_with_stdio(false)

typedef long long ll;
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;

const int N = 1e5 + 5;

set <string> s;

int main()
{
	string s1, s2; int n;
	cin >> s1 >> s2 >> n;
	cout << s1 << ' ' << s2 << endl;

	s.insert(s1);
	s.insert(s2);

	for (int i = 1; i <= n; ++i)
	{
		cin >> s1 >> s2;
		s.erase(s1);
		s.insert(s2);
		cout << *s.begin() << ' ' << *s.rbegin() << endl;
	}
}