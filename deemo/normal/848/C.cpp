#include<cstdio>
#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define F first
#define S second

const int MAXN = 1e5 + 10;
const int SQ = 330;

int n, q, a[MAXN];
set<int> st[MAXN];
pii b[MAXN], c[MAXN];
ll pt[MAXN];

void reArrenge(int l){
	int r = min(n, l+SQ);
	copy(b+l, b+r, c+l);
	sort(c + l, c + r);
	for (int i = r-1; i >= l; i--){
		pt[i] = c[i].S;
		if (i+1 < r)
			pt[i] += pt[i+1];
	}
}

void refresh(int pos){
	auto it = st[a[pos]].upper_bound(pos);
	pii xx;
	if (it != st[a[pos]].end())
		xx = {*it, *it-pos};
	else
		xx = {-1, 0};

	b[pos] = xx;
	reArrenge(pos/SQ*SQ);
}

ll get(int l, int r){
	ll res = 0;
	for (; l < r && l % SQ != 0; l++) 
		if (b[l].F < r)
			res += b[l].S;

	for (; l/SQ != r/SQ; l += SQ){
		int t = lower_bound(c+l, c+l+SQ, make_pair(r, -1)) - c;
		res += pt[l];
		if (t < l+SQ)
			res -= pt[t];
	}

	for (; l < r; l++)
		if (b[l].F < r)
			res += b[l].S;
	return res;
}

int main(){
	scanf("%d %d", &n, &q);
	for (int i = 0; i < n; i++) scanf("%d", &a[i]);

	for (int i = n-1; ~i; i--){
		if (st[a[i]].size())
			b[i] = {*st[a[i]].begin(), *st[a[i]].begin()-i};
		else
			b[i] = {-1, 0};
		st[a[i]].insert(i);
	}

	for (int l = 0; l < n; l += SQ)
		reArrenge(l);

	while (q--){
		int tp; scanf("%d", &tp);
		if (tp == 2){
			int l, r; scanf("%d %d", &l, &r), l--;
			printf("%lld\n", get(l, r));
		}
		else{
			int p, x; scanf("%d %d", &p, &x), p--;
			if (a[p] == x) continue;

			st[a[p]].erase(p);
			auto it = st[a[p]].lower_bound(p);
			if (it != st[a[p]].begin()){
				it--;
				refresh(*it);
			}

			a[p] = x;
			st[a[p]].insert(p);
			refresh(p);
			it = st[a[p]].lower_bound(p);
			if (it != st[a[p]].begin()){
				it--;
				refresh(*it);
			}
		}
	}
	return 0;
}