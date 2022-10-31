# include <iostream>
# include <cmath>
# include <algorithm>
# include <stdio.h>
# include <cstdint>
# include <cstring>
# include <string>
# include <cstdlib>
# include <vector>
# include <bitset>
# include <map>
# include <queue>
# include <ctime>
# include <stack>
# include <set>
# include <list>
# include <random>
# include <deque>
# include <functional>
# include <iomanip>
# include <sstream>
# include <fstream>
# include <complex>
# include <numeric>
# include <immintrin.h>
# include <cassert>
# include <array>
# include <tuple>
# include <unordered_set>
# include <unordered_map>
using namespace std;


int n,m;
pair<bool,int> dp[1005];
pair<int,int> pred[1005];

inline void upd(int x,int y,int z,int zz) {
    x=min(x,n);
    if (!dp[x].first || dp[x].second>y) {
        dp[x]=make_pair(true,y);
        pred[x]=make_pair(z,zz);
    }
}

int main(int argc, const char * argv[]) {
  //  freopen("/Users/danya.smelskiy/Documents/Danya/Resources/input.txt","r",stdin);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n>>m;
    if (m>=n) {
        cout<<1<<'\n'<<1;
        return 0;
    }
    dp[0]=make_pair(true,0);
    for (int i=m+1;i<=m+m+1;++i) {
        dp[i]=make_pair(true,1);
        pred[i]=make_pair(0,i-m);
    }
    for (int i=0;i<=n;++i) if (dp[i].first) {
        if (n-i>=m+1) upd(i+m+m+1,dp[i].second+1,i,i+m+1);
    }
    cout<<dp[n].second<<'\n';
    while (n) {
        cout<<pred[n].second<<" ";
        n=pred[n].first;
    }
}