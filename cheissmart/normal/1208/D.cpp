#include <bits/stdc++.h>
#define IO_OP std::ios::sync_with_stdio(0); std::cin.tie(0);
#define F first
#define S second
#define PB push_back
#define MP make_pair
#define EB emplace_back
#define ALL(v) (v).begin(), (v).end()
#define endl '\n'
#define debug(x) cerr << #x << " is " << x << endl
#define int ll
 
using namespace std;
 
typedef long long ll;
typedef pair<int, int> pi;
typedef vector<int> vi;
 
const int INF = 1e9 + 7, N = 2e5+ 5;
 
int a[N], p[N];
int c[N], bit[N], n; // [1, n]
 
int lowbit(int x) {
    return x & -x;
}
int ubound(int x)
{
// s0 = p(1011000)
// s1 = p(1011010) = s0 + bit[1011010]
    
    //s[r] <= x
    int r = 0, s = 0;
    for (int k = 1<<__lg(n); k; k >>= 1)
        if (r + k <= n && s + bit[r + k] <= x)
            s += bit[r += k];
    return r + 1;
}
 
void add(int i, int d) {
    while(i <= n) {
        bit[i] += d;
        i += lowbit(i);
    }
}
 
int qry(int i) {
    int res = 0;
    while(i) {
        res += bit[i];
        i -= lowbit(i);
    }
    return res;
}
 
int32_t main()
{
    IO_OP;
    cin >> n;
    for(int i=1;i<=n;i++)
        cin >> a[i];
    set<int> s;
    for(int i=1;i<=n;i++) {
        add(i, i);
        s.insert(i);
    }
    for(int i=n;i>=1;i--) {
        /* O(log^2 N), bad
        int l = 1, r = n;
        while(l <= r) {
            int m = (l + r) / 2;
            if(qry(m) <= a[i])
                l = m + 1;
            else
                r = m - 1;
        }
        */
        // O(log N), good
        int l = ubound(a[i]);
        int f = *s.lower_bound(l);
        s.erase(f);
        add(f, -f);
        p[i] = f;
    }
    for(int i=1;i<=n;i++)
        cout << p[i] << " ";
}