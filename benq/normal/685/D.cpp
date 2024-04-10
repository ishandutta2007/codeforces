#include <bits/stdc++.h>

using namespace std;
 
typedef pair<int, int> pii;

#define F0R(i, a) for (int i=0; i<a; i++)
#define pb push_back
#define f first
#define s second

int n,k, val[30000000];
long long ans[100001];
vector<pair<pii,int>> p;
vector<pii> p1;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> n >> k; 
	F0R(i,n) {
		int x,y;
		cin >> x >> y;
		p1.pb({y,x});
	}
	sort(p1.begin(),p1.end());
	int lst = -1000000300, cur = 0;
	for (auto a: p1) {
		if (a.f-lst < k) cur = cur+a.f-lst;
		else cur += k;
		p.pb({{a.s-k+1,cur},1});
		p.pb({{a.s+1,cur},-1});
		lst = a.f;
	}
	sort(p.begin(),p.end());
	for (auto a: p) F0R(i,k) {
		int i1 = a.f.s-k+1+i;
		ans[val[i1]] += a.f.f;
		ans[val[i1] += a.s] -= a.f.f;
	}
	F0R(i,n) cout << ans[i+1] << " ";
}