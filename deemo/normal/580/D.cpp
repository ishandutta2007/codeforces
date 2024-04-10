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

int cnt(int x){
	int ret = 0;
	while (x){
		if (x & 1)	ret++;
		x >>= 1;
	}
	return	ret;
}

const int max_n = 20;
const int MASK = 1<<20;

ll d[MASK][max_n];
int n, m, k;
vector<ll>	vec;
ll mat[max_n][max_n];
vector<int>	sec[max_n];

int main(){
	read_fast;
	cin >> n >> m >> k;
	vec.resize(n);
	for (int i = 0; i < n; i++)
		cin >> vec[i];
	for (int i = 0; i < k; i++){
		int a, b, c;	cin >> a >> b >> c;	a--, b--;
		mat[a][b] = c;
	}
	ll ans = 0;
	for (int i = 0; i < n; i++){
		d[1<<i][i] = vec[i];
		ans = max(ans, vec[i]);
	}

	for (int i = 1; i < (1 << n); i++){
		int c = cnt(i);
		if (c == 1)	continue;
		sec[c].pb(i);
	}	

	for (int w = 2; w <= m; w++){
		for (auto x:sec[w])
			for (int i = 0; i < n; i++){
				if (((x >> i) & 1) == 0)	continue;
				for (int j = 0; j < n; j++){
					if (((x >> j) & 1) == 0)	continue;
					d[x][i] = max(d[x][i], d[x ^ (1 << i)][j] + mat[j][i] + vec[i]);
					ans = max(ans, d[x][i]);
				}
			}
	}
	cout << ans << endl;
    return 0;
}