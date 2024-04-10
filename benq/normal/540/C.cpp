#include <bits/stdc++.h>
using namespace std;
 
#define ll long long
#define mp make_pair
#define pb push_back
#define pii pair <int, int>
#define vi vector<int>

#define FOR(i, a, b) for (int i=a; i<b; i++)
#define FORd(i, a, b) for (int i=a-1; i>=b; i--)
#define F0Rd(i, a) for (int i=a-1; i>=0; i--)
#define F0R(i, a) for (int i=0; i<a; i++)
 
#define f first
#define s second
#define be begin
#define e end
#define lb lower_bound
#define ub upper_bound
 
const int MOD = 1000000007;

int n,m, x1,y11,x2,y2,visit[500][500];
int xdir[4] = {-1,0,1,0}, ydir[4] = {0,1,0,-1};

int flood_fill(int x, int y) {
	if (x == x2 && y == y2) return 1;
	if (visit[x][y]  == 0) {
		visit[x][y] = 1;
		F0R(i,4) {
			if (x+xdir[i] >= 0 && x+xdir[i] < m && y+ydir[i] >= 0 && y+ydir[i] < n) {
				if (flood_fill(x+xdir[i],y+ydir[i])) return 1;
			}
		}
	}
	return 0;
}

int main() {
	cin >> n >> m;
	F0R(i,n) {
		F0R(j,m) {
			char k;
			cin >> k;
			if (k == 'X') visit[j][i] = 1;
		}
	}

	cin >> y11 >> x1 >> y2 >> x2;
	y11--, x1--, y2--, x2--;
	if (visit[x2][y2] == 0) {
		int a = 0;
		F0R(i,4) {
			if (x2+xdir[i] >= 0 && x2+xdir[i] < m && y2+ydir[i] >= 0 && y2+ydir[i] < n && !visit[x2+xdir[i]][y2+ydir[i]]) {
				a++;
			} else if (x2+xdir[i] == x1 && y2+ydir[i] == y11) {
				a++;
			}
		}
		
		if (a < 2) {
			cout << "NO";
			return 0;
		}
	}
	if (x1 == x2 && y11 == y2) {
		int a = 0;
		F0R(i,4) {
			if (x2+xdir[i] >= 0 && x2+xdir[i] < m && y2+ydir[i] >= 0 && y2+ydir[i] < n && !visit[x2+xdir[i]][y2+ydir[i]]) {
				a++;
			}
		}
		if (a < 1) {
			cout << "NO";
			return 0;
		}
	}
	visit[x1][y11] = 0;
	if (flood_fill(x1,y11)) cout << "YES";
	else cout << "NO";
	return 0;
}