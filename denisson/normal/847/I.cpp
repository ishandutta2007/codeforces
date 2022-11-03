#include <bits/stdc++.h>
	  
using namespace std;
	  
typedef long long ll;
#define mp make_pair
#define pub push_back
#define x first
#define y second
#define all(a) a.begin(), a.end()
#define db double

int n, m, p, q;
char a[255][255];
int sum[255][255];
int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};

pair<pair<int, int>, int> d[255 * 255];
bool was[255][255];

void go(int x, int y, int val){
	int uk1 = 0, uk2 = 0;
	d[uk2++] = mp(mp(x, y), val);
	was[x][y] = 1;
	while(uk1 < uk2){
		auto now = d[uk1++];
		if (sum[now.x.x][now.x.y] <= p) sum[now.x.x][now.x.y] += now.y;
		if (now.y / 2 == 0) continue;
		for (int i = 0; i < 4; i++){
			int nx = now.x.x + dx[i];
			int ny = now.x.y + dy[i];
			if (nx >= 0 && ny >= 0 && nx < n && ny < m && !was[nx][ny] && a[nx][ny] != '*'){
				was[nx][ny] = 1;
				d[uk2++] = mp(mp(nx, ny), now.y / 2);
			}
		}
	}
	for (int i = 0; i < uk2; i++) was[d[i].x.x][d[i].x.y] = 0;

	/*	for (int i = 0; i < n; i++){
		for (int j = 0; j < m; j++)
		cout << sum[i][j] << ' ';
	cout << endl;
	}*/
}

int main() { 
	srand('D' + 'E' + 'N' + 'I' + 'S' + 'S' + 'O' + 'N' + time(NULL));
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	//freopen("cpr.in", "r", stdin);
	//freopen("cpr.out", "w", stdout);
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> n >> m >> q >> p;
	for (int i = 0; i < n; i++){
		for (int j = 0; j < m; j++){
			cin >> a[i][j];
		}
	}

	for (int i = 0; i < n; i++) for (int j = 0; j < m; j++) if (a[i][j] >= 'A' && a[i][j] <= 'Z') go(i, j, q * (a[i][j] - 'A'  + 1));

	

	int ans = 0;
	for (int i = 0; i < n; i++) for (int j = 0; j < m; j++) if (sum[i][j] > p) ans++;
	cout << ans;
}