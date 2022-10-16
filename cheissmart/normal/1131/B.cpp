#include <bits/stdc++.h>
#define IO_OP std::ios::sync_with_stdio(0); std::cin.tie(0);
#define F first
#define S second
#define PB push_back
#define MP make_pair

using namespace std;

typedef long long ll;
typedef pair<int, int> pi;
typedef vector<int> vi;

const int INF = 1e9 + 7;

int main()
{
	IO_OP;
	
	int n, ans = 0, pa = 0, pb = -INF;
	cin >> n;
	for(int i=0;i<n;i++) {
		int a, b;
		cin >> a >> b;
		if(a == pa && b == pb) continue;
		ans += max(0, min(a, b) - max(pa, pb)+1);
		ans -= (pa == pb);
		pa = a, pb = b;
	}
	cout << ans << endl; 
	
}