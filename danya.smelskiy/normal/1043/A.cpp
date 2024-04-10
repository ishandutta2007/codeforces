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



int n,s;
int a[1005];
int main(int argc, const char * argv[]) {
 //   freopen("/Users/danya.smelskiy/Documents/Danya/Resources/input.txt","r",stdin);
    cin>>n;
    for (int i=1;i<=n;++i)
        cin>>a[i];
    for (int i=0;i<=1e5;++i) {
        s=0;
        bool t=false;
        int s1=0,s2=0;
        for (int j=1;j<=n;++j) {
            if (i-a[j]<0) t=true;
            s1+=a[j];
            s2+=i-a[j];
        }
        if (s2>s1 && t==false) {
            cout<<i;
            return 0;
        }
    }
}