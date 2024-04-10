#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define F first
#define S second

const int MAXN = 500 + 5;

int n, a[MAXN][MAXN];
int dx[2] = {1, 0};
int dy[2] = {0, 1};

bool fit(int x, int y){return 1 <= x && x <= n && 1 <= y && y <= n && a[x][y];}

bool ok1(int x, int y){
	cout << "? " << x << " " << y << " " << n << " " << n << endl;
	string t; cin >> t;
	return t[0] == 'Y';
}

bool ok2(int x, int y){
	cout << "? " << 1 << " " << 1 << " " << x << " " << y << endl;
	string t; cin >> t;
	return t[0] == 'Y';
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	a[1][1] = a[n][n] = 1;
	int x = 1, y = 1;
	while (x + y < n + 1){
		if (x + 1 <= n && ok1(x+1, y)) x++;
		else y++;
		a[x][y] = 1;
	}
	x = n, y = n;
	while (x+y > n+1){
		if (y - 1 >= 1 && ok2(x, y - 1)) y--;
		else x--;
		a[x][y] = 1;
	}
	x = 1, y = 1;
	string ans;
	while (x + y < n + n){
		if (fit(x+dx[0], y+dy[0]))
			x += dx[0], y += dy[0], ans += 'D';
		else
			x += dx[1], y += dy[1], ans += 'R';
	}
	cout << "! " << ans << endl;
	return 0;
}