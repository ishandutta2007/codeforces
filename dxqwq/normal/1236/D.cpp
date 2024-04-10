#include <bits/stdc++.h>
#define ll long long
#define maxn 100100

using namespace std;
set<int> row[maxn], col[maxn];
int n, m, k, a, b, c, d, w, i, j;
ll need;

int maxi(set<int> &x, int y) {
	auto it=x.lower_bound(y);
	if(it==x.end()) return maxn;
	return *it;
}
int mini(set<int> &x, int y) {
	if(x.empty()) return -maxn;
	auto it=x.upper_bound(y);
	if(it==x.begin()) return -maxn;
	it--;
	return *it;
}

int main () {
	ios_base::sync_with_stdio(false);
	cin >> n >> m >> k;
	need = 1ll*n*m - k;
	for(i=0; i<k; i++) cin >> a >> b, row[a].emplace(b), col[b].emplace(a);
	a=b=w=1, c=m, d=n;
	while(a<=c&&b<=d) {
		if(w==1) {
			c = min(c, maxi(row[b], a) -1);
			need -= (c-a+1), w=2, b++;
		} else if(w==2) {
			d = min(d, maxi(col[c], b) -1);
			need -= (d-b+1), w=3, c--;
		} else if(w==3) {
			a = max(a, mini(row[d], c) +1);
			need -= (c-a+1), w=4, d--;
		} else {
			b = max(b, mini(col[a], d) +1);
			need -= (d-b+1), w=1, a++;
		}
	}
	cout << (need ? "No" : "Yes") << endl;
	return 0;
}