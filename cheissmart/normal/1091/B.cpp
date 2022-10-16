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

vector<pi> v, w;

int main()
{
	IO_OP;
	
	int n;
	cin >> n;
	for(int i=0;i<n;i++) {
		int x, y;
		cin >> x >> y;
		v.PB({x, y});	
	}
	for(int i=0;i<n;i++) {
		int x, y;
		cin >> x >> y;
		w.PB({x, y});	
	}
	sort(v.begin(), v.end());
	sort(w.begin(), w.end(), greater<pi>());
	cout << v[0].F+w[0].F << " " << v[0].S+w[0].S << endl;
}