#include <bits/stdc++.h>
#define IO_OP std::ios::sync_with_stdio(0); std::cin.tie(0);
#define F first
#define S second
#define PB push_back
#define MP make_pair
#define EB emplace_back
#define int ll

using namespace std;

typedef long long ll;
typedef pair<int, int> pi;
typedef vector<int> vi;

const int INF = 1e9 + 7;

map<int, priority_queue<int, vi, greater<int>> > m;

int a[150004];

int32_t main()
{
	IO_OP;
	
	priority_queue<int, vi, greater<int>> pq;
	
	int n;
	cin >> n;
	for(int i=0;i<n;i++) {
		cin >> a[i];
		m[a[i]].push(i);
		pq.push(a[i]);
	}
	while(pq.size()) {
		if(m[pq.top()].size() < 2) {
			pq.pop();
			continue;
		}
		a[m[pq.top()].top()] = 0;
		m[pq.top()].pop();
		a[m[pq.top()].top()] = 0;
		int j = m[pq.top()].top();
		m[pq.top()].pop();
		m[pq.top()*2].push(j);
		pq.push(pq.top()*2);
		a[j] = pq.top() * 2;
	}
	int sz = 0;
	for(int i=0;i<n;i++)
		if(a[i]) sz++;
	cout << sz << endl;
	for(int i=0;i<n;i++)
		if(a[i])
			cout << a[i] << " ";
}