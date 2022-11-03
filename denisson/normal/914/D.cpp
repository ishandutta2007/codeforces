#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;
#define mp make_pair
#define pub push_back
#define x first
#define y second
#define all(a) a.begin(), a.end()
#define db double

int gcd(int a, int b){
	while(b){
		a %= b;
		swap(a, b);
	}
	return a;
}

int t[4 * 5 * 100007];

void up(int v, int vl, int vr, int pos, int val){
	if (vl == vr){
		t[v] = val;
	} else {
		int vm = (vl + vr) >> 1;
		if (pos <= vm) up(v * 2 + 1, vl, vm, pos, val);
		else up(v * 2 + 2, vm + 1, vr, pos, val);
		t[v] = gcd(t[v * 2 + 1], t[v * 2 + 2]);
	}
}

int get(int v, int vl, int vr, int l, int r){
	if (l > r) return 0;
	if (r < vl || l > vr) return 0;
	if (vl >= l && vr <= r) return t[v];
	int vm = (vl + vr) >> 1;
	return gcd(get(v * 2 + 1, vl, vm, l, r), get(v * 2 + 2, vm + 1, vr, l, r));
}

int getBad(int v, int vl, int vr, int l, int r, int val){
	if (r < vl || l > vr) return -1;
	int vm = (vl + vr) >> 1;
	if (vl >= l && vr <= r){
		if (t[v] % val == 0) return -1;
		if (vl == vr) return vl;
		if (t[v * 2 + 1] % val != 0) return getBad(v * 2 + 1, vl, vm, l, r, val);
		return getBad(v * 2 + 2, vm + 1, vr, l, r, val);
	}
	int now = getBad(v * 2 + 1, vl, vm, l, r, val);
	if (now != -1) return now;
	return getBad(v * 2 + 2, vm + 1, vr, l, r, val);
}

int n, m;

int main(){
	//srand(time(NULL));
//	freopen("input.txt", "r", stdin);
	//freopen("output2.txt", "w", stdout);
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++){
		int x;
		cin >> x;
		up(0, 0, n - 1, i, x);
	}
	cin >> m;
	while(m--){
		int type;
		cin >> type;
		if (type == 1){
			int l, r, x;
			cin >> l >> r >> x;
			l--; r--;
			int now = get(0, 0, n - 1, l, r);
			if (now % x == 0){
				cout << "YES\n";
				continue;
			}
			int pos = getBad(0, 0, n - 1, l, r, x);
			now = gcd(get(0, 0, n - 1, l, pos - 1), get(0, 0, n - 1, pos + 1, r));
			if (now % x == 0){
				cout << "YES\n";
			} else cout << "NO\n";
		} else {
			int v, val;
			cin >> v >> val;
			up(0, 0, n - 1, v - 1, val);
		}
	}
}