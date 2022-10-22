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

const int MAX = 50;
const int max_n = 30;
const ll INF = 1e9;

int d[max_n + 5][max_n + 5][MAX + 5];

int main(){
	read_fast;
	int t;	cin >> t;
	for (int i = 0; i <= max_n; i++)
		for (int j = 0; j <= max_n; j++)
			for (int k = 0; k <= MAX; k++)
				d[i][j][k] = INF;

	d[1][1][0] = d[1][1][1] = 0;
	for (int i = 1; i <= max_n; i++)
		for (int j = 1; j <= max_n; j++){
			if (i == j && i == 1)	continue;
			d[i][j][0] = 0;
			if (i * j <= MAX)	d[i][j][i * j] = 0;
			for (int k = 1; k <= min(MAX, i * j); k++)
				for (int p = 0; p <= k; p++){
					for (int w = 1; w < i; w++)
						d[i][j][k] = min(d[i][j][k], j * j + d[w][j][p] + d[i - w][j][k - p]);
					for (int w = 1; w < j; w++)
						d[i][j][k] = min(d[i][j][k], i * i + d[i][w][p] + d[i][j - w][k - p]);
				}
		}

	while (t--){
		int a, b, c;	cin >> a >> b >> c;
		cout << d[a][b][c] << endl;
	}
	return 0;
}