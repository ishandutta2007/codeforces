#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define F first
#define S second

const int MAXN = 1e5 + 10;

int n, c, d, s1, s2, pt[2][MAXN];
pii vec[MAXN], sec[MAXN];

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> c >> d;
	for (int i = 0; i < n; i++){
		int b, p; char t;	cin >> b >> p >> t;
		if (t == 'C')
			vec[s1++] = {p, b};
		else
			sec[s2++] = {p, b};
	}
	sort(vec, vec+s1);
	for (int i = 0; i < s1; i++)
		pt[0][i + 1] = max(pt[0][i], vec[i].S);
	sort(sec, sec+s2);
	for (int i = 0; i < s2; i++)
		pt[1][i + 1] = max(pt[1][i], sec[i].S);

	int ans = 0;
	int mx = 0;
	{
		for (int i = 0; i < s2; i++)
			if (sec[i].F <= d)
				mx = max(mx, sec[i].S);
	}
	for (int i = 0; i < s1 && vec[i].F <= c; i++){
		auto v = vec[i];
		int rem = c - v.F;
		int ret = v.S;
		if (mx)
			ans = max(ans, v.S+mx);
		
		int pos = lower_bound(vec, vec + i, make_pair(rem + 1, -1)) - vec;
		if (pos == 0) continue;
		ret += pt[0][pos];

		ans = max(ans, ret);
	}
	for (int i = 0; i < s2 && sec[i].F <= d; i++){
		auto v = sec[i];
		int rem = d - v.F;
		int ret = v.S;

		int pos = lower_bound(sec, sec + i, make_pair(rem + 1, -1)) - sec;
		if (pos == 0) continue;
		ret += pt[1][pos];

		ans = max(ans, ret);
	}

	cout << ans << "\n";
	return 0;
}