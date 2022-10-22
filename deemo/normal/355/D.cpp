//I lay dying, and I'm pouring crimson regret and betrayal..

#include<iostream>
#include<algorithm>
#include<vector>
#include<utility>
#include<cassert>
#include<cstring>

using namespace std;

const int MAXN = 20 + 1;
const int INF = 1e3;

int n, sz;
char c[MAXN][MAXN];
short d[2 * MAXN][1<<MAXN];
int ss[1<<MAXN][28];
bool vis[2 * MAXN][1<<MAXN];

bool fit(int a, int b){return 0 <= a && a < n && 0 <= b && b < n;}

short solve(int ind, int mask){
	if (ind == 2 * n - 2)	return	0;
	if (vis[ind][mask])
		return	d[ind][mask];
	vis[ind][mask] = 1;
	sz++;

	for (int i = 0; i < n; i++)
		if ((mask >> i) & 1){
			int a = i, b = ind - i;
			if (fit(a + 1, b))
				ss[sz][c[a + 1][b] - 'a'] |= 1<<(a + 1);
			if (fit(a, b + 1))
				ss[sz][c[a][b + 1] - 'a'] |= 1<<a;
		}
	int ts = sz;

	short dif = (ind % 2 == 0)?INF:-INF;
	for (char i = 'a'; i <= 'z'; i++)
		if (ss[ts][i - 'a']){
			if (ind % 2 == 1)
				dif = max(dif, (short)(solve(ind + 1, ss[ts][i - 'a']) + short(i == 'a') - short(i == 'b')));
			else
				dif = min(dif, (short)(solve(ind + 1, ss[ts][i - 'a']) + short(i == 'a') - short(i == 'b')));
		}

	return	d[ind][mask] = dif;
}

int main(){
	cin >> n;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)	cin >> c[i][j];
	auto x = solve(0, 1);
	if (c[0][0] == 'a')	x++;
	if (c[0][0] == 'b')	x--;

	if (x == 0)
		cout << "DRAW\n";
	else if (x > 0)
		cout << "FIRST\n";
	else
		cout << "SECOND\n";
	return	0;
}