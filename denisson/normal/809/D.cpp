#include <bits/stdc++.h>
                     
using namespace std;
             
typedef long long ll;
#define mp make_pair
#define pub push_back
#define x first
#define y second
#define all(a) a.begin(), a.end()
#define db double

struct vert{
	int l, r, x, y, add;
	vert() { l = 0, r = 0; y = rand(); }
};

struct dd{
	vert t[3 * 300007];
	int sz, root;

	dd() { sz = 1; root = 0; }

	void push(int v){
		if (v){
			t[v].x += t[v].add;
			t[t[v].l].add += t[v].add;
			t[t[v].r].add += t[v].add;
			t[v].add = 0;
		}
	}

	int merge(int a, int b){
		push(a); push(b);
		if (a == 0) return b;
		if (b == 0) return a;
		if (t[a].y < t[b].y){
			t[a].r = merge(t[a].r, b);
			return a;
		} else {
			t[b].l = merge(a, t[b].l);
			return b;
		}
	}

	pair<int, int> split(int v, int val){
		if (v == 0) return mp(0, 0);
		push(v);
		if (t[v].x >= val){
			auto now = split(t[v].l, val);
			t[v].l = now.y;
			return mp(now.x, v);
		} else {
			auto now = split(t[v].r, val);
			t[v].r = now.x;
			return mp(v, now.y);
		}
	}

	void insert(int val){
		int v = sz++;
		t[v].x = val;
		t[v].add = 0;
		root = merge(root, v);
	}

	void eraseFirst(int &v){
		if (t[v].l == 0){
			v = t[v].r;
			return;
		}
		eraseFirst(t[v].l);
	}

	void print(int v){
		if (v == 0) return;
		print(t[v].l);
		cout << t[v].x << ' ';
		print(t[v].r);
	}

	void calcFunc(int l, int r){
		r--;
		auto now = split(root, r + 1);
		auto now2 = split(now.x, l);
		t[now2.y].add++;
		eraseFirst(now.y);
		root = now2.x;
		insert(l);
		root = merge(root, now2.y);
		root = merge(root, now.y);
	}

	void getAns(int v, vector<int> &a){
		if (v == 0) return;
		getAns(t[v].l, a);
		a.pub(t[v].x);
		getAns(t[v].r, a);
	}
} t;

int n;
pair<int, int> a[300007];

int main(){
	srand(time(NULL));
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n;
    for (int i = 0; i < n; i++) cin >> a[i].x >> a[i].y;
	for (int i = 1; i <= n; i++) t.insert(2e9 + i);
	for (int i = 0; i < n; i++){
		t.calcFunc(a[i].x, a[i].y);
		//t.print(t.root);
		//cout << endl;
	}
	vector<int> g;
	t.getAns(t.root, g);
	int it = 0;
	for (int i = 0; i < g.size(); i++) if (g[i] < 2e9) it++;
	cout << it;
}