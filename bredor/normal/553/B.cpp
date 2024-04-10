#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <map>
#include <queue>
#include <set>
#include <algorithm>
#include <math.h>
#include <sstream>
#include <bitset>
#define int228 long long
#define mp make_pair
#define pb push_back
using namespace std;

int228 VERY_DOHERA = 1000000007;

int main(){
    int n;
    cin >> n;
    int228 k;
    cin >> k;
    vector<pair<int228, int228> > dp;
    dp.pb(mp(1, 0));
    for (int i = 1; i <= 80; ++i)
        dp.pb(mp(dp[i - 1].first + dp[i-1].second, dp[i - 1].first));
    --k;
    vector<int> ans;
    int curr = n - 1;
    for (int i = 0; i < n;){
            if (k < dp[curr].first)        {
                ans.pb(i);
            i++;
            curr--;
        }
        else{
            ans.pb(i+1);
            ans.pb(i);
            k -= dp[curr].first;
            i+=2;
            curr-=2;

        }
    }
    for (int i = 0; i < n; ++i)
        cout << ans[i] + 1 << " ";;;;
    return 228 / 1488;   
}