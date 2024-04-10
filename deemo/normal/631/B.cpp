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

const int MAXN = 5e3 + 10;

int n, m, q;
int c[MAXN][MAXN];
pair<int, int>	d[MAXN], e[MAXN];

int main(){
	read_fast;
	cin >> n >> m >> q;
	for (int i = 0; i < q; i++){
		int type;	cin >> type;
		if (type == 1){
			int r;	cin >> r;	int col;	cin >> col;	r--;
			d[r] = {i + 1, col};
		}
		else{
			int r;	cin >> r;	int col;	cin >> col;	r--;
			e[r] = {i + 1, col};
		}
	}
	for (int i = 0; i < n; i++){
		for (int j = 0; j < m; j++){
			if (d[i].first == e[j].first)
				cout << 0 << " ";
			else if (d[i].first > e[j].first)
				cout << d[i].second << " ";
			else 
				cout << e[j].second << " ";
		}
		cout << "\n";
	}
    return 0;
}