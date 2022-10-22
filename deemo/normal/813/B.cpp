#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define F first
#define S second

const int MAXN = 2e6 + 10;
const ll INF = (ll)1e18 + 10;

ll x, y, l, r;
ll vec[MAXN], sec[MAXN], s1, s2, gec[MAXN], s3;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> x >> y >> l >> r;
	vec[s1++] = 1;
	while (vec[s1-1] <= INF/x) vec[s1] = vec[s1-1]*x, s1++;
	sec[s2++] = 1;
	while (sec[s2-1] <= INF/y) sec[s2] = sec[s2-1]*y, s2++;

	for (int i = 0; i < s1; i++)
		for (int j = 0; j < s2; j++)
			if (l <= vec[i]+sec[j] && vec[i]+sec[j] <= r)
				gec[s3++] = vec[i]+sec[j];

	ll mx = 0;
	gec[s3++] = l-1, gec[s3++] = r+1;
	sort(gec, gec+s3);
	for (int i = 0; i + 1 < s3; i++)
		mx = max(mx, gec[i+1] - gec[i] - 1);
	cout << mx << "\n";
	return 0;
}