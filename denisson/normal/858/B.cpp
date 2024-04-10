#include <bits/stdc++.h>
	  
using namespace std;
	  
typedef long long ll;
#define mp make_pair
#define pub push_back
#define x first
#define y second
#define all(a) a.begin(), a.end()
#define db double

bool can[111];
int n, m;

int get(int x, int y){
	int ans = 1;

	while(1){
		if (x <= y) break;
		else x -= y, ans++;
	}

	return ans;
}

int main() { 
	srand('D' + 'E' + 'N' + 'I' + 'S' + 'S' + 'O' + 'N' + time(NULL));
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	//freopen("cpr.in", "r", stdin);
	//freopen("cpr.out", "w", stdout);
	ios_base::sync_with_stdio(0); cin.tie(0);
	for (int i = 1; i < 111; i++) can[i] = 1;
	cin >> n >> m;
	if (n == 1) cout << 1, exit(0);

	bool f = 1;
	int ma = 0;

	for (int i = 0; i < m; i++){
		int a, b;
		cin >> a >> b;
		if (b != 1) f = 0;
		ma = max(ma, a);
		for (int s = 1; s < 111; s++) if (get(a, s) != b) can[s] = 0;
	}

	if (f){
		if (n <= ma) cout << 1;
		else cout << -1;
		exit(0);
	}

	set<int> tt;
	for (int i = 1; i < 111; i++) if (can[i]){
		tt.insert(get(n, i));
	}		
	if (tt.size() != 1) cout << -1;
	else cout << *tt.begin();
}