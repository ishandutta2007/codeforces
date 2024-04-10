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

int a[100005], b[100005];

signed main()
{
	IO_OP;
	
	int t;
	cin >> t;
	while(t--) {
		int n;
		cin >> n;
		for(int i=0;i<n;i++)
			cin >> a[i];
		for(int i=0;i<n;i++)
			cin >> b[i];
		deque<int> dk;
		for(int i=0;i<n;i++)
			dk.PB(b[i]-a[i]);
		while(dk.size() && dk.front() == 0) dk.pop_front();
		while(dk.size() && dk.back() == 0) dk.pop_back();
		if(dk.empty()) {
			cout << "YES" << endl;
			continue;
		}
		if(dk[0] < 0){
			cout << "NO" << endl;
			continue;
		}

		bool ok = true;
		for(int i=0;i<dk.size();i++)
			if(dk[i] != dk[0]) {
				ok = false;
				break;
			}
		if(ok) cout << "YES" << endl;
		else cout << "NO" << endl;
	}	
	
}