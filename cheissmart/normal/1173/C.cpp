#include <bits/stdc++.h>
#define IO_OP std::ios::sync_with_stdio(0); std::cin.tie(0);
#define F first
#define S second
#define PB push_back
#define MP make_pair
#define EB emplace_back

using namespace std;

typedef long long ll;
typedef pair<int, int> pi;
typedef vector<int> vi;

const int INF = 1e9 + 7, N = 200005;

int a[N], b[N], m[N];
int n;

int ok(deque<int> dk) {
	int ans = 0;
	for(int i=b[n-1]+1;i<=n;i++) {
		if(m[i] == 0) return -1;
		m[i]--;
		dk.push_back(i);
		m[dk.front()]++;
		dk.pop_front();
		ans++;
	}
	for(int i=1;i<=n;i++){
		if(dk[i-1] != i)
			return -1;
	}
	return ans;
}

int main()
{
	IO_OP;
	
	deque<int> dk;
	cin >> n;
	for(int i=0;i<n;i++) {
		cin >> a[i];
		m[a[i]]++;
	}
	for(int i=0;i<n;i++) {
		cin >> b[i];
		dk.push_back(b[i]);
	}
	int cans = ok(dk);
	if(cans != -1) {
		cout << cans << endl;
		return 0;
	}
	memset(m, 0, sizeof m);
	for(int i=0;i<n;i++)
		m[a[i]]++;
	int mx = 0;
	for(int i=0;i<n;i++) {
		if(dk[i])
			mx = max(mx, i+1-dk[i]+1);
	}
	cout << mx + n << endl;
	
	
}