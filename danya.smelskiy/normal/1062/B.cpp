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


int ans;
vector<pair<int,int> > v;

inline vector<pair<int,int> > get(int n) {
    vector<pair<int,int> > res1;
    for (int i=2;i*i<=n;++i)
        if (n%i==0) {
            int c=0;
            while (n%i==0) {
                n/=i;
                ++c;
            }
            res1.push_back(make_pair(i,c));
        }
    if (n>1) res1.push_back(make_pair(n,1));
    return res1;
}

int main(int argc, const char * argv[]) {
 //   freopen("/Users/danya.smelskiy/Documents/Danya/Resources/input.txt","r",stdin);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int n;
    cin>>n;
    bool tt2=false;
    while (true) {
        v=get(n);
        bool t=false;
        bool tt=false;
        for (int j=0;j<v.size();++j) {
            if (v[j].second!=1) t=true;
            if (v[j].second&1) tt=true;
        }
        if (t==false) break;
        if (tt) tt2=true;
        n=1;
        for (int j=0;j<v.size();++j) {
            v[j].second=(v[j].second+1)/2;
            for (int k=0;k<v[j].second;++k)
                n*=v[j].first;
        }
        ++ans;
    }
    if (tt2) ++ans;
    cout<<n<<" "<<ans<<endl;
}