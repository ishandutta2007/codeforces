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
const long long md=998244353;

vector<int> v[300005];
long long dp1[300005];
long long dp2[300005];
long long dp3[300005];
int n;

inline long long pw(long long x,long long y) {
    long long res=1;
    while (y) {
        if (y&1) res=(res*x)%md;
        x=(x*x)%md;
        y>>=1;
    }
    return res;
}

void dfs(int x,int y) {
    dp1[x]=1;
    dp3[x]=1;
    for (int i=0;i<v[x].size();++i) {
        int to=v[x][i];
        if (to==y) continue;
        dfs(to,x);
        dp1[x]*=(dp1[to]+dp2[to])%md;
        dp1[x]%=md;
    }
    long long cur;
    for (int i=0;i<v[x].size();++i) {
        int to=v[x][i];
        if (to==y) continue;
        cur=dp1[to]+dp2[to];
        if (cur>=md) cur-=md;
        cur+=dp2[to];
        if (cur>=md) cur-=md;
        dp3[x]=(dp3[x]*cur)%md;
    }
    long long cur2;
    for (int i=0;i<v[x].size();++i) {
        int to=v[x][i];
        if (to==y) continue;
        cur=dp1[to]+dp2[to];
        if (cur>=md) cur-=md;
        cur+=dp2[to];
        if (cur>=md) cur-=md;
        cur2=(dp3[x]*pw(cur,md-2))%md;
        cur2=(cur2*dp3[to])%md;
        dp2[x]+=cur2;
        if (dp2[x]>=md) dp2[x]-=md;
    }
}

int main(int argc, const char * argv[]) {
//    freopen("/Users/danya.smelskiy/Documents/Danya/Resources/input.txt","r",stdin);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n;
    int x,y;
    for (int i=1;i<n;++i) {
        cin>>x>>y;
        v[x].push_back(y);
        v[y].push_back(x);
    }
    dfs(1,0);
    long long res=dp1[1]+dp2[1];
    res%=md;
    cout<<res<<endl;
}