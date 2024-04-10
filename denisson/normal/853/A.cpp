#include <bits/stdc++.h>
	  
using namespace std;
	  
typedef long long ll;
#define mp make_pair
#define pub push_back
#define x first
#define y second
#define all(a) a.begin(), a.end()

int n, m;
int a[300007];
ll ans = 0;
int q[300007];

int main() { 
	srand('D' + 'E' + 'N' + 'I' + 'S' + 'S' + 'O' + 'N' + time(NULL));
	//freopen("input.txt", "r", stdin);
	//freopen("output1.txt", "w", stdout);
	//freopen("cpr.in", "r", stdin);
	//freopen("cpr.out", "w", stdout);
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> n >> m;
	for (int i = 0; i < n; i++) cin >> a[i];

	int uk = 0;

	set<pair<int, int> > se;

	for (int i = m + 1; i <= m + n; i++){
		while(uk < n && uk + 1 <= i) se.insert(mp(a[uk], uk)), uk++;
		auto now = *(--se.end());
		ans += now.x * (ll)(i - now.y - 1);
		q[now.y] = i;
		se.erase(--se.end());
	}


	cout << ans << "\n";
	for (int i = 0; i < n; i++) cout << q[i] << ' ';
}