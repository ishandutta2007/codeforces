#include<iostream>
#include<string>
#include<cmath>
#include<algorithm>
#include<set>
#include<vector>
#include<utility>

using namespace std;

typedef long long ll;

const int MAXQ = 2e5 + 30;
const int INF = 1e9 + 5;

int n, q;
set<pair<int, int>>	stc, str;
set<pair<int, char>>	seen;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> q;

	str.insert({n + 1, 0});
	str.insert({0, n + 1});
	stc.insert({0, 0});
	stc.insert({n + 1, n + 1});
	while (q--){
		int x, y;	char ch;	cin >> x >> y >> ch;
		if (seen.count({y, ch})){
			cout << 0 << "\n";
			continue;
		}
		seen.insert({y, ch});

		if (ch == 'L'){
			pair<int, int>	temp =  *str.upper_bound({y, -INF});
			pair<int, int>	tm = *stc.lower_bound({y, -INF});
			int ret = temp.second + abs(temp.first - y);
			if (tm.second >= abs(y - tm.first))
				ret = min(ret, abs(y - tm.first));
			cout << ret << "\n";
			str.insert({y, ret});
		}			
		else{
			set<pair<int, int>>::iterator it =  stc.lower_bound({y, INF});
			it--;
			pair<int, int>	temp = *it;
			it = str.lower_bound({y, INF});
			it--;
			pair<int, int>	tm = *it;
			int ret = temp.second + abs(y - temp.first);
			if (tm.second >= abs(y - tm.first))
				ret = min(ret, abs(y - tm.first));
			cout << ret << "\n";
			stc.insert({y, ret});
		}
	}
	return 0;	
}