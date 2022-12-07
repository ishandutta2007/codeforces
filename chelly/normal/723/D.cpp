#include<bits/stdc++.h>
using namespace std;
const int N(55);
char st[N][N];
bool vst[N][N];
int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};
int n, m;
inline bool inRange(int x, int y) {
	return 0 <= x && x < n && 0 <=y && y < m;
}
int main() {
	vector<vector<pair<int, int> > > ans;
	int k;
	scanf("%d%d%d", &n, &m, &k);
	for(int i(0); i < n; i++) {
		scanf("%s", st[i]);
	}
	for(int i(0); i < n; i++) {
		for(int j(0); j < m; j++) {
			if(st[i][j] == '.' && !vst[i][j]) {
				bool flag(false);
				vector<pair<int, int> > vec;
				vec.push_back(make_pair(i, j));
				vst[i][j] = true;
				for(int op(0); op < (int)vec.size(); op++) {
					auto v(vec[op]);
					int x(v.first), y(v.second);
					for(int d(0); d < 4; d++) {
						int X(x + dx[d]), Y(y + dy[d]);
						if(!inRange(X, Y)) {
							flag = true;
						}else if(st[X][Y] == '.' && vst[X][Y] == false) {
							vst[X][Y] = true;
							vec.push_back(make_pair(X, Y));
						}
					}
				}
				if(flag == false) {
					ans.push_back(vec);
				}
			}
		}
	}
	int res(0);
	int rmn(ans.size());
	while(rmn > k) {
		int mni(-1);
		for(int i(0); i < (int)ans.size(); i++) {
			if(ans[i].size()) {
				if(mni == -1 || ans[i].size() < ans[mni].size()) {
					mni = i;
				}
			}
		}
		res += ans[mni].size();
		for(auto i : ans[mni]) {
			st[i.first][i.second] = '*';
		}
		ans[mni].clear();	
		rmn--;
	}
	cout << res << endl;
	for(int i(0); i < n; i++) {
		cout << st[i] << endl;
	}
}