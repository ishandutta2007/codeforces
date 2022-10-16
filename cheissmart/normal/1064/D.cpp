#include <bits/stdc++.h>
#define INF 2147483647

using namespace std;

typedef pair<int, int> pii;

char mz[2048][2048];
int a[2048][2048], cnt[2048*2048];
pii vis[2048*2048];

vector<int> gl[2048*2048], gr[2048*2048];

int main()
{
	int n, m, r, c, x, y;
	cin >> n >> m >> r >> c >> x >> y;
	r--, c--;
	for(int i=0;i<n;i++)	
		for(int j=0;j<m;j++)
			cin >> mz[i][j];
	int ct = 1;
	for(int j=0;j<m;j++) {
		for(int i=0;i<n;i++) {
			if(mz[i][j] == '*') {
				ct++;
				continue;
			}
			a[i][j] = ct;
			cnt[ct]++;
		}
		ct++;
	}

	for(int i=0;i<n;i++) {
		for(int j=0;j<m-1;j++) {
			if(a[i][j+1] && a[i][j]) {
				gr[a[i][j]].push_back(a[i][j+1]);
				gl[a[i][j+1]].push_back(a[i][j]);
			}
		}
	}
	for(int i=1;i<=ct;i++) {
		sort(gr[i].begin(), gr[i].end());
		sort(gl[i].begin(), gl[i].end());
		gr[i].resize(unique(gr[i].begin(), gr[i].end())-gr[i].begin());
		gl[i].resize(unique(gl[i].begin(), gl[i].end())-gl[i].begin());
	}
	fill(vis, vis+ct+1, pii(-1, -1));
	int s = a[r][c];
	vis[s] = {x, y};
	vector<int> q;
	q.push_back(s);
	for(int i=0;i<q.size();i++) {
		int k = q[i];
		for(int j=0;j<gl[k].size();j++) {
			if(vis[gl[k][j]] == pii(-1, -1) && vis[k].first > 0) {
				q.push_back(gl[k][j]);
				vis[gl[k][j]] = {vis[k].first-1, vis[k].second};
			}
		}
		for(int j=0;j<gr[k].size();j++) {
			if(vis[gr[k][j]] == pii(-1, -1) && vis[k].second > 0) {
				q.push_back(gr[k][j]);
				vis[gr[k][j]] = {vis[k].first, vis[k].second-1};
			}
		}
	}
	int ans = 0;
	for(int i:q) {
		ans += cnt[i];
	}
	cout << ans << endl;
}