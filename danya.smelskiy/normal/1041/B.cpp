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


inline long long gcd(long long x,long long y) {
    while (x>0 && y>0) {
        if (x>y) x%=y;
        else y%=x;
    }
    return x+y;
}


int main(int argc, const char * argv[]) {
 //   freopen("/Users/danya.smelskiy/Documents/Danya/Resources/input.txt","r",stdin);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    long long a,b,x,y;
    cin>>a>>b>>x>>y;
    long long z=gcd(x,y);
    x/=z;
    y/=z;
    long long res=min(a/x,b/y);
    cout<<res;
    
}