#include <bits/stdc++.h>
#define ll long long
#define db long double
#define x first
#define y second
#define mp make_pair
#define pb push_back
#define all(a) a.begin(), a.end()

using namespace std;

struct Lecture {
	int a; int b;
	int c; int d;
};

bool cmp(Lecture &a, Lecture &b) {
	pair<int, int> A = {a.a, a.b}, B = {b.a, b.b};
	return (A<B);
}

const int N = 400007;

vector<int> rmq;
vector<int> p;

void push(int i, int l, int r) {
	if (r-l<=1) return;
	rmq[2*i+1] += p[i], rmq[2*i+2] += p[i], p[2*i+1] += p[i], p[2*i+2] += p[i];
	p[i] = 0;
}

void add(int i, int l, int r, int l1, int r1) {
	push(i, l, r);
	if (l1 >= r1) return;
	if (l==l1 && r==r1) {
		rmq[i] += 1, p[i] += 1;
		return;
	}

	int mid = (l+r)/2;
	add(2*i+1, l, mid, l1, min(r1, mid));
	add(2*i+2, mid, r, max(l1, mid), r1);
	rmq[i] = rmq[2*i+1] + rmq[2*i+2];

}

void check(int i, int l, int r, int l1, int r1) {
	push(i,l,r);
	if (l1 >= r1) return;
	if (l==l1 && r==r1){
		if (rmq[i] > 0) {
			cout << "NO";
			exit(0);
		}
		return;
	}
	int mid = (l+r)/2;
	check(2*i+1, l, mid, l1, min(r1, mid));
	check(2*i+2, mid, r, max(l1, mid), r1);
}

void solve(vector<Lecture> v) {
	sort(v.begin(), v.end(), cmp);

	rmq.assign(4*N, 0);
	p.assign(4*N, 0);

	set<pair<int, int> > rights;

	for (int i = 0; i < v.size(); ++i) {
		int L = v[i].a;
		while (rights.size()) {
			auto it = rights.begin();
			pair<int, int> p = *it;
			if (p.first < L) {
				rights.erase(it);
				int index = p.second;
				add(0, 0, N, v[index].c, v[index].d + 1);
			}
			else break;
		}
		check(0, 0, N, v[i].c, v[i].d+1);
		rights.insert({v[i].b, i});
	}


}

main(){
#ifdef LOCAL
	freopen("E_input.txt", "r", stdin);
	//freopen("E_output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;

	vector<Lecture> v(n);

	set<int> coordinate;

	for (int i = 0; i < n; ++i) {
		cin >> v[i].a >> v[i].b >> v[i].c >> v[i].d;
		coordinate.insert(v[i].a);
		coordinate.insert(v[i].b);
		coordinate.insert(v[i].c);
		coordinate.insert(v[i].d);
	}

	map<int, int> kek;
	int u = 0;
	for (auto it = coordinate.begin(); it != coordinate.end(); it++) {
		kek[(*it)] = u++;
	}

	for (int i = 0; i < n; ++i) {
		v[i].a = kek[v[i].a];
		v[i].b = kek[v[i].b];
		v[i].c = kek[v[i].c];
		v[i].d = kek[v[i].d];
	}

	solve(v);

	for (int i = 0; i < n; ++i) {
		swap(v[i].d, v[i].b);
		swap(v[i].c, v[i].a);
	}

	solve(v);

	cout << "YES";

}