#include <cstdio>
#include <cstdlib>

#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

typedef long long ll;

const int modulo = 1e9 + 7;
const int max_n = 202;

struct point
{
    ll x, y;
    
    point()
    {
    }
    
    point(ll _x, ll _y):
        x(_x),
        y(_y)
    {
    }
};

point operator-(const point& p1, const point& p2)
{
    return point(p1.x - p2.x, p1.y - p2.y);
}

point p[max_n];
int is_link[max_n][max_n];
int n;
int dp[max_n][max_n], f[max_n][max_n];

inline int mmult(int a, int b)
{
    return (1LL * a * b) % modulo;
}

inline int next_in_loop(int x)
{
    ++x;
    if (x == n) x = 0;
    return x;
}

inline int msum(int a, int b)
{
    int s = a + b;
    if (s >= modulo) s -= modulo;
    if (s < 0) s += modulo;
    return s;
}

ll vmult(const point& a, const point& b)
{
    return a.x * b.y - a.y * b.x;
}

ll smult(const point& a, const point& b)
{
    return a.x * b.x + a.y * b.y;
}

int point_in_segment(const point& p, const point& pl, const point& pr)
{
    return vmult(pr - pl, p - pl) == 0 && smult(p - pl, pr - pl) >= 0 &&
            smult(p - pr, pl - pr) >= 0;
}

int find_dp(int l, int r)
{
    if (f[l][r]) return dp[l][r];
    f[l][r] = 1;
    if (r == l + 1) {
        dp[l][r] = 1;
        return 1;
    }
    dp[l][r] = 0;
    for (int k = l + 1; k < r; ++k)
        if (vmult(p[k] - p[l], p[r] - p[l]) > 0) 
            dp[l][r] = msum(dp[l][r], mmult(find_dp(l, k), find_dp(k, r)));
    return dp[l][r];
}

int main()
{
    ios_base::sync_with_stdio(false);
    
  //  freopen("input.txt", "r", stdin);
  //  freopen("output.txt", "w", stdout);
    
    cin >> n;  
    for (int i = 0; i < n; ++i)
        cin >> p[i].x >> p[i].y;
        
    ll all_sq = 0;
    for (int i = 0; i < n; ++i) {
        int j = i - 1; if (j < 0) j += n;
        all_sq += vmult(p[j], p[i]);
    }
    if (all_sq < 0) {
        all_sq = -all_sq;
        reverse(p, p + n);
    }
            
    cout << find_dp(0, n - 1) << endl;
    
    return 0;
}