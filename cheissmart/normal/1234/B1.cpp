#include <bits/stdc++.h>
#define IO_OP std::ios::sync_with_stdio(0); std::cin.tie(0);
#define F first
#define S second
#define V vector
#define PB push_back
#define MP make_pair
#define EB emplace_back
#define ALL(v) (v).begin(), (v).end()
#define debug(x) cerr << #x << " is " << x << endl

using namespace std;

typedef long long ll;
typedef pair<int, int> pi;
typedef V<int> vi;

const int INF = 1e9 + 7;

map<int, bool> in;

int32_t main()
{
	IO_OP;
	
	int n, k;
	cin >> n >> k;
	deque<int> dk;
	for(int i=0;i<n;i++) {
		int t;
		cin >> t;
		if(in[t]) continue;
		if(dk.size() == k) {
			in[dk.back()] = false;
			dk.pop_back();
		}
		dk.push_front(t);
		in[t] = true;
	}
	cout << dk.size() << endl;
	for(int e:dk)
		cout << e << " ";

}