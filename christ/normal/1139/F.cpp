#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
#define all(x) (x).begin(),(x).end()
#define x first
#define y second
const int MN = 4e5+3, MM = 2e5+3, MOD = 1e9+7;
mt19937_64 rnd = mt19937_64(chrono::steady_clock::now().time_since_epoch().count());
struct Dish {
	int p,s,b,v1,v2;
};
struct Dude {
	int inc,pref,ind,v1,v2;
};
int ans[MN], bit[MN];
void inc (int i) {
	for (;i<MN;i+=i&-i)
		++bit[i];
}
void dec (int i) {
	for (;i<MN;i+=i&-i)
		--bit[i];
}
int query (int i) {
	int ret = 0;
	for (;i;i^=i&-i)
		ret += bit[i];
	return ret;
}
vector<int> xs;
void getx (int &x) {x = lower_bound(all(xs),x)-xs.begin()+1;}
void cdq (int l, int r, vector<Dish> &dishes, vector<Dude> &dudes) { //cdq over b_i/pref_j
	if (dishes.empty() || dudes.empty()) return;
	vector<Dish> lq,rq; vector<Dude> ld,rd; int bp = 0, mid = (l+r)/2;
	for (Dude &d : dudes) {
		while (bp < dishes.size() && dishes[bp].v1 <= d.v1) {
			if (dishes[bp].b <= mid && l!=r) lq.push_back(dishes[bp++]);
			else {
				rq.push_back(dishes[bp]);
				inc(dishes[bp].p);
				dec(dishes[bp++].s+1);
			}
		}
		if (d.pref <= mid || l==r) {
			ans[d.ind] += query(d.inc);
			ld.push_back(d);
		} else rd.push_back(d);
	}
	for (Dish &d : rq) dec(d.p), inc(d.s+1);
	if (l < r) {
		cdq(l,mid,lq,ld); cdq(mid+1,r,rq,rd);
	}
}
void cdq2 (int l, int r, vector<Dish> &dishes, vector<Dude> &dudes) {
	if (dishes.empty() || dudes.empty()) return;
	vector<Dish> lq,rq; vector<Dude> ld,rd; int bp = 0, mid = (l+r)/2;
	for (Dude &d : dudes) {
		while (bp < dishes.size() && dishes[bp].v2 <= d.v2) {
			if (dishes[bp].b <= mid) {
				lq.push_back(dishes[bp]);
				inc(dishes[bp].p);
				dec(dishes[bp++].s+1);
			} else rq.push_back(dishes[bp++]);
		}
		if (d.pref <= mid) ld.push_back(d);
		else {
			ans[d.ind] += query(d.inc);
			rd.push_back(d);
		}
	}
	for (Dish &d : lq) dec(d.p), inc(d.s+1);
	if (l < r) {
		cdq2(l,mid,lq,ld); cdq2(mid+1,r,rq,rd);
	}
}
int main() {
	int n,m,ree=0;
	scanf ("%d %d",&n,&m);
	vector<Dish> dishes(n); vector<Dude> dudes(m);
	for (auto &au : dishes) scanf ("%d",&au.p), xs.push_back(au.p);
	for (auto &au : dishes) scanf ("%d",&au.s), xs.push_back(au.s);
	for (auto &au : dishes) scanf ("%d",&au.b), au.v1 = au.b+au.p, au.v2 = au.p-au.b;
	for (auto &au : dudes) scanf ("%d",&au.inc), xs.push_back(au.inc), au.ind = ++ree;
	for (auto &au : dudes) scanf ("%d",&au.pref), au.v1 = au.inc+au.pref, au.v2=au.inc-au.pref;
	sort(all(dishes),[&](const Dish &a, const Dish &b){return a.v1 < b.v1;});
	sort(all(dudes),[&](const Dude &a, const Dude &b){return a.v1 < b.v1;});
	sort(all(xs)); xs.erase(unique(all(xs)),xs.end());
	for (auto &au : dishes) getx(au.p), getx(au.s);
	for (auto &au : dudes) getx(au.inc);
	xs.clear();
	for (auto &au : dishes) xs.push_back(au.b);
	for (auto &au : dudes) xs.push_back(au.pref);
	sort(all(xs)); xs.erase(unique(all(xs)),xs.end());
	for (auto &au : dishes) getx(au.b);
	for (auto &au : dudes) getx(au.pref);
	cdq(1,xs.size(),dishes,dudes);
	sort(all(dishes),[&](const Dish &a, const Dish &b) {return a.v2 < b.v2;});
	sort(all(dudes),[&](const Dude &a, const Dude &b){return a.v2 < b.v2;});
	cdq2(1,xs.size(),dishes,dudes);
	for (int i = 1; i <= m; i++) printf ("%d ",ans[i]);
	printf ("\n");
    return 0;
}