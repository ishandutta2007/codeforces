#include <iostream>
#include <vector>
#define mp make_pair
#define fi first
#define se second
#define maxn 2003
using namespace std;
vector < pair <int, int> > G[102];
int a[maxn][maxn], b[maxn][maxn], ans[maxn][4];
string s[maxn];
int main(){
	int T;
	cin >> T;
	while (T --){
		int n, m;
		cin >> n >> m;
		for (int i = 1; i <= 26; ++ i)
			G[i].clear();
		int mx = 0;
		for (int i = 1; i <= n; ++ i){
			cin >> s[i];
			for (int j = 1; j <= m; ++ j){
				if (s[i][j - 1] != '.'){
					mx = max(mx, a[i][j] = s[i][j - 1] - 'a' + 1);
					G[a[i][j]].push_back(mp(i, j));
				}
				else
					a[i][j] = 0;
				b[i][j] = 0;
			}
		}
		bool flag = false;
		int x = 0;
		for (int i = 1; i <= mx; ++ i){
			if (G[i].size() == 0){
				++ x;
				ans[x][0] = ans[x][2] = G[mx][0].fi;
				ans[x][1] = ans[x][3] = G[mx][0].se;
				continue;
			}
			if (G[i].size() == 1){
				b[G[i][0].fi][G[i][0].se] = -1;
				++ x;
				ans[x][0] = ans[x][2] = G[i][0].fi;
				ans[x][1] = ans[x][3] = G[i][0].se;
				continue;
			}
			if (G[i][0].fi == G[i][1].fi){
				int t = G[i][0].fi;
				for (int j = 2; j < G[i].size(); ++ j)
					if (G[i][j].fi != t)
						flag = true;
				int l = m + 1, r = 0;
				for (int j = 0; j < G[i].size(); ++ j){
					r = max(G[i][j].se, r);
					l = min(G[i][j].se, l);
				}
				for (int j = l; j <= r; ++ j)
					if (b[t][j] == -1 || a[t][j] == 0)
						flag = true;
					else
						b[t][j] = i;
				for (int j = 0; j < G[i].size(); ++ j)
					b[G[i][j].fi][G[i][j].se] = -1;
				++ x;
				ans[x][0] = ans[x][2] = t;
				ans[x][1] = l, ans[x][3] = r;
			}
			else{
				int t = G[i][0].se;
				for (int j = 1; j < G[i].size(); ++ j)
					if (G[i][j].se != t)
						flag = true;
				int l = n + 1, r = 0;
				for (int j = 0; j < G[i].size(); ++ j){
					r = max(G[i][j].fi, r);
					l = min(G[i][j].fi, l);
				}
				for (int j = l; j <= r; ++j)
					if (b[j][t] == -1 || a[j][t] == 0)
						flag = true;
					else
						b[j][t] = i;
				for (int j = 0; j < G[i].size(); ++ j)
					b[G[i][j].fi][G[i][j].se] = -1;
				++ x;
				ans[x][0] = l, ans[x][2] = r;
				ans[x][1] = ans[x][3] = t;
			}
		}
		if (! flag){
			for (int i = 1; i <= n; ++ i)
				for (int j = 1; j <= m; ++ j)
					if (b[i][j] != -1 && a[i][j] != b[i][j])
						flag = true;
		}
		if (! flag){
			cout << "YES" << endl << x << endl;
			for (int i = 1; i <= x; ++ i)
				cout << ans[i][0] << " " << ans[i][1] << " " << ans[i][2] << " " <<ans[i][3] << endl;
		}
		else
			cout << "NO" << endl;
	}
}