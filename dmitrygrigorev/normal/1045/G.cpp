#include <bits/stdc++.h>
           
using namespace std;
           
typedef long long ll;
#define mp make_pair
#define pb push_back
#define x first
#define y second
#define all(a) a.begin(), a.end()
#define db long double

int n, k;
pair<int, pair<int, int> > a[100007];
vector<int> t[100007];
vector<int> fen[100007];
map<int, int> g;

int getFen2(int v, int x){
	int ans = 0;
	for (; x >= 0; x = (x & (x + 1)) - 1) ans += fen[v][x];
	return ans;
}

int getFen(int v, int vl, int vr){
	if (vl == 0) return getFen2(v, vr);
	return getFen2(v, vr) - getFen2(v, vl - 1);
}

void upFen(int v, int x){
	for (; x < fen[v].size(); x = (x | (x + 1))) fen[v][x]++;
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	//freopen("input.txt", "r", stdin);
	cin >> n >> k;
	for (int i = 0; i < n; i++) cin >> a[i].y.x >> a[i].x >> a[i].y.y;
	sort(a, a + n);
	reverse(a, a + n);
	ll ans = 0;

	int sz = 0;
	for (int i = 0; i < n; i++){
		int v;
		if (g.find(a[i].y.y) != g.end()) v = g[a[i].y.y];
		else v = sz++, g[a[i].y.y] = v;
		t[v].pb(a[i].y.x); 
	}

	for (int i = 0; i < sz; i++){
		sort(all(t[i]));
		t[i].resize(unique(all(t[i])) - t[i].begin());
		fen[i].resize(t[i].size());
	}


	for (int i = 0; i < n; i++){
		for (int c = a[i].y.y - k; c <= a[i].y.y + k; c++){
			int uk;
			if (g.find(c) == g.end()) continue;
			uk = g[c];
			//cout << a[i].y.x << ' ' << c << endl;
			int x1 = a[i].y.x - a[i].x, x2 = a[i].y.x + a[i].x;
			int vl = -1, vr = t[uk].size();
			while(vl + 1 < vr){
				int vm = (vl + vr) >> 1;
				if (t[uk][vm] < x1)
					vl = vm;
				else
					vr = vm;
			}
			if (vr == t[uk].size()) continue;
			int l = vr;
			vl = -1, vr = t[uk].size();
			while(vl + 1 < vr){
				int vm = (vl + vr) >> 1;
				if (t[uk][vm] > x2)
					vr = vm;
				else
					vl = vm;
			}
			if (vl == -1) continue;
			int r = vl;
			//cout << a[i].y.x << ' ' << c << ' ' << l << ' ' << r << ' ' << getFen(uk, l, r) << endl;
			ans += getFen(uk, l, r);
		}
		int uk = g[a[i].y.y];
		int vl = -1, vr = t[uk].size();
		while(vl + 1 < vr){
			int vm = (vl + vr) >> 1;
			if (t[uk][vm] > a[i].y.x)
				vr = vm;
			else
				vl = vm;
		}
		upFen(uk, vl);
	}

	cout << ans; 
}