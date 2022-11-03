#include <bits/stdc++.h>
	  
using namespace std;
	  
typedef long long ll;
#define mp make_pair
#define pub push_back
#define x first
#define y second
#define all(a) a.begin(), a.end()
#define db double

struct tree{
	int t[4 * 2 * 100007];

	void up(int v, int vl, int vr, int pos, int val){
		if (vl == vr){
			t[v] = val;
		} else {
			int vm = (vl + vr) >> 1;
			if (pos <= vm) up(v * 2 + 1, vl, vm, pos, val);
			else up(v * 2 + 2, vm + 1, vr, pos, val);
			t[v] = max(t[v * 2 + 1], t[v * 2 + 2]);
		}
	}

	int get(int v, int vl, int vr, int l, int r){
		if (vr < l || vl > r) return -1;
		if (vl >= l && vr <= r){
			return t[v];
		} else {
			int vm = (vl + vr) >> 1;
			return max(get(v * 2 + 1, vl, vm, l, r), get(v * 2 + 2, vm + 1, vr, l, r));
		}
	}

};

int n;
int a[200007];
tree t;

int main() { 
	srand('D' + 'E' + 'N' + 'I' + 'S' + 'S' + 'O' + 'N' + time(NULL));
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	//freopen("cpr.in", "r", stdin);
	//freopen("cpr.out", "w", stdout);
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++) cin >> a[i];
	for (int i = 0; i < n; i++) t.up(0, 0, n - 1, i, a[i]);
	int sz = 0;
	while(1){
		if (sz == n) break;
		int last = 0;
		int pos = -1;

		while(1){
			int vl = pos, vr = n;
			while(vl + 1 < vr){
				int vm = (vl + vr) >> 1;
				if (t.get(0, 0, n - 1, pos + 1, vm) > last)
					vr = vm;
				else
					vl = vm;
			}
			if (vr == n) break;
			pos = vr;
			last = a[vr];
			t.up(0, 0, n - 1, pos, -1);
			cout << last << ' ';
			sz++;
		}

		cout << "\n";
	}
}