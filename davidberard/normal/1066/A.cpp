#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

int solve_seg(int l, int r, int v)
{
	return (r-1)/v-(l)/v;
}

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0);
	int TT;
	cin >> TT;
	for(int tt=0;tt<TT;++tt)
	{
		int L, v, l, r;
		cin >> L >> v >> l >> r;
		cout << solve_seg(0, l, v)+solve_seg(r, L+1, v) << "\n";
	}

	return 0;
}