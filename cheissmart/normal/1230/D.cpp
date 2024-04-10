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

int a[7003], b[7003];

signed main()
{
	IO_OP;
	
	int n;
	cin >> n;
    set<int> s1, s2;
    for (int i=0; i<n; i++) cin >> a[i];
    for (int i=0; i<n; i++) cin >> b[i];
    for (int i=0; i<n; i++) {
        if (s1.count(a[i])) s2.insert(a[i]);
        else s1.insert(a[i]);
    }
    vi v;
    for (auto s: s2)  v.PB(s);
    int ans = 0;
    for (int i=0;i<n;i++) {
        for (auto x : v) {
            if ((a[i] | x) == x) {
                ans += b[i];
                break;
            }
        }
    }
    cout << ans << endl;
	
}