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



long long ans=0;
int n,m;
int a[11][100005];
int pos[11][100005];
int x,y;
int dp[100005];
bool t=false;

int main(int argc, const char * argv[]) {
   // freopen("/Users/danya.smelskiy/Documents/Danya/Resources/input.txt","r",stdin);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n>>m;
    for (int i=1;i<=m;++i) {
        for (int j=1;j<=n;++j) {
            cin>>a[i][j];
            pos[i][a[i][j]]=j;
        }
    }
    for (int i=n;i>0;--i) {
        dp[i]=1;
        if (i==n) { ++ans; continue; }
        x=a[1][i];
        y=a[1][i+1];
        t=false;
        for (int j=1;j<=m;++j)
            if (pos[j][x]==n || a[j][pos[j][x]+1]!=y) t=true;
        if (t==false) dp[i]=dp[i+1]+1;
        ans+=dp[i];
    }
    cout<<ans;
}