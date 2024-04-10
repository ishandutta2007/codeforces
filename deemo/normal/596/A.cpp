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
	int n;	cin >> n;
	vector<pair<int, int>>	vec(n);
	for (int i = 0; i < n; i++)
		cin >> vec[i].first >> vec[i].second;

	if (n == 1){
		cout << -1 << endl;
		return 0;
	}

	if (n == 2){
		if (vec[0].first == vec[1].first || vec[0].second == vec[1].second){
			cout << -1 << endl;
			return 0;
		}
		cout << abs((vec[0].first - vec[1].first) * (vec[0].second - vec[1].second)) << endl;
		return 0;
	}
	int minx = vec[0].first;
	for (int i = 1; i < n; i++)
		minx = min(minx, vec[i].first);

	int maxx = vec[0].first;
	for (int i = 1; i < n; i++)
		maxx = max(maxx, vec[i].first);

	int miny = vec[0].second;
	for (int i = 1; i < n; i++)
		miny = min(miny, vec[i].second);
	
	int maxy = vec[0].second;
	for (int i = 1; i < n; i++)
		maxy = max(maxy, vec[i].second);
	cout << abs((minx - maxx) * (miny - maxy)) << endl;
    return 0;
}