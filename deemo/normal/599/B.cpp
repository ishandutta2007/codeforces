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

const int max_n = 1e5 + 40;

int n, m;
int f[max_n], b[max_n], a[max_n];
int mp[max_n], cnt[max_n];

int main(){
	read_fast;
	cin >> n >> m;
	for (int i = 0; i < n; i++){
		cin >> f[i];
		mp[f[i]] = i + 1;
		cnt[f[i]]++;
	}

	bool fl = 0;
	for (int i = 0; i < m; i++){
		cin >> b[i];
		if (cnt[b[i]] == 0){
			cout << "Impossible" << endl;
			return 0;
		}
		if (cnt[b[i]] > 1)	fl = 1;
		a[i] = mp[b[i]];
	}
	if (fl){
		cout << "Ambiguity" << endl;
		return 0;
	}
	cout << "Possible" << endl;
	for (int i = 0; i < m; i++)
		cout << a[i] << " ";
	cout << endl;
    return 0;
}