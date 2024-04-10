#include<iostream>
#include<cstdio>
#include<cmath>
#include<algorithm>
#include<vector>
#include<stack>
#include<queue>
#include<deque>
#include<set>
#include<map>
#include<string>
#include<utility>
#include<iomanip>
#include<fstream>
#include<list>
#include<sstream> 
#include<cstring>
#include<bitset>
#include<functional>
#include<numeric>

using namespace std;

typedef long long ll;
//#define size(x) ((int)(x).size())
#define error(x) cerr << #x << " = " << x << endl
#define pb push_back
#define setprecision(x) cout << fixed << setprecision((x))
#define read_fast ios_base::sync_with_stdio(false) , cin.tie(0)
#define PQ priority_queue;
#define to_string(x) ({ string _str; stringstream _ss; _ss << x;  _ss >> _str; _str; })
#define to_int(x) ({ int _x; stringstream _ss; _ss << x; _ss >> _x; _x; })

const int max_n = 1e3 + 10;
const int MAX = 1e6 + 10;

int n, m, q, cnt;
char c[max_n][max_n];
int save[MAX], mark[max_n][max_n];

void dfs(int y, int x, int col){
	mark[y][x] = col;
	if (c[y + 1][x] == '*')	cnt++, mark[y + 1][x] = col;
	if (c[y - 1][x] == '*')	cnt++, mark[y - 1][x] = col;
	if (c[y][x + 1] == '*')	cnt++, mark[y][x + 1] = col;
	if (c[y][x - 1] == '*')	cnt++, mark[y][x - 1] = col;

	if (mark[y + 1][x] != col)
		if (c[y + 1][x] != '*')	dfs(y + 1, x, col);
	if (mark[y - 1][x] != col)
		if (c[y - 1][x] != '*')	dfs(y - 1, x, col);
	if (mark[y][x + 1] != col)
		if (c[y][x + 1] != '*')	dfs(y, x + 1, col);
	if (mark[y][x - 1] != col)
		if (c[y][x - 1] != '*')	dfs(y, x - 1, col);
}

int main(){
	read_fast;
	cin >> n >> m >> q;
	for (int i = 0; i < n; i++){
		string temp;	cin >> temp;
		for (int j = 0; j < m; j++)
			c[i][j] = temp[j];
	}

	int g = 1;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++){
			if (mark[i][j])	continue;
			if (c[i][j] == '*')	continue;
			cnt = 0;
			dfs(i, j, g);
			save[g] = cnt;
			g++;
		}

	while (q--){
		int y, x;	cin >> y >> x;	y--, x--;
		cout << save[mark[y][x]] << endl;
	}
    return 0;
}