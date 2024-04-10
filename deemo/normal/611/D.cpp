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
//#define size(x) ((ll)(x).size())
#define error(x) cerr << #x << " = " << x << endl
#define pb push_back
#define setprecision(x) cout << fixed << setprecision((x))
#define read_fast ios_base::sync_with_stdio(false) , cin.tie(0)
#define PQ priority_queue;
#define to_string(x) ({ string _str; stringstream _ss; _ss << x;  _ss >> _str; _str; })
#define to_ll(x) ({ ll _x; stringstream _ss; _ss << x; _ss >> _x; _x; })

const ll MOD = 1e9 + 7;
const ll MAXN = 5e3 + 20;

ll n;
string s;
ll d[MAXN][MAXN], c[MAXN][MAXN];
int lc[MAXN][MAXN];

void init(){
	for (ll i = (ll)s.size() - 1; i >= 0; i--)
		for (ll j = (ll)s.size() - 1; j >= 0; j--)
			if (s[i] != s[j])
				lc[i][j] = 0;
			else
				lc[i][j] = lc[i + 1][j + 1] + 1;
}

int main(){
	read_fast;
	cin >> n >> s;
	s.push_back('9' + 5);
	init();

	d[0][0] = c[0][0] = 1;
	for (ll j = 1; j <= n + 2; j++)
		for (ll i = 0; i <= n; i++){
			if (i < n && s[i] == '0'){
				c[i][j] = 0;
				d[i][j] = d[i + 1][j - 1];
				continue;
			}
			
			if (i == 0){
				c[i][j] = 1;
				d[i][j] = c[i][j] + d[i + 1][j - 1];
				continue;
			}	

			int g = min(j - 1, i);
			c[i][j] = d[i - g][g];
			if (j <= i){
				ll z = lc[i - j][i];
				if (z < j && (i + z < n || i == n) && s[i - j + z] < s[i + z])
					c[i][j] = (c[i][j] + c[i - j][j]) % MOD;
			}
			d[i][j] = (d[i + 1][j - 1] + c[i][j]) % MOD;
		}
	cout << c[n][n] << endl;
	return 0;
}