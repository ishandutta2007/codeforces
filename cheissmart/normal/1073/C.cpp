#include <bits/stdc++.h>
#define IO_OP std::ios::sync_with_stdio(0); std::cin.tie(0);
#define F first
#define S second
#define PB push_back
#define MP make_pair
#define EB emplace_back
#define ALL(c) c.begin(),c.end()
#define INF int(1e9+7)

using namespace std;

typedef long long ll;
typedef pair<int, int> pi;
typedef vector<int> vi;

int px[200005], py[200005];
const char * dir = "UDLR";
const int dx[] = {0,0,-1,1}, dy[] = {1,-1,0,0};
int main()
{
	IO_OP;

	int n;
	string s;


	cin >> n >> s;
	s = ' ' + s;
	int x, y;
	cin >> x >> y;
	if(abs(x)+abs(y) > n || (abs(x)+abs(y)) % 2 != n % 2) {
		cout << -1 << endl;
		return 0;
	}
	int l = 1, r = n;
	for(int i=1;i<=n;i++) {
		px[i] = px[i-1] + dx[find(dir, dir+4, s[i])-dir];
		py[i] = py[i-1] + dy[find(dir, dir+4, s[i])-dir];
	}
	int tx = px[n], ty = py[n], ans = INF;
	for(int i=1, j=0;;i++){
		while (j<n&&abs(tx-x)+abs(ty-y) > j-i+1){
			j++;
			tx -= dx[find(dir, dir+4, s[j])-dir];
			ty -= dy[find(dir, dir+4, s[j])-dir];
		}
		if (abs(tx-x)+abs(ty-y) > j-i+1)
			break;
		ans = min(ans, j-i+1);
		tx += dx[find(dir, dir+4, s[i])-dir];
		ty += dy[find(dir, dir+4, s[i])-dir];
	}
	cout << ans << endl;
}