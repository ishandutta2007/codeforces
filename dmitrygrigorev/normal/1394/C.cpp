#include <bits/stdc++.h>
#define ll long long
#define db float
#define ld float
#define x first
#define y second
#define mp make_pair
#define pb push_back
#define all(a) a.begin(), a.end()

using namespace std;

struct point{
	ld x, y;
	int Q;
	point() {}
	point(ld x1, ld y1, int tp) { x = x1, y = y1; Q=tp;}
	point(ld x1, ld y1) { x = x1, y = y1;}
	ld operator% (point nxt) const { return x * nxt.y - y * nxt.x; }
	ld operator* (point nxt) const { return x * nxt.x + y * nxt.y; }
	point operator- (point nxt) const { return point(x - nxt.x, y - nxt.y); }
	point operator+ (point nxt) const { return point(x + nxt.x, y + nxt.y); }
};
struct line{
	ld a, b, c;
	point s, t;
	line() {}
	line(point s1, point t1){
		s = s1, t = t1;
	 	a = t.y - s.y;
		b = s.x - t.x;
		c = (t.x - s.x) * s.y - s.x * (t.y - s.y);
		if ((t - s) % point(a, b) < 0){
			a = -a, b = -b, c = -c;
		}
	}
};

const db BOX = 1e18;

const ld pi = acos(-1.0);
bool equal(point s, point t){
	return (s % t) == 0 && (s * t) > 0;
}
bool cmp(line s, line t){
	if (equal(s.t - s.s, t.t - t.s)){
		if (abs(s.s.x) == BOX) return 0;
		if (abs(t.s.x) == BOX) return 1;
		return (s.t - s.s) % (t.s - s.s) < 0;
	}
	ld val1 = atan2(s.b, s.a);
	ld val2 = atan2(t.b, t.a);
	if (val1 < 0) val1 += pi * 2;
	if (val2 < 0) val2 += pi * 2;
	return val1 < val2;
}	

point crossLineLine(line s, line t){
	ld x = (t.c * s.b - s.c * t.b) / (s.a * t.b - s.b * t.a);
	ld y = (t.c * s.a - s.c * t.a) / (s.b * t.a - t.b * s.a);
	return point(x, y);
}
pair<int, int> halfplanesIntersection(vector<line> &a){
	//==========BOX=================
	//==============================
	vector<line> q;
	for (int i = 0; i < a.size(); i++){
		if (i == 0 || !equal(a[i].t - a[i].s, a[i - 1].t - a[i - 1].s)) q.pb(a[i]);
	}
	//for (auto c : q){
	//	cout << "Line " << fixed << c.a << ' ' << c.b << ' ' << c.c << endl;
	//}
	vector<int> st;
	for (int it = 0; it < 2; it++){
		for (int i = 0; i < q.size(); i++){
			while(st.size() > 1){
				int j = st.back(), k = st[(int)st.size() - 2];
				if (((q[i].t - q[i].s) % (q[j].t - q[j].s)) == 0) break;
				auto pt = crossLineLine(q[i], q[j]);
				if ((q[k].t - q[k].s) % (pt - q[k].s) > 0) break;
				st.pop_back();
			}
			st.pb(i);
		}	
	}
    vector<int> was((int)a.size(), -1);
    bool ok = 0;
    for (int i = 0; i < st.size(); i++){
    	int uk = st[i];
    	if (was[uk] == -1){
    		was[uk] = i;
    	} else {
    		st = vector<int>(st.begin() + was[uk], st.begin() + i);
    		ok = 1;
    		break;
    	}
    } 
    if (!ok){
 		return mp(-1, -1);
    }
    point ans = point(0, 0);
    for (int i = 0; i < st.size(); i++){
    	line l1 = q[st[i]], l2 = q[st[(i + 1) % (int)st.size()]];
    	ans = ans + crossLineLine(l1, l2);
    }
    ans.x /= (ld)st.size();
    ans.y /= (ld)st.size();
    for (int i = 0; i < a.size(); i++){
    	line l = a[i];
    	if ((l.t - l.s) % (ans - l.s) <= 0) return mp(-1, -1);
    }
    return mp(ans.x, ans.y);
}

int gd(pair<int, int> a, pair<int, int> b) {
	int dx = (a.x-1) - b.x;
	int dy = (a.y-1)-b.y;

	if (dx > dy) swap(dx, dy);

	if (dx < 0 && dy > 0) return abs(dx) + abs(dy);
	return max(abs(dx), abs(dy));
}

main(){
#ifdef LOCAL
	freopen("A_input.txt", "r", stdin);
	//freopen("A_output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;

	vector<pair<int, int> > v;
	for (int i = 0; i < n; ++i) {
		string s;
		cin >> s;
		int a = 0,b = 0;
		for (auto x : s) {
			if (x=='B') a++;
			else b++;
		}
		v.pb(mp(a+1, b+1));
	}

	sort(all(v));

	int L = -1, R = 500000;
	int M = 1;

	vector<line> av;

	for (auto x : v) {

		point a = {x.x - M, x.y+M, 0};
		point b = {x.x + M, x.y+M, 1};
		point c = {x.x + M, x.y-M, 2};
		point d = {x.x - M, x.y-M, 3};
		av.pb({b, a});
		av.pb({a, d});
		av.pb({d, c});
		av.pb({c, b});
		a = {x.x, x.y+M, 4};
		b = {x.x + M, x.y, 5};
		c = {x.x, x.y-M, 6};
		d = {x.x - M, x.y, 7};
		av.pb({a, d});
		av.pb({c, b});
	}

	av.pb(line(point(-BOX, -BOX, 8), point(BOX, -BOX, 8)));
	av.pb(line(point(-BOX, BOX, 8), point(-BOX, -BOX, 8)));
	av.pb(line(point(BOX, -BOX, 8), point(BOX, BOX, 8)));
	av.pb(line(point(BOX, BOX, 8), point(-BOX, BOX, 8)));


	sort(all(av), cmp);

	int ax, ay;
	int lm = 1;

	while (R-L>1) {
		M = (L+R)/2;
		int delta = M-lm;

		for (auto& l : av) {
			if (l.s.Q == 0) {
				l.s.x -= delta, l.s.y+=delta;
			}
			if (l.s.Q == 1) {
				l.s.x += delta, l.s.y+=delta;
			}
			if (l.s.Q == 2) {
				l.s.x += delta, l.s.y-=delta;
			}
			if (l.s.Q == 3) {
				l.s.x -= delta, l.s.y-=delta;
			}

			if (l.s.Q == 4) {
				l.s.y+=delta;
			}
			if (l.s.Q == 5) {
				l.s.x += delta;
			}
			if (l.s.Q == 6) {
				l.s.y-=delta;
			}
			if (l.s.Q == 7) {
				l.s.x -= delta;
			}

			if (l.t.Q == 0) {
				l.t.x -= delta, l.t.y+=delta;
			}
			if (l.t.Q == 1) {
				l.t.x += delta, l.t.y+=delta;
			}
			if (l.t.Q == 2) {
				l.t.x += delta, l.t.y-=delta;
			}
			if (l.t.Q == 3) {
				l.t.x -= delta, l.t.y-=delta;
			}

			if (l.t.Q == 4) {
				l.t.y+=delta;
			}
			if (l.t.Q == 5) {
				l.t.x += delta;
			}
			if (l.t.Q == 6) {
				l.t.y-=delta;
			}
			if (l.t.Q == 7) {
				l.t.x -= delta;
			}

			l.a = l.t.y - l.s.y;
			l.b = l.s.x - l.t.x;
			l.c = (l.t.x - l.s.x) * l.s.y - l.s.x * (l.t.y - l.s.y);
			if ((l.t - l.s) % point(l.a, l.b) < 0){
				l.a = -l.a, l.b = -l.b, l.c = -l.c;
			}
		}

		//sort(all(av), cmp);

		auto res = halfplanesIntersection(av);
		//cout << M << " " << res.x << " " << res.y << endl;
		if (res.x == -1 || res.x ==-2147483648) L = M;
		else {
			R = M;
			ax = res.x;
			ay = res.y;
		}
		lm = M;
	} 

	ax--, ay--;

	int best = 1e7;
	int bx, by;

	for (int dx = -10; dx <= 10; ++dx) {
		for (int dy = -10; dy <= 10; ++dy) {
			if (ax + dx < 0 || ay + dy < 0) continue;
			if (ax + dx == 0 && ay + dy == 0) continue;
			int e = 0;
			for (int i = 0; i < n; ++i) {
				//cout << v[i].x << " " << v[i].y << endl;
				e = max(e, gd(v[i], mp(ax+dx, ay+dy)));
			}
			if (e < best) {
				best = e;
				bx = ax+dx;
				by = ay+dy;
			}
		}
	}

	//cout << "ANS = " << ax << " " << ay << endl;

	cout << best << endl;
	for (int i = 0; i < bx; ++i) cout << 'B';
	for (int i = 0; i < by; ++i) cout << 'N';

	
}