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

const int INF = 1e9;
const int max_n = 1e3 + 100;

char c[max_n][max_n];
int n, m;
int d[4][max_n][max_n], mark[max_n][max_n];
deque<pair<int, int>>	st;
vector<pair<int, int>>	vec[4];

void f(int ind){
	st.clear();
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			d[ind][i][j] = INF;

	for (pair<int, int>	u:vec[ind]){
		d[ind][u.first][u.second] = 0;
		st.push_back(u);
		mark[u.first][u.second] = ind + 1;
	}

	while (!st.empty()){
		pair<int, int>	fr = st.front();
		st.pop_front();
		if (fr.first + 1 < n && mark[fr.first + 1][fr.second] != ind + 1)
			if (c[fr.first + 1][fr.second] != '#'){
				mark[fr.first + 1][fr.second] = ind + 1;
				d[ind][fr.first + 1][fr.second] = d[ind][fr.first][fr.second] + bool(c[fr.first + 1][fr.second] == '.');
				if (c[fr.first + 1][fr.second] == '.')	st.push_back({fr.first + 1, fr.second});
				else	st.push_front({fr.first + 1, fr.second});
			}	

		if (fr.first - 1 >= 0 && mark[fr.first - 1][fr.second] != ind + 1)
			if (c[fr.first - 1][fr.second] != '#'){
				mark[fr.first - 1][fr.second] = ind + 1;
				d[ind][fr.first - 1][fr.second] = d[ind][fr.first][fr.second] + bool(c[fr.first - 1][fr.second] == '.');
				if (c[fr.first - 1][fr.second] == '.')	st.push_back({fr.first - 1, fr.second});
				else	st.push_front({fr.first - 1, fr.second});
			}
		if (fr.second + 1 < m && mark[fr.first][fr.second + 1] != ind + 1)
			if (c[fr.first][fr.second + 1] != '#'){
				mark[fr.first][fr.second + 1] = ind + 1;
				d[ind][fr.first][fr.second + 1] = d[ind][fr.first][fr.second] + bool(c[fr.first][fr.second + 1] == '.');
				if (c[fr.first][fr.second + 1] == '.')	st.push_back({fr.first, fr.second + 1});
				else	st.push_front({fr.first, fr.second + 1});
			}
		if (fr.second - 1 >= 0 && mark[fr.first][fr.second - 1] != ind + 1)
			if (c[fr.first][fr.second - 1] != '#'){
				mark[fr.first][fr.second - 1] = ind + 1;
				d[ind][fr.first][fr.second - 1] = d[ind][fr.first][fr.second] + bool(c[fr.first][fr.second - 1] == '.');
				if (c[fr.first][fr.second - 1] == '.')	st.push_back({fr.first, fr.second - 1});
				else	st.push_front({fr.first, fr.second - 1});
			}
	}	
}

int main(){
	read_fast;
	cin >> n >> m;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++){
			cin >> c[i][j];
			if (c[i][j] == '1')	vec[0].push_back({i, j});
			if (c[i][j] == '2')	vec[1].push_back({i, j});
			if (c[i][j] == '3')	vec[2].push_back({i, j});
		}
	for (int i = 0; i < 3; i++)
		f(i);

	int ans = INF;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++){
			if (d[0][i][j] == INF || d[1][i][j] == INF || d[2][i][j] == INF)	continue;
			int t = d[0][i][j] + d[1][i][j] + d[2][i][j], cnt = 0;
			if (d[0][i][j])	cnt++;
			if (d[1][i][j])	cnt++;
			if (d[2][i][j])	cnt++;
			if (cnt > 1 && c[i][j] == '.')	t -= cnt - 1;
			ans = min(ans, t);
		}
	if (ans == INF)	cout << -1 << endl;
	else	cout << ans << endl;
    return 0;
}