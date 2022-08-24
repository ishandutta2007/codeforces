#include <bits/stdc++.h>
#define double long double
#define int long long
using namespace std;
struct state {
	int len, link;
	map<int,int> next;
};
const int MAXLEN = 300000;
state st[MAXLEN*2];
int sz, last;
void sa_init() {
	sz = last = 0;
	st[0].len = 0;
	st[0].link = -1;
	++sz;
	/*
	//   ,         :
	for (int i=0; i<MAXLEN*2; ++i)
		st[i].next.clear();
	*/
}
void sa_extend (int c) {
	int cur = sz++;
	st[cur].len = st[last].len + 1;
	int p;
	for (p=last; p!=-1 && !st[p].next.count(c); p=st[p].link)
		st[p].next[c] = cur;
	if (p == -1)
		st[cur].link = 0;
	else {
		int q = st[p].next[c];
		if (st[p].len + 1 == st[q].len)
			st[cur].link = q;
		else {
			int clone = sz++;
			st[clone].len = st[p].len + 1;
			st[clone].next = st[q].next;
			st[clone].link = st[q].link;
			for (; p!=-1 && st[p].next[c]==q; p=st[p].link)
				st[p].next[c] = clone;
			st[q].link = st[cur].link = clone;
		}
	}
	last = cur;
}
struct pt {
	double x, y;
};

bool cmp (pt a, pt b) {
	return a.x < b.x || a.x == b.x && a.y < b.y;
}

bool cw (pt a, pt b, pt c) {
	return a.x*(b.y-c.y)+b.x*(c.y-a.y)+c.x*(a.y-b.y) < 0;
}

bool ccw (pt a, pt b, pt c) {
	return a.x*(b.y-c.y)+b.x*(c.y-a.y)+c.x*(a.y-b.y) > 0;
}

void convex_hull (vector<pt> & a) {
	if (a.size() == 1)  return;
	sort (a.begin(), a.end(), &cmp);
	pt p1 = a[0],  p2 = a.back();
	vector<pt> up, down;
	up.push_back (p1);
	down.push_back (p1);
	for (size_t i=1; i<a.size(); ++i) {
		if (i==a.size()-1 || cw (p1, a[i], p2)) {
			while (up.size()>=2 && !cw (up[up.size()-2], up[up.size()-1], a[i]))
				up.pop_back();
			up.push_back (a[i]);
		}
		if (i==a.size()-1 || ccw (p1, a[i], p2)) {
			while (down.size()>=2 && !ccw (down[down.size()-2], down[down.size()-1], a[i]))
				down.pop_back();
			down.push_back (a[i]);
		}
	}
	a.clear();
	for (size_t i=0; i<up.size(); ++i)
		a.push_back (up[i]);
	for (size_t i=down.size()-2; i>0; --i)
		a.push_back (down[i]);
}
struct H{int side; pair<int, int> cs;};
struct Cmp {
    bool operator()(const H& a, const H& b) const {
        if (a.cs != b.cs) return (a.cs < b.cs);
        if (a.side != b.side) return (a.side < b.side);
        return false;
    }
};
int dst(pt &A, pt &B){
    return (A.x - B.x) * (A.x - B.x) + (A.y - B.y) * (A.y - B.y);
}
int gcd(int a, int b){
    if (b==0) return a;
    return gcd(b, a%b);
}
vector<H> get(vector<pt> &a){
    vector<H> res;
    int e = a.size();
    for (int i=0; i < a.size(); i++){
        pt A = a[i], B = a[(i+1) % e], C = a[(i+2)%e];
        H h;
        h.side = dst(A, B);
        int aa = dst(A, B), bb = dst(B, C), cc = dst(A, C);
        int csl = cc - aa - bb;
        int zn = -2*aa*bb;
        int g = gcd(csl, zn);
        csl/=g, zn/=g;
        h.cs = make_pair(csl, zn);
        res.push_back(h);
    }
    return res;
}
bool solve(vector<pt> &a, vector<pt> &b){
    vector<H> F, S;
    F = get(a), S = get(b);
    //for (int i=0; i < 5; i++) cout << F[i].side << " " << F[i].cs.first << " " << F[i].cs.second << endl;
    //cout << endl;
    map<H, int, Cmp> mm;
    vector<int> rf, rs;
    for (int i=0; i < F.size(); i++){
        if (mm.count(F[i])) rf.push_back(mm[F[i]]);
        else{
            int Sz = mm.size();
            mm[F[i]] = Sz;
            rf.push_back(Sz);
        }
    }
    for (int i=0; i < S.size(); i++){
        if (mm.count(S[i])) rs.push_back(mm[S[i]]);
        else{
            int Sz = mm.size();
            mm[S[i]] = Sz;
            rs.push_back(Sz);
        }
    }
    int Ss = rf.size();
    for (int i=0; i < Ss; i++) rf.push_back(rf[i]);
    sa_init();
    if (F.size() != S.size()) return false;
    for (int i=0;i<rf.size(); i++) sa_extend(rf[i]);
    int now = 0;
    for (int i=0; i < rs.size(); i++){
        if (!st[now].next.count(rs[i])) return false;
        now = st[now].next[rs[i]];
    }
    return true;
}
signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, m;
    cin >> n >> m;
    vector<pt> a, b;
    for (int i=0; i < n; i++){
        int x, y;
        cin >> x >> y;
        a.push_back({x, y});
    }
    for (int i=0; i < m; i++){
        int x, y;
        cin >> x >> y;
        b.push_back({x, y});
    }
    convex_hull(a), convex_hull(b);
    vector<H> f, s;
    bool res = solve(a, b);
    if (res){
        cout << "YES";
        return 0;
    }
    cout << "NO";
    return 0;
}