#include<iostream>
#include<string>
#include<algorithm>
#include<cstring>
#include<utility>

using namespace std;

const int MAXN = 1e5 + 10;

int n, k, lv[2][MAXN], ans = 1e9;
string s[2];
pair<int, int>	q[3 * MAXN];

bool fit(int a, int b){return 0 <= b && b < n && s[a][b] != 'X';}

void bfs(int a, int b){
	memset(lv, 63, sizeof(lv));
	lv[a][b] = 0;
	int h = 0, t = 0;
	q[t++] = {a, b};
	while (h < t){
		a = q[h].first, b = q[h].second;
		h++;
		if (fit(a, b - 1) && lv[a][b] + 1 < lv[a][b - 1]){
			lv[a][b - 1] = lv[a][b] + 1;
			if (lv[a][b - 1] <= b - 1)
				q[t++] = {a, b - 1};
		}
		if (fit(a, b + 1) && lv[a][b] + 1 < lv[a][b + 1]){
			lv[a][b + 1] = lv[a][b] + 1;
			q[t++] = {a, b + 1};
		}
		else if (b + 1 >= n)	ans = 1;

		if (fit(1 - a, b + k) && lv[a][b] + 1 < lv[1 - a][b + k]){
			lv[1-a][b + k] = lv[a][b] + 1;
			q[t++] = {1-a, b + k};
		}
		else if (b + k >= n)	ans = 1;
	}
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> k;
	cin >> s[0] >> s[1];
	bfs(0, 0);
	if (ans > 1e8)
		cout << "NO\n";
	else
		cout << "YES\n";
	return 0;
}