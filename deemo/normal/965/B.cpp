#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define F first
#define S second

const int MAXN = 100 + 5;

int n, k, pt[MAXN][MAXN];
string s[MAXN];

void add(int x, int y, int xx, int yy){
	x++, y++, xx++, yy++;
	pt[x][y]++;
	pt[xx][y]--;
	pt[x][yy]--;
	pt[xx][yy]++;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> k;
	for (int i = 0; i < n; i++) cin >> s[i];
	for (int i = 0; i < n; i++){
		for (int l = 0; l < n;){
			if (s[i][l] == '#'){
				l++;
				continue;
			}

			int r = l;
			while (r < n && s[i][r] == '.') r++;

			for (int j = l; j + k <= r; j++)
				add(i, j, i+1, j+k);
			l = r;
		}
	}
	for (int j = 0; j < n; j++){
		for (int l = 0; l < n; ){
			if (s[l][j] == '#'){
				l++;
				continue;
			}

			int r = l;
			while (r < n && s[r][j] == '.') r++;

			for (int i = l; i + k <= r; i++)
				add(i, j, i+k, j+1);
			l = r;
		}
	}

	int mx = 0;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			pt[i+1][j+1] += pt[i+1][j] + pt[i][j+1] - pt[i][j], mx = max(mx, pt[i+1][j+1]);
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			if (pt[i+1][j+1] == mx){
				cout << i+1 << " " << j+1 << endl;
				return 0;
			}
	return 0;
}