#include <bits/stdc++.h>
#define ll long long
#define db long double
#define x first
#define y second
#define mp make_pair
#define pb push_back
#define all(a) a.begin(), a.end()

using namespace std;

struct Vertex {
	int alive_bombs;
	int alive_guys;
	int min_pref;
	int sum;
};

vector<Vertex> rmq;

void recalc(Vertex &a, Vertex &b, Vertex &c) {
	a.sum = b.sum + c.sum;
	a.min_pref = min(b.min_pref, b.sum + c.min_pref);

	a.alive_guys = c.alive_guys + max(0, b.alive_guys - c.alive_bombs);

	a.alive_bombs = b.alive_bombs + max(0, c.alive_bombs - b.alive_guys);

}

const int INF = 1e9;

Vertex start = {0, 0, 0, 0};
Vertex cur;

void get(int i, int l, int r, int l1, int r1) {
	if (l1 >= r1) return;
	if (l==l1 && r==r1) {
		Vertex C = cur;
		recalc(cur, C, rmq[i]);
		return;
	}
	int mid = (l+r)/2;
	get(2*i+1, l, mid, l1, min(r1, mid));
	get(2*i+2, mid, r, max(l1, mid), r1);
}

int n;

Vertex take(int l, int r) {
	cur = start;
	get(0, 0, n, l, r+1);
	return cur;
}

void upd(int i, int l, int r, int index, int add) {

	if (r-l==1) {
		rmq[i].sum += add;
		rmq[i].min_pref = rmq[i].sum;
		
		rmq[i].alive_guys = (rmq[i].sum > 0);
		rmq[i].alive_bombs = (rmq[i].sum < 0);
		return;
	}

	int mid = (l+r)/2;
	if (index < mid) upd(2*i+1, l, mid, index, add);
	else upd(2*i+2, mid, r, index, add);
	recalc(rmq[i], rmq[2*i+1], rmq[2*i+2]);

}

int main(){
#ifdef LOCAL
	freopen("C_input.txt", "r", stdin);
	//freopen("C_output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;

	vector<int> a(n), b(n);
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
		a[i]--;
	}

	for (int i = 0; i < n; ++i) {
		cin >> b[i];
		b[i]--;
	}

	rmq.assign(4*n, {0, 0, 0, 0});
	
	int now = n-1;

	vector<int> posa(n);
	for (int i = 0; i < n; ++i) posa[a[i]] = i;

	for (int i = 0; i < n; ++i) {
		cout << now+1 << " ";
		upd(0, 0, n, b[i], -1);
		if (i+1==n) break;
		while (true) {
			Vertex A = take(0, posa[now] - 1);
			Vertex B = take(posa[now], n-1);
			if (A.alive_guys + B.min_pref < 0) {
				upd(0, 0, n, posa[now], 1);
				now--;
			}
			else break;
		}
	}
	

}