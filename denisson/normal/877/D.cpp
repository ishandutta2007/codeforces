#include <bits/stdc++.h>
        
using namespace std;
        
typedef long long ll;
#define mp make_pair
#define pub push_back
#define x first
#define y second
#define all(a) a.begin(), a.end()
#define db double

#define x1 dfgdg1
#define y1 dfgdg2
#define x2 dfgdg3
#define y2 dfgdg4

int n, m, k, x1, y1, x2, y2;
char a[1007][1007];
int sum[1007][1007];
set<pair<int, int> > se1[1007], se2[1007];
int ans[1007][1007];

int getSum(int x1, int y1, int x2, int y2){
	if (x1 > x2) swap(x1, x2);
	if (y1 > y2) swap(y1, y2);
	return sum[x2][y2] - sum[x1 - 1][y2] - sum[x2][y1 - 1] + sum[x1 - 1][y1 - 1];
}

int getDist(pair<int, int> a, pair<int, int> b){
	return abs(a.x - b.x) + abs(a.y - b.y);
}

int main(){ 
    //freopen("input.txt", "r", stdin);
    //freopen("output1.txt", "w", stdout);
    //freopen("heavy.in", "r", stdin);
    //freopen("heavy.out", "w", stdout);
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n >> m >> k;
    for (int i = 1; i <= n; i++) for (int j = 1; j <= m; j++) cin >> a[i][j];
    cin >> x1 >> y1 >> x2 >> y2;

	for (int i = 1; i <= n; i++) for (int j = 1; j <= m; j++){
		sum[i][j] = sum[i - 1][j] + sum[i][j - 1] - sum[i - 1][j - 1] + (a[i][j] == '#');
	}

	for (int i = 1; i <= n; i++){
		for (int j = 1; j <= m; j++) if (a[i][j] == '.'){
			se1[i].insert(mp(i, j));
			se2[j].insert(mp(i, j));
		}
	}

	for (int i = 1; i <= n; i++) for (int j = 1; j <= m; j++) ans[i][j] = -1;
	ans[x1][y1] = 0;
	vector<pair<int, int > > st;
	int uk = 0;
	st.pub(mp(x1, y1));
	se1[x1].erase(mp(x1, y1));
	se2[y1].erase(mp(x1, y1));
	
	while(uk < st.size()){
		auto v = st[uk++];
		//cout << v.x << ' ' << v.y << endl;
		while(1){
			if (se1[v.x].upper_bound(v) == se1[v.x].end()) break;
			auto to = *se1[v.x].upper_bound(v);
			if (getSum(v.x, v.y, to.x, to.y) > 0) break;
			if (getDist(v, to) > k) break;
			ans[to.x][to.y] = ans[v.x][v.y] + 1;
			st.pub(mp(to.x, to.y));
			se1[to.x].erase(to);
			se2[to.y].erase(to);
		}

		while(1){
			if (se1[v.x].upper_bound(v) == se1[v.x].begin()) break;
			auto to = *(--se1[v.x].upper_bound(v));
			if (getSum(v.x, v.y, to.x, to.y) > 0) break;
			if (getDist(v, to) > k) break;
			ans[to.x][to.y] = ans[v.x][v.y] + 1;
			st.pub(mp(to.x, to.y));
			se1[to.x].erase(to);
			se2[to.y].erase(to);
		}

		while(1){
			if (se2[v.y].upper_bound(v) == se2[v.y].end()) break;
			auto to = *se2[v.y].upper_bound(v);
			if (getSum(v.x, v.y, to.x, to.y) > 0) break;
			if (getDist(v, to) > k) break;
			ans[to.x][to.y] = ans[v.x][v.y] + 1;
			st.pub(mp(to.x, to.y));
			se1[to.x].erase(to);
			se2[to.y].erase(to);
		}


		while(1){
			if (se2[v.y].upper_bound(v) == se2[v.y].begin()) break;
			auto to = *(--se2[v.y].upper_bound(v));
			if (getSum(v.x, v.y, to.x, to.y) > 0) break;
			if (getDist(v, to) > k) break;
			ans[to.x][to.y] = ans[v.x][v.y] + 1;
			st.pub(mp(to.x, to.y));
			se1[to.x].erase(to);
			se2[to.y].erase(to);
		}
	}


	cout << ans[x2][y2];
}