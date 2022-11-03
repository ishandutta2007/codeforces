#include <bits/stdc++.h>
	  
using namespace std;
	  
typedef long long ll;
#define mp make_pair
#define pub push_back
#define x first
#define y second
#define all(a) a.begin(), a.end()
#define db double

int n, t;
int a[200007];

unordered_map<int, int> fen;

int MAXVAL = (int)2e9 + 7;

void up(int v){
	for (; v < MAXVAL; v = (v + 1) | v) fen[v]++;
}

int get(int v){
	int ans = 0;
	for (; v >= 0; v = (v & (v + 1)) - 1) ans += fen[v];
	return ans;
}

int main() { 
	srand('D' + 'E' + 'N' + 'I' + 'S' + 'S' + 'O' + 'N' + time(NULL));
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	//freopen("cpr.in", "r", stdin);
	//freopen("cpr.out", "w", stdout);
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> n >> t;
	for (int i = 0; i < n; i++) cin >> a[i];
	int ans = 0;

	for (int i = 0; i < n; i++){
		int ost = t - i - 1;
		if (ost < 0) break;	
		int val = max(0, a[i] - i - 1);
		ans = max(ans, get(ost));
		if (ost != 0){
			up(val);
			ans = max(ans, get(ost - 1));
		}
	}

	cout << ans;
}