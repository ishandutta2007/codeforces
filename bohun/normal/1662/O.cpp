#include<bits/stdc++.h>
#define rep(i, a, b) for (int i = a; i <= b; i++)
#define cat(x) cout << #x << ": " << x << endl
#define f first
#define s second

using ll = long long;
using namespace std;

bool wall1[360][21];
bool wall2[360][21];
bool vis[360][21];

bool solve()
{
	int n;
	scanf("%d", &n);

	rep(i, 0, 359){
		rep(j, 0, 20){
			wall1[i][j] = false;
			wall2[i][j] = false;
			vis[i][j] = false;
		}
	}

	while (n--){
		char type;
		scanf(" %c ", &type);
		assert(type == 'C' || type == 'S');
		if (type == 'C'){
			int r, a1, a2;
			scanf("%d%d%d", &r, &a1, &a2);
			if (a2 < a1){
				a2 += 360;
			}
			rep(i, a1, a2 - 1){
				wall2[i % 360][r - 1] = true;
			}
		}
		if (type == 'S'){
			int r1, r2, a;
			scanf("%d%d%d", &r1, &r2, &a);
			rep(i, r1, r2 - 1){
				wall1[(a + 359) % 360][i] = true;
			}
		}
	}

	queue < pair <int,int> > Q;

	rep(i, 0, 359){
		vis[i][0] = true;
		Q.push({i, 0});
	}

	while (!Q.empty()){
		auto p = Q.front();
		Q.pop();
		int a = p.f;
		int r = p.s;
		assert(vis[a][r] == true);
		
		auto relax = [&] (int a, int r){
			assert(r >= 0 && r <= 19);
			assert(a >= 0 && a <= 359);
			if (vis[a][r] == false){
				vis[a][r] = true;
				Q.push({a, r});
			}
		};

		
		if (wall1[a][r] == false){
			relax((a + 1) % 360, r);
		}
		
		if (wall1[(a + 359) % 360][r] == false){
			relax((a + 359) % 360, r);
		}

		if (r == 19 && wall2[a][r] == false){
			return true;
		}

		if (wall2[a][r] == false){
			relax(a, r + 1);
		}

		if (r - 1 >= 0 && wall2[a][r - 1] == false){
			relax(a, r - 1);
		}
	}

	return false;
}

int main() {
	int q;
	scanf("%d", &q);
	while (q--){
		printf("%s\n", solve() ? "YES" : "NO");
	}
	return 0;
}