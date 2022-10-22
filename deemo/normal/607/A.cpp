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

const int MAXN = 1e5 + 30;

int n;
pair<int, int>	vec[MAXN];
int dp[MAXN];
set<pair<int, int>>	st;

int main(){
	read_fast;
	cin >> n;
	for (int i = 0; i < n; i++)	cin >> vec[i].first >> vec[i].second;
	sort(vec, vec + n);
	dp[0] = 1;
	for (int i = 1; i < n; i++){
		int pos = lower_bound(vec, vec + n, make_pair(vec[i].first - vec[i].second , -1)) - vec;
		if (pos == 0)	
			dp[i] = 1;
		else
			dp[i] = dp[pos - 1] + 1;
	}
	int ans = 0;
	for (int i = 0; i < n; i++)
		ans = max(ans, dp[i]);
	cout << n - ans << endl;
    return 0;
}