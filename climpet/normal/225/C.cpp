#include <cstdlib>
#include <cmath>
#include <climits>
#include <cfloat>
#include <map>
#include <utility>
#include <set>
#include <iostream>
#include <memory>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>
#include <sstream>
#include <deque>
#include <complex>
#include <stack>
#include <queue>
#include <cstdio>
#include <cctype>
#include <cstring>
#include <ctime>
#include <iterator>
#include <bitset>
using namespace std;


typedef long long LL;
typedef pair<int,int> pii;
typedef pair<LL,LL> pll;


int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, m, x, y;
    cin >> n >> m >> x >> y;
    
    vector<string> vs(n);
    for(int i = 0; i < n; ++i)
        cin >> vs[i];
    
    vector<int> cnt(m);
    for(int i = 0; i < m; ++i){
        for(int j = 0; j < n; ++j){
            if( vs[j][i] == '.' ) ++cnt[i];
        }
    }

    vector<int> sum(m + 1), sum2(m + 1);
    for(int i = 0; i < m; ++i){
        sum[i + 1] = sum[i] + cnt[i];
        sum2[i + 1] = sum2[i] + (n - cnt[i]);
    }

    vector<vector<int> > dp(2, vector<int>(m + 1, 100000000) );
    dp[0][0] = dp[1][0] = 0;
    
    for(int i = 0; i < m; ++i){
        for(int j = i + x; j <= i + y && j <= m; ++j){
            dp[0][j] = min(dp[0][j], dp[1][i] + sum[j] - sum[i]);
            dp[1][j] = min(dp[1][j], dp[0][i] + sum2[j] - sum2[i]);
        }
    }
    
    cout << min(dp[0][m], dp[1][m]) << '\n';
}