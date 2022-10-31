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


int m,res;
int a[10005];



int main(int argc, const char * argv[]) {
//    freopen("/Users/danya.smelskiy/Documents/Danya/Resources/input.txt","r",stdin);
    int n,r;
    cin>>n>>r;
    for (int i=1;i<=n;++i)
        cin>>a[i];
    int l1=0;
    int l2=-1e9;
    for (int i=1;i<=n;++i) if (a[i]) {
        if (i-l1<=r) {
            l2=i;
            continue;
        }
        ++res;
        l1=l2+r-1;
        if (i-l1>r) {
            cout<<"-1";
            return 0;
        }
        l2=i;
    }
    if (l1<n) {
        l1=l2+r-1;
        ++res;
        if (l1<n) {
            cout<<"-1";
            return 0;
        }
    }
    cout<<res;
    
}