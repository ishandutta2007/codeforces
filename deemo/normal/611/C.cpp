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

const int MAXN = 500 + 20;

int n, m;
char c[MAXN][MAXN];
int p[MAXN][MAXN];

bool fit(int r, int c, int r1, int r2, int c1, int c2){return	r >= r1 && r < r2 && c >= c1 && c < c2;}

int main(){
	read_fast;
	cin >> n >> m;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			cin >> c[i][j];
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++){
			int cn = 0;
			if (c[i][j] == '.'){
				if (fit(i + 1, j, 0, n, 0, m) && c[i + 1][j] == '.')	cn++;
				if (fit(i, j + 1, 0, n, 0, m) && c[i][j + 1] == '.')	cn++;
			}

			p[i + 1][j + 1] = p[i][j + 1] + p[i + 1][j] - p[i][j] + cn;
		}	
	
	int q;	cin >> q;
	while (q--){
		int r1, r2, c1, c2;	cin >> r1 >> c1 >> r2 >> c2;		r1--;	c1--;
		int ans = p[r2][c2] - p[r1][c2] - p[r2][c1] + p[r1][c1];
		
		for (int i = r1; i < r2; i++)
			if (c[i][c2 - 1] == '.')
				if (fit(i, c2, 0, n, 0, m) && c[i][c2] == '.')	ans--;
		for (int j = c1; j < c2; j++)
			if (c[r2 - 1][j] == '.')
				if (fit(r2, j, 0, n, 0, m) && c[r2][j] == '.')	ans--;
		cout << ans << "\n";
	}
    return 0;
}