#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (int)(n); i ++)
#define rep1(i, n) for(int i = 1; i <= (int)(n); i ++)
#define MP make_pair

using namespace std;
typedef long long LL;
typedef pair<int, int> PII;
const int INF = 0x3f3f3f3f;

int n, m;
string ch[1000005];
vector<int> dis[1000005];

int dx[8] = {0, -1, 0, 1, 1, -1, -1, 1}, dy[8] = {-1, 0, 1, 0, -1, -1, 1, 1};
void bfs0()
{
	rep(i, n) dis[i].resize(m, INF);
	queue<PII> que;
	rep(i, n) rep(j, m) if(ch[i][j] == '.') {
		dis[i][j] = 0;
		que.push(MP(i, j));
	}
	
	while(!que.empty()) {
		int cx = que.front().first, cy = que.front().second;
		que.pop();
		rep(i, 8) {
			int nx = cx + dx[i], ny = cy + dy[i];
			if(nx < 0 || ny < 0 || nx >= n || ny >= m || dis[nx][ny] != INF) continue;
			dis[nx][ny] = dis[cx][cy] + 1;
			que.push(MP(nx, ny));
		}
	}
}

vector<int> rec[1000005];

bool check(int md)
{
	rep(i, n) rep(j, m) rec[i][j] = INF;
	queue<PII> que;
	rep(i, n) rep(j, m) if(ch[i][j] == 'X' && dis[i][j] > md) {
		rec[i][j] = 0;
		que.push(MP(i, j));
	}
	
	while(!que.empty()) {
		int cx = que.front().first, cy = que.front().second;
		que.pop();
		rep(i, 8) {
			int nx = cx + dx[i], ny = cy + dy[i];
			if(nx < 0 || ny < 0 || nx >= n || ny >= m || rec[nx][ny] != INF) continue;
			rec[nx][ny] = rec[cx][cy] + 1;
			que.push(MP(nx, ny));
		}
	}
	
	rep(i, n) rep(j, m) if(ch[i][j] == 'X' && rec[i][j] > md) return false;
	return true;
} 

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m;
	rep(i, n) cin >> ch[i + 1];
	ch[0] = ch[n + 1] = string(m + 2, '.');
	rep(i, n) ch[i + 1] = '.' + ch[i + 1] + '.';
	n += 2;
	m += 2;
	
	bfs0();
	rep(i, n) rec[i].resize(m);
	
	int l = 0, r = n + m;
	while(l < r) {
		int mid = l + r + 1 >> 1;
		if(check(mid)) l = mid;
		else r = mid - 1;
	}
	
	check(r);
	cout << r << endl;

	rep1(i, n - 2) {
		rep1(j, m - 2) cout << (dis[i][j] > r ? 'X' : '.');
		cout << '\n';
	}
	return 0;
}