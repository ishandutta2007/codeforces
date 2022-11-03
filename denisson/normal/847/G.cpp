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
int a[7][200007];

int main() { 
	srand('D' + 'E' + 'N' + 'I' + 'S' + 'S' + 'O' + 'N' + time(NULL));
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	//freopen("cpr.in", "r", stdin);
	//freopen("cpr.out", "w", stdout);
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++){
		for (int j = 0; j < 7; j++){
			char c;
			cin >> c;
			a[j][i] = c - '0';
		}
	}
	int ans = 0;
	for (int i = 0; i < 7; i++){
		int now = 0;
		for (int j = 0; j < n; j++) now += a[i][j];
		ans = max(ans, now);
	}
	cout << ans;
	exit(0);
	//for (int i = 0; i < n; i++) cin >> a[i];
}