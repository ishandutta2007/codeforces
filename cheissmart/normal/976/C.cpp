#include <bits/stdc++.h>
#define F first
#define S second
using namespace std;
typedef pair<int, int> pii;
pair<pii,int> a[300087];
bool cmp(pair<pii,int> & x, pair<pii,int> & y)
{
	if (x.F.F != y.F.F)
		return x.F.F < y.F.F;
	return x.F.S > y.F.S;
}
int main()
{
	int n;
	cin >> n;
	for(int i=0;i<n;i++) {
		cin >> a[i].F.F >> a[i].F.S;
		a[i].S = i;
	}
	sort(a, a+n, cmp);
	set<pii> s;
	for (int i = n - 1; i >= 0; i--) {
		set<pii>::iterator it = s.upper_bound({a[i].F.S,n});
		if (it != s.begin()) {
			it--;
			cout <<  it->S+1 << ' ' << a[i].S+1 << endl;
			return 0;
		}
		s.insert({a[i].F.S, a[i].S});
	}
	cout << "-1 -1" << endl;
}