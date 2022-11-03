#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <memory.h>

using namespace std;

map <int,int> f;

int main() {
//  freopen("input.txt","r",stdin);
//  freopen("output.txt","w",stdout);
    int n,a;
    scanf("%d",&n);
    for(int i=0;i<n;++i) {
        scanf("%d",&a);
        f[a]++;
    }
    int cur=0,pw=0,sub=0;
    f[2147000000]=0;
    for(map <int,int>::iterator it=f.begin();it!=f.end();++it) {
        int nx=it->first,cnt=it->second;
        while(pw<nx&&cur) {
            if (cur&1) sub++;
            cur>>=1; pw++;
        }
        if (nx!=2147000000) pw=nx;
        cur+=cnt;
    }
    printf("%d\n",pw-sub);
    return 0;
}