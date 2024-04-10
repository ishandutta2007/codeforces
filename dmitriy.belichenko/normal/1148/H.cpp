#include"bits/stdc++.h"
#include<valarray>
using namespace std;
 
#define MAX 200013
 
 
int n;
 
//10 8 5 3.4.5. 1...* 
//
 
//?
 
struct seg {
	long long int sum;
	long long int cont;
	seg *l;
	seg *r;
	seg() {
		l = r = NULL;
		sum = cont = 0;
	}
};
struct st {
	vector<seg*> root;
	vector<int> tim;
	vector<pair<pair<int, int>, pair<int, int> > > ad;  //{tim},{pos}
	long long int cont(seg *b) {
		if (b == NULL)return 0;
		return b->cont;
	}
	inline void add(seg *&b, int l, int r, int ll, int rr, long long int x) {
		if (r <= ll || rr <= l) {
			return;
		}
		if (b == NULL) {
			b = new seg();
		}
		else {
			auto f = b;
			b = new seg();
			(*b) = (*f);
		}
		if (ll <= l && r <= rr) {
			b->sum += x;
			b->cont += x * (r - l);
			return;
		}
		add(b->l, l, (l + r) >> 1, ll, rr, x);
		add(b->r, (l + r) >> 1, r, ll, rr, x);
		b->cont = cont(b->l) + cont(b->r) + b->sum*(r - l);
	}
	inline long long int sum(seg *&b, int l, int r, int ll, int rr) {
		if (b == NULL)return 0;
		if (r <= ll || rr <= l) {
			return 0;
		}
		if (ll <= l && r <= rr) {
			return b->cont;
		}
		int rg = min(r, rr) - max(l, ll);
		return sum(b->l, l, (l + r) >> 1, ll, rr) + sum(b->r, (l + r) >> 1, r, ll, rr) + rg * b->sum;
	}
	st() {
	}
};
 
st bit[MAX + 3];
 
struct tt {
	int val;
	int lef;
	int rig;
	int tim;
};
bool operator<(const tt &a, const tt &b) {
	return make_tuple(a.val, a.lef, a.rig, a.tim) < make_tuple(b.val, b.lef, b.rig, b.tim);
}
set<tt> rng;  //{val,{}}
 
 
int CUR_TIM;
vector<int> ar;
 
 
void remove_rng(tt a) {
	int X = CUR_TIM - a.tim;
	bit[a.val].tim.push_back(ar.size()-1);
	bit[a.val].root.push_back(NULL);
	if (bit[a.val].root.size() > 1) {
		bit[a.val].root.back() = bit[a.val].root[bit[a.val].root.size() - 2];
	}
	bit[a.val].ad.push_back({ {a.tim,ar.size() - 1},{a.lef,a.rig} });
	bit[a.val].add(bit[a.val].root.back(), 0, n, a.lef, a.rig + 1, X);
}
 
 
 
 
int im[200];
 
void ins(tt a) {
	auto u = rng.lower_bound({ a.val, -1, 0, 0 });
	if (u != rng.end() && u->val == a.val) {
		a.lef = min(a.lef, u->lef);
		a.rig = max(a.rig, u->rig);
		remove_rng(*u);
		rng.erase(u);
	}
	rng.insert(a);
}
 
 
int seg2[(MAX+5) * 4];
int lb;
 
inline void add(int b, int l, int r, int ll, int x) {
	if (l <= ll && ll < r) {
		if (l + 1 == r) {
			seg2[b] = x;
			return;
		}
		add(b * 2 + 1, l, (l + r) >> 1, ll,x);
		add(b * 2 + 2, (l + r) >> 1, r, ll,x);
		seg2[b] = min(seg2[b * 2 + 1], seg2[b * 2 + 2]);
	}
}
inline int query(int b, int l, int r,int x) {
	if (l + 1 == r) {
		if (seg2[b] < x) {
			lb = seg2[b];
			return l;
		}
		return -1;
	}
	if (seg2[b] >= x) {
		return -1;
	}
	int u = query(b * 2 + 1, l, (l+r)>>1, x);
	if (u != -1)return u;
	return query(b * 2 + 2, (l + r) >> 1, r, x);
}
int mex(int pos) {
	return query(0, 0, MAX + 4, pos);
}
 
void add_val(int val) {
	auto z = rng.upper_bound({ val,-1,0,0 });
	int pos = 0;
	if (rng.size() == 0) {
		pos = 0;
	}
	else {
		if (z != rng.begin()) {
			pos = (*prev(z)).lef - 1;
		}
		else {
			pos = ar.size();
		}
	}
	while (z!=rng.end()&&z->val == val) {
		auto t = next(z);
		remove_rng(*z);
		rng.erase(z);
		z = t;
	}
	add(0, 0, MAX+4, val, ar.size());
	ar.push_back(val);
	int want = 1;
	int until = 0;
	if (z != rng.end()) {
		until = (*z).rig + 1;
	}
	if (true) {
		if (val == 0) {
			ins({ 1,(int)ar.size() - 1,(int)ar.size() - 1,CUR_TIM });
		}
		else {
			ins({ 0,(int)ar.size() - 1,(int)ar.size() - 1,CUR_TIM });
		}
		pos = min(pos, (int)ar.size() - 2);
	}
	if (pos >= until) {
		int R = pos;
		while (pos >= until) {
			want = mex(pos);
			pos = max(until-1,lb);
			ins({ want,pos + 1,R,CUR_TIM });
			R = pos;
			//pos--;
		}
		if (pos >= until) {
			want = mex(until);
			ins({ want, until, R, CUR_TIM });
		}
	}
}
long long int overlap(int l1, int r1, int l2, int r2) {
	if (r2 < l1||r1<l2) {
		return 0;
	}
	if (l1 <= l2 && r2 <= r1) {
		return r2 - l2 + 1;
	}
	if (l2 <= l1 && r1 <= r2) {
		return  r1 - l1 + 1;
	}
	return min(r2, r1) - max(l1, l2) + 1;
}
long long int query(int k, int l, int r) {
	int zz = upper_bound(bit[k].tim.begin(), bit[k].tim.end(), r) - bit[k].tim.begin();
	long long int z = 0;
	if (zz > 0) {
		z = bit[k].sum(bit[k].root[zz-1], 0, n, l, r + 1);
	}
	//over lap
	if (zz != bit[k].tim.size()) {
		auto u = bit[k].ad[zz];
		z+=overlap(l, r, u.second.first, u.second.second)*overlap(l, r, u.first.first, u.first.second);
	}
	auto f = rng.upper_bound({ k,-1,0,0 });
	while (f != rng.end() && f->val == k) {
		z += overlap(l, r, f->lef, f->rig)*overlap(l, r, f->tim, ar.size() - 1);
		f++;
		/*long long int rng = min(r, f->rig) - max(l, f->lef);
		if (rng >= 0)rng++;
		rng = max(rng, 0LL);
		int tt = (r - f->tim + 1);
		tt = max(tt, 0);
		z += rng * tt;*/
	}
	return z;
}
int main() {
	memset(seg2, -1, sizeof(seg2));
	cin >> n;
	long long int lans = 0;
	for (int i = 1; i <= n; i++) {
		int a, l, r, k;
		scanf("%d%d%d%d", &a, &l, &r, &k);
		a = (a + lans) % (n + 1);
		l = (l + lans) % i;
		r = (r + lans) % i;
		if (l > r)swap(l, r);
		k = (k + lans) % (n + 1);
		if (a >= MAX) {
			add_val(MAX);
		}
		else {
			add_val(a);
		}
		lans = 0;
		if (k >= MAX) {
			puts("0");
		}
		else {
			lans = query(k, l, r);
			printf("%lld\n", lans);
		}
		CUR_TIM++;
	}
	return 0;
}