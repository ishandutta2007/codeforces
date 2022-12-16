#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

int n, d;

inline int cp(int a, int b, int c, int d)
{
	return a*d-b*c;
}
inline int sgn(int a)
{
	return (a == 0 ? 0 : (a > 0 ? 1 : -1));
}

inline bool is_in(int x, int y)
{
	return (sgn(cp(1, 1, x, y-d)) <= 0
		 && sgn(cp(1, 1, x-d, y)) >= 0
		 && sgn(cp(1, -1, x, y-d)) >= 0
		 && sgn(cp(1, -1, x-(n-d), y-n) <= 0));
}

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0);
	cin >> n >> d;
	int m;
	cin >> m;
	int amt = 0;
	for(int i=0;i<m;++i)
	{
		int x, y;
		cin >> x>> y;
		cout << (is_in(x, y) ? "YES" : "NO") << endl;
	}

	return 0;
}