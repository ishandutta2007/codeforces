#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define F first
#define S second
#define X first
#define Y second

const int MAXN = 2500 + 10;

int n;
pii p[MAXN];
pii sec[MAXN]; int sz;

int half(pii p) {
    assert(p.X || p.Y);
    return p.Y > 0 || (p.Y == 0 && p.X < 0);
}

ll dot(pii a, pii b){ return 1ll*a.X*b.X + 1ll*a.Y*b.Y; }

ll cross(pii a, pii b){ return 1ll*a.X*b.Y - 1ll*a.Y*b.X; }

int nxt(int x){return x+1 == sz? 0: x+1;}

void solve() {
	cin >> n;
	for (int i = 0; i < n; i++) cin >> p[i].F >> p[i].S;

	ll ans = 0;
	for (int i = 0; i < n; i++){
		sz = 0;
		for (int j = 0; j < n; j++)
			if (i^j)
				sec[sz++] = {p[j].F-p[i].F, p[j].S-p[i].S};
		sort(sec, sec + sz, [](pii a, pii b) {
				return make_tuple(half(a), 0, dot(a, b)) < make_tuple(half(b), cross(a, b), dot(a, b));
				});

		ll temp = 0;
		int cur = 0;
		for (int j = 0; j < sz; j++){
			if (cur == j) cur = nxt(j);
			while (cur != j && cross(sec[j], sec[cur]) > 0) cur = nxt(cur);
			
			int ln = cur > j? cur-j: sz-(j-cur);
			temp += 1ll*(ln-1)*(ln-2)*(ln-3)/ 6;
		}
		ans += 1ll*(n-1)*(n-2)*(n-3)*(n-4)/ 24 - temp;
	}
	cout << ans << "\n";
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	//cout << fixed << setprecision(6);
	
	int te = 1;	
	//cin >> te;
	for (int w = 1; w <= te; w++){
		//cout << "Case #" << w << ": ";
		solve();
	}
	return 0;
}