#include <algorithm>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <string>
#include <vector>
#include <cmath>
#include <queue>
#include <set>
#include <map>
using namespace std;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef long long ll;
typedef pair<ll,ll> pll;

struct interval {
	ll a,b;
	int ind;
	interval(ll a, ll b, int ind):a(a),b(b),ind(ind){};
};

struct end_first {
	bool operator()(const interval& x, const interval& y) {
		if(x.b != y.b)
			return x.b > y.b;
		return x.a > y.a;
	}
};

struct start_first {
	bool operator()(const interval& x, const interval& y) {
		if(x.a != y.a)
			return x.a > y.a;
		return x.b > y.b;
	}
};

priority_queue<interval,vector<interval>,start_first> S;
priority_queue<interval,vector<interval>,end_first> E;

const int N = 200005;
ll l[N],r[N];
pll L[N],b[N];
int ans[N]={0};

int main() {
	ios::sync_with_stdio(0); cin.tie();
	int n,m;
	cin >> n >> m;
	for(int i = 0; i < n; ++i)
		cin >> l[i] >> r[i];
	for(int i = 1; i < n; ++i) {
		S.push(interval(l[i]-r[i-1],r[i]-l[i-1],i-1));
	}
	fill(ans,ans+n,-1);
	for(int i = 0; i < m; ++i) {
		cin >> L[i].first;
		L[i].second = i;
	}
	sort(L,L+m);

	int assigned=0;
	for(int i = 0; i < m; ++i) {
		while(!S.empty() && S.top().a <= L[i].first) {
			E.push(S.top());
			S.pop();
		}
		while(!E.empty() && E.top().b < L[i].first)
			E.pop();

		if(!E.empty()) {
			ans[E.top().ind] = L[i].second;
			E.pop();
			++assigned;
		}
	}

	if(assigned != n-1) {
		cout << "No\n";
		return 0;
	}
	cout << "Yes\n";
	for(int i = 0; i < n-1; ++i)
		cout << ans[i]+1 << " ";
	cout << "\n";
	return 0;
}