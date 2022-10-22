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

bool cmp(pair<int, int>	a, pair<int, int>	b){
	return	a.second < b.second;
}

int main(){
	read_fast;
	int n;	cin >> n;
	vector<pair<int, int>>	vec(n);
	for (int i = 0; i < n; i++)
		cin >> vec[i].first >> vec[i].second;
	sort(vec.begin(), vec.end(), cmp);

	int ans = 1, b = 1;
	pair<int, int>	cur = vec[0];
	while (b < n){
		while (b < n && vec[b].first <= cur.second)	b++;
		if (b < n){
			ans++;
			cur = vec[b];
		}
		b++;
	}
	cout << ans << endl;
    return 0;
}