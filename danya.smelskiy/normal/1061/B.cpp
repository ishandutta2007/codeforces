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

long long ans,a[100005];

int main(int argc, const char * argv[]) {
  //  freopen("/Users/danya.smelskiy/Documents/Danya/Resources/input.txt","r",stdin);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int n,m;
    cin>>n>>m;
    for (int i=1;i<=n;++i) {
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    long long last=n;
    long long ans=n;
    for (int i=1;i<=n;++i) {
        if (a[i]!=a[i-1]) {
            long long l=a[i]-a[i-1];
            if (l<=last) {
                last-=l;
                continue;
            }
            ans+=l-last;
            last=0;
        }
        if (n-last<i) --last;
    }
    for (int i=1;i<=n;++i)
        ans-=a[i];
    cout<<abs(ans)<<'\n';
}