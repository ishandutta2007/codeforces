#include <bits/stdc++.h>
	  
using namespace std;
	  
typedef long long ll;
#define mp make_pair
#define pub push_back
#define x first
#define y second
#define all(a) a.begin(), a.end()
#define db double

int n;
pair<int, int> a[111];

int dfs(int v){
	if (a[v].y == 0) return v;
	return dfs(a[v].y);
}

int main() { 
	srand('D' + 'E' + 'N' + 'I' + 'S' + 'S' + 'O' + 'N' + time(NULL));
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	//freopen("cpr.in", "r", stdin);
	//freopen("cpr.out", "w", stdout);
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> a[i].x >> a[i].y;
	vector<pair<int, int> > t;
	for (int i = 1; i <= n; i++) if (a[i].x == 0){
		auto now = dfs(i);
		t.pub(mp(i, now));
		//cout << i << ' ' << now << endl;
		//cout << endl;
	}

	for (int i = 1; i < t.size(); i++){
		a[t[i - 1].y].y = t[i].x;
		a[t[i].x].x = t[i - 1].y;
	}

	for (int i = 1; i <= n; i++) cout << a[i].x << ' ' << a[i].y << "\n";
}