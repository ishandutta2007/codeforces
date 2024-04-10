#include <bits/stdc++.h>
#define ll long long
#define db long double
#define x first
#define y second
#define mp make_pair
#define pb push_back
#define all(a) a.begin(), a.end()

using namespace std;

struct N {
  string col[2];
  int lock[2];
};

string a[100007];

string kek(string a, string b) {
	if (b == "") return a;
	return b;
}

N merge(N a, N b) {
	N c;
	c.col[0] = kek(a.col[0], b.col[a.lock[0]]);
	c.col[1] = kek(a.col[1], b.col[a.lock[1]]);
	c.lock[0] = b.lock[a.lock[0]];
	c.lock[1] = b.lock[a.lock[1]];
	return c;
}

struct Tree {
  N t[400007];

  void init(int v, int vl) {
    	if (a[vl] == "lock") {
    		t[v].col[0] = t[v].col[1] = "";
    		t[v].lock[0] = t[v].lock[1] = 1;
    	} else if (a[vl] == "unlock") {
    		t[v].col[0] = t[v].col[1] = "";
    		t[v].lock[0] = 0;
    		t[v].lock[1] = 0;
    	} else {
    		t[v].col[0] = a[vl];
    		t[v].col[1] = "";
    		t[v].lock[0] = 0;
    		t[v].lock[1] = 1;
    	}
  }

  void build(int v, int vl, int vr) {
    if (vl == vr) {
    	init(v, vl);
    } else {
      int vm = (vl + vr) >> 1;
      build(v * 2 + 1, vl, vm);
      build(v * 2 + 2, vm + 1, vr);
      t[v] = merge(t[v * 2 + 1], t[v * 2 + 2]);
    }
  }

  void up(int v, int vl, int vr, int pos) {
  	if (vl == vr) {
  		init(v, vl);
  	} else {
  		int vm = (vl + vr) >> 1;
  		if (pos <= vm) up(v * 2 + 1, vl, vm, pos);
  		else up(v * 2 + 2, vm + 1, vr, pos);
      t[v] = merge(t[v * 2 + 1], t[v * 2 + 2]);
  	}
  }
} tr;

int n;

int main(){
#ifdef LOCAL
	freopen("D_input.txt", "r", stdin);
	//freopen("D_output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	for (int i = 0; i < n; ++i) cin >> a[i];

	tr.build(0, 0, n - 1);

	cout << kek("blue", tr.t[0].col[0]) << "\n";

	int m;
	cin >> m;
	while (m--) {
		int v; string c;
		cin >> v >> c; --v;
		a[v] = c;
		tr.up(0, 0, n - 1, v);
		auto now = tr.t[0];
		cout << kek("blue", now.col[0]) << "\n";
	}

}