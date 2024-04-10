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
};

int n;
int a[1111];

int main() { 
	srand('D' + 'E' + 'N' + 'I' + 'S' + 'S' + 'O' + 'N' + time(NULL));
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	//freopen("cpr.in", "r", stdin);
	//freopen("cpr.out", "w", stdout);
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++) cin >> a[i];
	bool f = 1;
	for (int i = 1; i < n; i++) if (a[i] - a[i - 1] != a[1] - a[0]) f = 0;
	if (f) cout << a[n - 1] + a[1] - a[0];
	else cout << a[n - 1];
}