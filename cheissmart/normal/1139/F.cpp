#include <bits/stdc++.h>
#include <bits/extc++.h>
#define IO_OP std::ios::sync_with_stdio(0); std::cin.tie(0);
#define F first
#define S second
#define V vector
#define PB push_back
#define MP make_pair
#define EB emplace_back
#define ALL(v) (v).begin(), (v).end()
#define debug(x) cerr << "Line(" << __LINE__ << ") -> " << #x << " is " << x << endl
using namespace std;
using namespace __gnu_pbds;

typedef long long ll;
typedef pair<int, int> pi;
typedef V<int> vi;

const int INF = 1e9 + 7, N = 1e5 + 7;

/*

Solution: 
    |b_i - pref_j| <= inc_j - p_i
<=> -(inc_j - p_i) <= (b_i - pref_j) <= inc_j - p_i
    answer = #(b_i - pref_j <= inc_j - p_i) - #(-(inc_j - p_i) > b_i - pref_j)

    #(b_i - pref_j <= inc_j - p_i) = #(b_i + p_i <= pref_j + inc_j)
    #(-(inc_j - p_i) > b_i - pref_j) = #(p_i - b_i > inc_j - pref_j)
=>  answer = #(b_i + p_i <= pref_j + inc_j) - #(p_i - b_i > inc_j - pref_j)

*/

typedef tree<pi,null_type,less<pi>,rb_tree_tag,tree_order_statistics_node_update> ordered_set;

array<int, 3> dish[N];
array<int, 2> person[N];
V<array<int, 3>> events;
int ans[N];

ordered_set s1, s2;

signed main()
{
	IO_OP;

	int n, m;
	cin >> n >> m;
	for(int i = 0; i < n; i++) cin >> dish[i][0]; // p
	for(int i = 0; i < n; i++) cin >> dish[i][1]; // s
	for(int i = 0; i < n; i++) cin >> dish[i][2]; // b
	for(int i = 0; i < m; i++) cin >> person[i][0]; // inc
	for(int i = 0; i < m; i++) cin >> person[i][1]; // pref
	for(int i = 0; i < n; i++) {
		events.PB({dish[i][0], -1, i});
		events.PB({dish[i][1], 1, i});
	}
	for(int i = 0; i < m; i++) events.PB({person[i][0], 0, i});
	sort(ALL(events));
	for(auto event:events) {
		int i = event[2];
		if(event[1] == -1) { // add
			s1.insert({dish[i][0] + dish[i][2], i});
			s2.insert({dish[i][0] - dish[i][2], i});			
		} else if(event[1] == 1) { // delete
			s1.erase({dish[i][0] + dish[i][2], i});
			s2.erase({dish[i][0] - dish[i][2], i});			
		} else { // qry
			ans[i] += s1.order_of_key({person[i][0] + person[i][1], INF});
			ans[i] -= s2.size() - s2.order_of_key({person[i][0] - person[i][1], INF});
		}
	}
	for(int i = 0; i < m; i++) cout << ans[i] << " ";
	cout << endl;
}