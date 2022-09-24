#include<iostream>
#include<math.h>
#include<set>
#include<algorithm>
#include<vector>
#include<map>
#include<iomanip>
#include<deque>
using namespace std;
long long inf = 1LL << 62;
static long parseans(long j, long l)
{
    string k = "";
    long ps = 0;
    for (long long i = (long long) j; i <= l; ++i)
    {
        ps *= 10;
        ps += k[i] - '0';
    }
    return ps;
}

int cur = 1;
int cnt = 0;
static long gcd(long a, long b)
{
    if (b == 0)
    {
        return a;
    } else
    {
        return gcd(b, a % b);
    }
}

static bool pri(long long k)
{
    if (k == 1LL) return false;
    for (long long i = 2; i * i <= k; i++)
    {
        
        if (k % i == 0) return false;
    }
    return true;
}
int n , k;

using namespace std;


int main(){
    int n, m;
    cin >> n >> m;
    vector<vector<int > > g(n, vector<int>(m));
    vector<vector<int > > up(n, vector<int>(m));
    vector<vector<int > > down(n, vector<int>(m));
    vector<vector<int > > left(n, vector<int>(m));
    vector<vector<int > > right(n, vector<int>(m));
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cin >> g[i][j];
            if(i == 0){
                down[i][j] = g[i][j];
            } else {
                down[i][j] = down[i - 1][j] + g[i][j];
            }
        }
    }
    for(int i = n - 1; i >= 0; i--) {
        for(int j = 0; j < m; j++) {
            if(i == n - 1) {
                up[i][j] = g[i][j];
            } else {
                up[i][j] = g[i][j] + up[i + 1][j];
            }
        }
    }
    
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(j == 0) {
                left[i][j] = g[i][j];
            } else {
                left[i][j] = left[i][j - 1] + g[i][j];
            }
        }
    }
    for(int i = 0; i < n; i++) {
        for(int j = m - 1; j >= 0; j--) {
            if(j == m - 1) {
                right[i][j] = g[i][j];
            } else {
                right[i][j] = right[i][j + 1] + g[i][j];
            }
        }
    }
    long long ans = 0;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(g[i][j]) {
                continue;
            }
            if(down[i][j]) {
                ans ++;
            }
            if(up[i][j]) {
                ans++;
            }
            if(left[i][j]) {
                ans++;
            }
            if(right[i][j]){
                ans++;
            }
        }
    }
    cout << ans;
    return 0;
}