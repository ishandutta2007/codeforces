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

int main(){
	read_fast;
	int n, m;	cin >> n >> m;
	vector<int>	vec(n), sec(m);
	for (int i = 0; i < n; i++)
		cin >> vec[i];
	for (int i = 0; i < m; i++)
		cin >> sec[i];
	sort(vec.begin(), vec.end());
	for (int x:sec)
		cout << upper_bound(vec.begin(), vec.end(), x) - vec.begin() << " ";
	cout << endl;
    return 0;
}