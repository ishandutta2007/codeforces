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

const int max_n = 3e5 + 100;

int n;
int fen[2 * max_n];
int vec[max_n];
map<int, int>	mp;
int a[max_n], save[max_n];

int get(int v){
	int ret = 0;
	for (; v; v -= v & (-v))
		ret += fen[v];
	return	ret;
}

void add(int v, int val){
	for (v++; v < max_n; v += v & (-v))
		fen[v] += val;
}

int main(){
	read_fast;
	cin >> n;
	for (int i = 0; i < n; i++){
		cin >> a[i];
		vec[i] = a[i];
	}
	sort(a, a + n);
	for (int i = 1; i < n; i++){
		if (a[i] == a[i - 1])	continue;
		mp[a[i]] = i;
	}

	for (int i = 0; i < n; i++)
		save[i] = a[i];

	int ans = 0;
	for (int i = 0; i < n; i++){
		int x = mp[vec[i]]++;
		add(x, 1);
		if (get(i + 1) == i + 1)	ans++;
	}
	cout << ans << endl;
    return 0;
}