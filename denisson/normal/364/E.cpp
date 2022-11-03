#include <bits/stdc++.h>
  
using namespace std;
  
typedef long long ll;
#define mp make_pair
#define pb push_back
#define x first
#define y second
#define all(a) a.begin(), a.end()
#define db long double

int n, m, k;
bool a[2501][2501];
int sum[2501][2501];
ll ans = 0;
  
int get(int x1, int x2, int y1, int y2){
	return sum[x2][y2] - sum[x1 - 1][y2] - sum[x2][y1 - 1] + sum[x1 - 1][y1 - 1];
}

void solve(int x1, int y1, int x2, int y2){
	//cout << x1 << ' ' << y1 << ' ' << x2 << ' ' << y2 << endl;
	if (x1 == x2 && y1 == y2){
		ans += a[x1][y1] == k;
		return;
	}
	if (y2 - y1 > x2 - x1){
		int yy = (y2 + y1) >> 1;
		for (int c = 0; c <= k; c++){
			int c1 = c, c2 = k - c;
			for (int i = x1; i <= x2; i++){
				int l1 = y1, r1 = y1;
				int l2 = y2, r2 = y2;
				for (int j = i; j <= x2; j++){
					while(l1 <= yy && get(i, j, l1, yy) >= c1) l1++;
					while(r1 <= yy && get(i, j, r1, yy) > c1) r1++;
					if (r1 > yy) break;
					while(l2 > yy && get(i, j, yy + 1, l2) >= c2) l2--;
					while(r2 > yy && get(i, j, yy + 1, r2) > c2) r2--;
					if (r2 <= yy) break;
					ll w1 = 0, w2 = 0;
					if (get(i, j, r1, yy) == c1) w1 = l1 - r1;
					if (get(i, j, yy + 1, r2) == c2) w2 = r2 - l2;
					ans += w1 * w2;
				}
			}
		}
		solve(x1, y1, x2, yy);
		solve(x1, yy + 1, x2, y2);
	} else {
		int xx = (x1 + x2) >> 1;
		for (int c = 0; c <= k; c++){
			int c1 = c, c2 = k - c;
			for (int i = y1; i <= y2; i++){
				int l1 = x1, r1 = x1;
				int l2 = x2, r2 = x2;
				for (int j = i; j <= y2; j++){
					while(l1 <= xx && get(l1, xx, i, j) >= c1) l1++;
					while(r1 <= xx && get(r1, xx, i, j) > c1) r1++;
					if (r1 > xx) break;
					while(l2 > xx && get(xx + 1, l2, i, j) >= c2) l2--;
					while(r2 > xx && get(xx + 1, r2, i, j) > c2) r2--;
					if (r2 <= xx) break;
					ll w1 = 0, w2 = 0;
					if (get(r1, xx, i, j) == c1) w1 = l1 - r1;
					if (get(xx + 1, r2, i, j) == c2) w2 = r2 - l2;
					ans += w1 * w2;
				}
			}
		}
		solve(x1, y1, xx, y2);
		solve(xx + 1, y1, x2, y2);
	}
}

int main(){
    //freopen("input.txt", "r", stdin);
    //freopen("output1.txt", "w", stdout);
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n >> m >> k;
    for (int i = 1; i <= n; i++){
    	for (int j = 1; j <= m; j++){
    		char c;
    		cin >> c;
    		a[i][j] = c - '0';
    		sum[i][j] = a[i][j] + sum[i - 1][j] + sum[i][j - 1] - sum[i - 1][j - 1];
    	}
    }

    solve(1, 1, n, m);

    cout << ans;
}