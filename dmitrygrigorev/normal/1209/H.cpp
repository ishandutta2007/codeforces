#include <bits/stdc++.h>
#define db long double
#define ll long long
#define x first
#define y second
#define mp make_pair
#define pb push_back
#define all(a) a.begin(), a.end()

using namespace std;

const db INF = 1e10;

struct Travolator{int l; db v; db L; db R;};
vector<Travolator> t;
struct Vertex{db p; db minimum;};
vector<Vertex> rmq;

void push(int i, int l, int r){
	if (r-l<=1) return;
	db P = rmq[i].p;
	rmq[i].p=0;
	rmq[2*i+1].p+=P, rmq[2*i+1].minimum+=P;
	rmq[2*i+2].p+=P, rmq[2*i+2].minimum+=P;
}

void add(int i, int l, int r, int l1, int r1, db x){
	push(i, l, r);
	if (l1 >= r1) return;
	if (l==l1 && r==r1){
		rmq[i].p+=x, rmq[i].minimum+=x;
		return;
	}
	int mid = (l+r)/2;
	add(2*i+1, l, mid, l1, min(r1, mid), x), add(2*i+2, mid, r, max(l1, mid), r1, x);
	rmq[i].minimum = min(rmq[2*i+1].minimum, rmq[2*i+2].minimum);
}

db get(int i, int l, int r, int l1, int r1){
	push(i, l, r);
	if (l1 >= r1) return 1e18;
	if (l==l1 && r==r1) return rmq[i].minimum;
	int mid = (l+r)/2;
	return min(get(2*i+1, l, mid, l1, min(r1, mid)), get(2*i+2, mid, r, max(l1, mid), r1)); 
}
main(){
#ifdef LOCAL
	freopen("H_input.txt", "r", stdin);
	//freopen("J_output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n, l;
	cin >> n >> l;
	int last = 0;
	for (int i=0; i < n; ++i){
		int x, y;
		db v;
		cin >> x >> y >> v;
		if (x!=last){
			t.push_back({x-last, 1});
		}
		t.push_back({y-x, v+1});
		last = y;
	}
	if (last != l) t.push_back({l-last, 1});
	n = t.size();
	for (int i=0;i<n;++i){
		db tm = t[i].l / (t[i].v + 1);
		t[i].L = -tm;
		if (abs(1. - t[i].v) < 1/INF){
			t[i].R = INF;
		}
		else t[i].R = t[i].l / (t[i].v - 1);
	}
	rmq.assign(4*n, {0., 0.});
	vector<pair<db, int> > arr;
	for (int i=0;i<n;++i) arr.push_back({t[i].v, i});
	sort(arr.begin(), arr.end());
	for (int i=0;i<n;++i){
		add(0, 0, n, i, n, t[i].R);
	}
	for (int i=0;i<n;++i){
		int index = arr[i].second;
		db minimum = min(get(0, 0, n, index, n), (db) t[index].R - (db) t[index].L);
		add(0, 0, n, index, n, -minimum);
	}
	db ans = 0;
	db old = 0;
	for (int i=0;i<n;++i){
		db spent = get(0, 0, n, i, i+1);
		//cout << spent - old << endl;
		ans += (t[i].l + (spent-old)) / t[i].v;
		//cout << ans << endl;
		old = spent;
	}
	cout.precision(11);
	cout << fixed << ans;
}