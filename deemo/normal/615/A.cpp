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

const int MAXN = 200;

int n, m, vec[MAXN];

int main(){
	read_fast;
	cin >> n >> m;
	while (n--){
		int t;	cin >> t;
		while (t--){
			int x;	cin >> x;
			vec[x] = 1;
		}
	}
	bool fl = 1;
	for (int i = 1; i <= m; i++)
		if (vec[i] == 0)	fl = 0;
	if (fl)
		cout << "YES\n";
	else
		cout << "NO\n";
    return 0;
}