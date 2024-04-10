#include <bits/stdc++.h>
using namespace std;
#pragma optimize("-O3")
#define int long long int
#define f first
#define s second
#define pb push_back
#define endl '\n'
#define T long double

const T EPS = 1E-9;
const int N=25005;
int n;
int x[N];
int y[N];
int dx[N];
int dy[N];
int sp[N];

struct pt {
    T x, y;
};

struct seg {
    pt p, q;
    int id;

    T get_y(T x) const {
        if (abs(p.x - q.x) < EPS)
            return p.y;
        return p.y + (q.y - p.y) * (x - p.x) / (q.x - p.x);
    }
};

bool intersect1d(T l1, T r1, T l2, T r2) {
    if (l1 > r1)
        swap(l1, r1);
    if (l2 > r2)
        swap(l2, r2);
    return max(l1, l2) <= min(r1, r2) + EPS;
}

int vec(const pt& a, const pt& b, const pt& c) {
    T s = (b.x - a.x) * (c.y - a.y) - (b.y - a.y) * (c.x - a.x);
    return abs(s) < EPS ? 0 : s > 0 ? +1 : -1;
}

bool intersect(const seg& a, const seg& b)
{
    return intersect1d(a.p.x, a.q.x, b.p.x, b.q.x) &&
           intersect1d(a.p.y, a.q.y, b.p.y, b.q.y) &&
           vec(a.p, a.q, b.p) * vec(a.p, a.q, b.q) <= 0 &&
           vec(b.p, b.q, a.p) * vec(b.p, b.q, a.q) <= 0;
}

bool operator<(const seg& a, const seg& b)
{
    T x = max(min(a.p.x, a.q.x), min(b.p.x, b.q.x));
    return a.get_y(x) < b.get_y(x) - EPS;
}

struct event {
    T x;
    int tp, id;

    event() {}
    event(T x, int tp, int id) : x(x), tp(tp), id(id) {}

    bool operator<(const event& e) const {
        if (abs(x - e.x) > EPS)
            return x < e.x;
        return tp > e.tp;
    }
};

set<seg> s;
vector<set<seg>::iterator> where;

set<seg>::iterator prev(set<seg>::iterator it) {
    return it == s.begin() ? s.end() : --it;
}

set<seg>::iterator next(set<seg>::iterator it) {
    return ++it;
}

pair<int, int> solve(const vector<seg>& a) {
    int n = (int)a.size();
    vector<event> e;
    for (int i = 0; i < n; ++i) {
        e.push_back(event(min(a[i].p.x, a[i].q.x), +1, i));
        e.push_back(event(max(a[i].p.x, a[i].q.x), -1, i));
    }
    sort(e.begin(), e.end());

    s.clear();
    where.resize(a.size());
    for (size_t i = 0; i < e.size(); ++i) {
        int id = e[i].id;
        if (e[i].tp == +1) {
            set<seg>::iterator nxt = s.lower_bound(a[id]), prv = prev(nxt);
            if (nxt != s.end() && intersect(*nxt, a[id]))
                return make_pair(nxt->id, id);
            if (prv != s.end() && intersect(*prv, a[id]))
                return make_pair(prv->id, id);
            where[id] = s.insert(nxt, a[id]);
        } else {
            set<seg>::iterator nxt = next(where[id]), prv = prev(where[id]);
            if (nxt != s.end() && prv != s.end() && intersect(*nxt, *prv))
                return make_pair(prv->id, nxt->id);
            s.erase(where[id]);
        }
    }

    return make_pair(-1, -1);
}



bool f(T tim, int cnt){
	vector<seg>a;
	for(int i=0; i<n; i++){
		seg xx;
		pt pt1;
		pt1.x=x[i];
		pt1.y=y[i];
		xx.p=pt1;
		pt pt2;
		pt2.x=x[i]+(sp[i]*dx[i]*tim/(sqrt(dx[i]*dx[i]+dy[i]*dy[i])));
		pt2.y=y[i]+(sp[i]*dy[i]*tim/(sqrt(dx[i]*dx[i]+dy[i]*dy[i])));
		xx.q=pt2;
		xx.id=i;
		a.pb(xx);
	}
	
	pair<int, int>pts=solve(a);
	
	if(pts.f!=-1){
		return 1;
	}
	else{
		return 0;
	}
}
 
 
main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	cin>>n;
	for(int i=0; i<n; i++){
		cin>>x[i]>>y[i]>>dx[i]>>dy[i]>>sp[i];
	}
	T lo=0;
	T hi=1e12;
	T ans=-1;
	for(int i=0; i<60; i++){
		T mid=(lo+hi)/2;
		
		if(f(mid, i)){
			ans=mid;
			hi=mid;
		}
		else{
			lo=mid;
		}
	}
	if(ans<0){
		cout<<"No show :(";
	}
	else{
		cout<<fixed<<setprecision(20)<<ans<<endl;
	}
	return 0;
}