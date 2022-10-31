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
pair<long long,long long> a[300005],b[300005];
long long p1[300005];
long long p2[300005];
long long ans[300005];
long long x,y;
vector<int> v[3000005];

inline int get_pos1(int x) {
    int l=1;
    int r=n;
    while (l<r-1) {
        int mid=(l+r)>>1;
        if (b[mid].first>=x) r=mid;
        else l=mid;
    }
    if (b[l].first>=x) r=l;
    return r;
}

inline long long solve(int x,int y) {
    long long res1=0,res2=0;
    res1=a[x].first+a[y].second;
    res2=a[x].second+a[y].first;
    return min(res1,res2);
}

int main(int argc, const char * argv[]) {
 //   freopen("/Users/danya.smelskiy/Documents/Danya/Resources/input.txt","r",stdin);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n>>m;
    for (int i=1;i<=n;++i) {
        cin>>a[i].first>>a[i].second;
        b[i].first=a[i].first-a[i].second;
        b[i].second=i;
    }
    for (int i=1;i<=m;++i) {
        cin>>x>>y;
        v[x].push_back(y);
        v[y].push_back(x);
    }
    sort(b+1,b+n+1);
    for (int i=1;i<=n;++i)
        p1[i]=p1[i-1]+a[b[i].second].second;
    for (int i=1;i<=n;++i)
        p2[i]=p2[i-1]+a[b[i].second].first;
    for (int i=1;i<=n;++i) {
        x=a[i].first-a[i].second;
        y=get_pos1(x);
        ans[i]+=(n-y)*1ll*a[i].first;
        ans[i]+=(y-1ll)*1ll*a[i].second;
        ans[i]+=p1[n]-p1[y-1];
        ans[i]-=a[i].second;
        ans[i]+=p2[y-1];
        for (int j=0;j<v[i].size();++j)
            ans[i]-=solve(i,v[i][j]);
        cout<<ans[i]<<" ";
    }
    
    
}