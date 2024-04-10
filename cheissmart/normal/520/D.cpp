#include <bits/stdc++.h>
#define IO_OP std::ios::sync_with_stdio(0); std::cin.tie(0);
#define F first
#define S second
#define PB push_back
#define MP make_pair
#define EB emplace_back

using namespace std;

typedef long long ll;
typedef pair<int, int> pi;
typedef vector<int> vi;

const int INF = 1e9 + 7, M = 1e9 + 9;

map<pi, pi> m;
int x[100005], y[100005];

bool stable(int xx, int yy) {
	if(!m[{xx, yy}].F)
		return true;
	if(yy == 0)
		return true;
	return m[{xx, yy-1}].F || m[{xx-1, yy-1}].F || m[{xx+1, yy-1}].F;
}

bool ok(int xx, int yy) {
	if(!m[{xx, yy}].F)
		return false;
	bool ret = true;
	m[{xx, yy}].F = 0;
	ret = ret && stable(xx,yy+1);
	ret = ret && stable(xx-1,yy+1);
	ret = ret && stable(xx+1,yy+1);
	
	m[{xx, yy}].F = 1;
	return ret;
}

int main()
{
	IO_OP;
	
	int n;
	cin >> n;
	for(int i=0;i<n;i++) {
		cin >> x[i] >> y[i];
		m[{x[i], y[i]}] = {1, i};
	}
	set<int> s;
	for(auto p:m) {
		int xx = p.F.F, yy = p.F.S;
		int idx = p.S.S;
		if(ok(xx, yy))
			s.insert(idx);
	}
	vi v;
	bool who = 0; 
	while(s.size()) {
		int xx, yy;
		if(who) {
			int idx = *s.begin();
			s.erase(s.begin());
			v.PB(idx);
			xx = x[idx], yy = y[idx];
		} else {
			int idx = *prev(s.end());
			s.erase(prev(s.end()));
			v.PB(idx);
			xx = x[idx], yy = y[idx];
		}
		m[{xx, yy}].F = 0;
		if(ok(xx, yy-1))
			s.insert(m[{xx, yy-1}].S);	
		if(ok(xx-1, yy-1))
			s.insert(m[{xx-1, yy-1}].S);	
		if(ok(xx+1, yy-1))
			s.insert(m[{xx+1, yy-1}].S);
		if(m[{xx+1,yy}].F && !ok(xx+1, yy))
			s.erase(m[{xx+1,yy}].S);
		if(m[{xx+2,yy}].F && !ok(xx+2, yy))
			s.erase(m[{xx+2,yy}].S);
		if(m[{xx-1,yy}].F && !ok(xx-1, yy))
			s.erase(m[{xx-1,yy}].S);
		if(m[{xx-2,yy}].F && !ok(xx-2, yy))
			s.erase(m[{xx-2,yy}].S);
		who = !who;
		
	}
	ll p = 1, ans = 0;
	for(int i=v.size()-1;i>=0;i--) {
		ans += p * v[i] % M;
		ans %= M;
		p *= n;
		p %= M;
	}
	cout << ans << endl;
}