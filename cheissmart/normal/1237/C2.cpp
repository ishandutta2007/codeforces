#include <bits/stdc++.h>
#define IO_OP std::ios::sync_with_stdio(0); std::cin.tie(0);
#define F first
#define S second
#define V vector
#define PB push_back
#define MP make_pair
#define EB emplace_back
#define ALL(v) (v).begin(), (v).end()
#define debug(x) cerr << #x << " is " << x << endl
#define int ll
	
using namespace std;

typedef long long ll;
typedef pair<int, int> pi;
typedef V<int> vi;

const int INF = 1e9 + 7, N = 50004;

struct P{
	int x, y, z, i;
};

bool cmp(P p1, P p2) {
	return p1.x < p2.x || (p1.x == p2.x && p1.y < p2.y) || (p1.x == p2.x && p1.y == p2.y && p1.z < p2.z) ;
}

int goo(V<P>& v) {
	for(int i=0;i+1<v.size();i+=2)
		cout << v[i].i << " " << v[i+1].i << endl;
	if(v.size()&1) return v.back().i;
	return -1;
}

int go(V<P>& v) {
	vi ttt;
	for(int i=0;i<v.size();i++) {
		V<P> tt({v[i]});
		while(i+1<v.size() && v[i+1].y == v[i].y)
			tt.PB(v[++i]);
		int r = goo(tt);
		if(r > 0) ttt.PB(r);
	}
	for(int i=0;i+1<ttt.size();i+=2)
		cout << ttt[i] << " " << ttt[i+1] << endl;
	if(ttt.size()&1) return ttt.back();
	return -1;
}

int32_t main()
{
	IO_OP;
	
	int n;
	cin >> n;
	V<P> a(n);
	for(int i=0;i<n;i++) {
		cin >> a[i].x >> a[i].y >> a[i].z;
		a[i].i = i + 1;
	}
	sort(ALL(a), cmp);
	vi t;
	for(int i=0;i<n;i++) {
		V<P> v({a[i]});
		while(i+1 < n && a[i+1].x == a[i].x)
			v.PB(a[++i]);
		int r = go(v);
		if(r > 0) t.PB(r); 
	}
	for(int i=0;i+1<t.size();i+=2)
		cout << t[i] << " " << t[i+1] << endl;
}