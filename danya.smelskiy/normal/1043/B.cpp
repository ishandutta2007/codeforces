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

int n;
int a[1005];
int ans=0;
int p[1005];

int main(int argc, const char * argv[]) {
  //  freopen("/Users/danya.smelskiy/Documents/Danya/Resources/input.txt","r",stdin);
    cin>>n;
    for (int i=1;i<=n;++i)
        cin>>a[i];
    for (int i=n;i>0;--i)
        a[i]-=a[i-1];
    int x;
    vector<int> v;
    for (int i=1;i<=n;++i) {
        for (int j=0;j<=i;++j)
            p[j]=-1;
        bool t=false;
        for (int j=1;j<=n;++j) {
            x=(j-1)%i;
            if (p[j]==-1 || p[x]==a[j]) p[x]=a[j];
            else t=true;
        }
        if (t==false) ++ans;
        if (t==false) v.push_back(i);
    }
    cout<<ans;
    cout<<'\n';
    for (int i=0;i<v.size();++i)
        cout<<v[i]<<" ";
}