#include <bits/stdc++.h>
#define IO_OP std::ios::sync_with_stdio(0); std::cin.tie(0);
#define F first
#define S second
#define PB push_back
#define MP make_pair
#define EB emplace_back
#define ALL(c) c.begin(),c.end()
#define INF int(1e9+7)

using namespace std;

typedef long long ll;
typedef pair<int, int> pi;
typedef vector<int> vi;

struct p{
    int a, b, c;
	p(){};
	p(int _a, int _b, int _c){
        a = _a, b = _b, c = _c;
	}
	bool operator<(const p t)const {
		return MP(MP(a, b), c) < MP(MP(t.a, t.b), t.c);
	}
};

int ans[200005];

int main()
{
	IO_OP;

	int t;
	cin >> t;
	while(t--) {
		int n;
		cin >> n;
		vector<p> v;
		for(int i=0;i<n;i++) {
			int x, y;
			cin >> x >> y;
			v.EB(x, y, i);
		}
        sort(ALL(v));
        int ct = 0, rmx = -1;
        for(int i=0;i<n;i++) {
            if(v[i].a > rmx) ct++;
            ans[v[i].c] = ct;
            rmx = max(rmx, v[i].b);
        }
        if(ct == 1) {
            cout << -1 << endl;
            continue;
        }
        for(int i=0;i<n;i++)
            cout << min(2, ans[i]) << " ";
        cout << endl;
	}
}