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
#define int ll

using namespace std;

typedef long long ll;
typedef pair<int, int> pi;
typedef V<int> vi;

const int INF = 1e9 + 7;

signed main()
{
	IO_OP;
	
    int t;
    cin >> t;
    while(t--) {
        int x, y;
        cin >> x >> y;
        y /= __gcd(x, y);
        int ans = y;
        for(int i=2;i*i<=y;i++) {
            if(y % i) continue;
            while(y % i == 0) y /= i;
            ans = ans / i * (i - 1);
        }
        if(y != 1) ans = ans / y * (y - 1);
        cout << ans << endl;
    }
    	
}