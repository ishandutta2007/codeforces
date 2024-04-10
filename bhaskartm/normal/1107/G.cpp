#include<bits/stdc++.h>

using namespace std;

const int N = int(3e5) + 99;

struct node{
	long long sum, ans, pref, suf;
	
	node () {}
	node(int x){
		sum = x;
		x = max(x, 0);
		pref = suf = ans = x;
	}
};

node merge(const node &a, const node &b){
	node res;
	res.sum = a.sum + b.sum;
	res.pref = max(a.pref, a.sum + b.pref);
	res.suf = max(b.suf, b.sum + a.suf);
	res.ans = max(max(a.ans, b.ans), a.suf + b.pref);
	return res;
}

int n, x;
pair<int, int> p[N];
node t[N * 4];

void upd(int v, int l, int r, int pos, int x){
	if(r - l == 1){
		assert(pos == l);
		t[v] = node(x);
		return;
	}
	
	int mid = (l + r) / 2;
	if(pos < mid) upd(v * 2 + 1, l, mid, pos, x);
	else upd(v * 2 + 2, mid, r, pos, x);
	
	t[v] = merge(t[v * 2 + 1], t[v * 2 + 2]);
}

node get(int v, int l, int r, int L, int R){
	if(L >= R) return node(0);
	
	if(l == L && r == R)
		return t[v];
	
	int mid = (l + r)/ 2;
	return merge(get(v * 2 + 1, l, mid, L, min(mid, R)),
				 get(v * 2 + 2, mid, r, max(L, mid), R));	
}

int main() {
	scanf("%d %d", &n, &x);
	for(int i = 0; i < n; ++i){
		scanf("%d %d", &p[i].first, &p[i].second);
		p[i].second = x - p[i].second;
	}
	
	sort(p, p + n);
	for(int i = 0; i < n; ++i) upd(0, 0, n, i, p[i].second);
	
	vector <pair<int, int> > v;
	for(int i = 1; i < n; ++i)
		v.emplace_back(p[i].first - p[i - 1].first, i);
	sort(v.begin(), v.end());
	
	long long res = 0;
	set <pair<int, int> > s;
	for(int i = 0; i < n; ++i){
		s.insert(make_pair(i, i + 1));
		res = max(res, 1LL * p[i].second);
	}
	
	int l = 0;
	while(l < v.size()){
		int r = l + 1;
		while(r < v.size() && v[l].first == v[r].first) ++r;
		long long d = v[l].first * 1LL * v[l].first;
		
		for(int i = l; i < r; ++i){
			int id = v[i].second;
			auto it = s.upper_bound(make_pair(id, -1));
			assert(it->first == id);
			assert(it != s.begin());
			auto R = *it;
			--it;
			auto L = *it;
			s.erase(L), s.erase(R);
			L.second = R.second;
			
			auto nd = get(0, 0, n, L.first, L.second);
			res = max(res, nd.ans - d);
			s.insert(L);
		}
		
		l = r;
	}
	
	cout << res << endl;
	return 0;
}