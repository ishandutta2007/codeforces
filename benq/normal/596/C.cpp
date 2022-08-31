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

set<pii> points[200001];
int yvals[100001], xvals[100001];
vector<pii> answers;

int main() {
	int n;
	cin >> n;
	F0R(i,n) {
		pii x;
		cin >> x.f >> x.s;
		points[x.s-x.f+100000].insert(x);
	}
	F0R(i,n) {
		int s;
		cin >> s;
		if (points[s+100000].size() == 0) {
			cout << "NO";
			return 0;
		}
		pii t = *points[s+100000].begin();
		points[s+100000].erase(points[s+100000].begin());
		if (t.s == yvals[t.f] && t.f == xvals[t.s]) {
			yvals[t.f] ++;
			xvals[t.s] ++;
			answers.pb(t);
		} else {
			cout << "NO";
			return 0;
		}
	}
	cout << "YES" << endl;
	F0R(i,n) cout << answers[i].f << " " << answers[i].s << endl;
	return 0;
}