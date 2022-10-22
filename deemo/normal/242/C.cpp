#include<iostream>
#include<algorithm>
#include<vector>
#include<map>
#include<utility>

using namespace std;

const int MAXN = 2e5 + 20;

int a, b, c, d, n;
map<pair<int, int>, int>	mp, ok;
pair<int, int>	q[MAXN];

void bfs(int x, int y){
	mp[{x, y}] = 0;
	int h = 0, t = 0;
	q[t++] = {x, y};

	while (h < t){
		x = q[h].first;
		y = q[h++].second;

		for (int i = -1; i <= 1; i++)
			for (int j = -1; j <= 1; j++)
				if (mp.count({x + i, y + j}) == 0 && ok[{x + i, y + j}]){
					mp[{x + i, y + j}] = mp[{x, y}] + 1;
					q[t++] = {x + i, y + j};
				}
	}
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> a >> b >> c >> d;
	cin >> n;
	while (n--){
		int x, l, r;	cin >> x >> l >> r;	
		for (; l <= r; l++)
			ok[{x, l}] = 1;
	}
	bfs(a, b);
	if (mp.count({c, d}) == 0)	
		cout << -1 << endl;
	else
		cout << mp[{c, d}] << endl;
	return 0;
}