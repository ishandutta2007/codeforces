#include <bits/stdc++.h>
using namespace std;
 
#define ll long long
#define mp make_pair
#define pb push_back
#define pii pair <int, int>
#define vi vector<int>
 
#define FOR(i, a, b) for (int i=a; i<b; i++)
#define F0R(i, a) for (int i=0; i<a; i++)
 
#define f first
#define s second
 
const int MOD = 1000000007;
const int MAX = 10000005;

int n, ans=0;
vector<pii> negatives, positives;

int main() {
	cin >> n;
	F0R(i,n) {
		int a,b;
		cin >> a >> b;
		if (a<0) negatives.pb(mp(-1*a,b));
		else positives.pb(mp(a,b));
	}
	sort(negatives.begin(), negatives.end());
	sort(positives.begin(), positives.end());
	if (positives.size() == negatives.size()) F0R(i,positives.size()) ans += (positives[i].s+negatives[i].s);
	else if (positives.size() > negatives.size()) {
		F0R(i,negatives.size()) ans += (positives[i].s+negatives[i].s);
		ans += positives[negatives.size()].s;
	} else {
		F0R(i,positives.size()) ans += (positives[i].s+negatives[i].s);
		ans += negatives[positives.size()].s;
	}
	cout << ans;
	return 0;
}