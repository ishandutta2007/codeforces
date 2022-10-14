#include <iostream>
#include <iomanip>
#include <random>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <cmath>
#include <numeric>
#include <cstdlib>
#include <cstring>
#include <deque>
#include <sstream>
#include <bitset>
#include <cassert>
#include <fstream>
#include <queue>
 
#define len(X) ((int)(X).size())
 
#ifdef __LOCAL
	#define DBG(X) cout << #X << "=" << (X) << endl;
#else
	#define DBG(X)
#endif
 
using std::cin;
using std::cout;
using std::vector;
using std::string;
using std::pair;
using std::swap;
using std::sort;
using std::lower_bound;
using std::unique;
 
using int64 = long long int;
using pii   = pair<int, int>;
using pii64 = pair<int64, int64>;
 
const int NIL = -1;
 
void init_IO() {
	std::ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
}
 
void solve() {
	int64 sum = 0, cnt;
	cin >> cnt;
 
	for(int i = 0; i < cnt; ++i) {
		int64 val;
		cin >> val;
 
		sum += val;
	}
 
	cout << (sum + cnt - 1) / cnt << '\n';
}
 
int main() {
	init_IO();
 
	int T;
	cin >> T;
 
	while(T--)
		solve();
 
	return 0;
}//dasfadsf dsadf sdf as fds