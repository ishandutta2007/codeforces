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
const int md=1e9+7;

int n;
int a[105];
int dp[2][105][10005];
int c[105][105];
int last_s;
int cnt[105];

int main(int argc, const char * argv[]) {
 //   freopen("/Users/danya.smelskiy/Documents/Danya/Resources/input.txt","r",stdin);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n;
    for (int i=1;i<=n;++i)
        cin>>a[i];
    last_s=0;
    int x=0,y=1;
    dp[x][0][0]=1;
    for (int i=1;i<=n;++i) {
        swap(x,y);
        memset(dp[x],0,sizeof(dp[x]));
        for (int j=0;j<=i-1;++j) {
            for (int k=0;k<=last_s;++k) {
                dp[x][j][k]+=dp[y][j][k];
                if (dp[x][j][k]>=md) dp[x][j][k]-=md;
                dp[x][j+1][k+a[i]]+=dp[y][j][k];
                if (dp[x][j+1][k+a[i]]>=md) dp[x][j+1][k+a[i]]-=md;
            }
        }
        last_s+=a[i];
    }
    int ans=0;
    for (int i=1;i<=n;++i)
        ++cnt[a[i]];
    c[0][0]=1;
    for (int i=1;i<=n;++i) {
        for (int j=0;j<=n;++j) {
            c[i][j]=c[i-1][j];
            if (j) c[i][j]+=c[i-1][j-1];
            if (c[i][j]>=md) c[i][j]-=md;
        }
    }
    vector<int> v;
    for (int i=1;i<=100;++i) {
        for (int j=1;j<=cnt[i];++j) {
            if (dp[x][j][i*j]==c[cnt[i]][j]) ans=max(ans,j);
        }
        if (cnt[i]) v.push_back(cnt[i]);
    }
    if (v.size()==2 && (ans==v[0] || ans==v[1])) ans=n;
    cout<<ans<<endl;
}