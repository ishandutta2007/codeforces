#include <bits/stdc++.h>
#define IO_OP std::ios::sync_with_stdio(0); std::cin.tie(0);
#define F first
#define S second
#define PB push_back
#define MP make_pair
#define INF int(1e9+7)

using namespace std;

typedef long long ll;
typedef pair<int, int> pi;
typedef vector<int> vi;

int main()
{
	IO_OP;
	
	int n, k;
	cin >> n >> k;
	if(n < k) {
		cout << "NO" << endl;
		return 0;
	}
	priority_queue<int> pq;
	for(int i=0;(1LL<<i) <= n;i++) {
		if(n & (1<<i)) {
			pq.push(1<<i);
		}
	}
	if(pq.size() > k) {
		cout << "NO" << endl;
		return 0;
	}
	while(pq.size() < k) {
		int a = pq.top();
		pq.pop();
		pq.push(a/2);
		pq.push(a/2);
	}
	cout << "YES" << endl;
	while(pq.size()) {
		cout << pq.top() << " ";
		pq.pop();
	}
}