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

vector < pair <int,int> > v;

int main() {
//  freopen("input.txt","r",stdin);
//  freopen("output.txt","w",stdout);
    int n;
    scanf("%d",&n);
    v.resize(n);
    for(int i=0;i<n;++i)
        scanf("%d%d",&v[i].first,&v[i].second);
    sort(v.rbegin(),v.rend());
/*  int sz=v[0].first,cnt=v[0].second;
    for(int i=1;i<v.size();++i) {
        while(sz<v[i].first||cnt>1) {
            ++sz; cnt=(cnt+3)/4;
        }
        cnt=max(0,cnt-v[i].second*4);
        sz=v[i].first; cnt+=v[i].second;
    }
    while(cnt>1)
        cnt=(cnt+3)/4,sz++;*/
    int sz=0;
    for(int i=0;i<v.size();++i) {
        int cur=v[i].first;
        while(v[i].second>1) {
            v[i].second=(v[i].second+3)/4;
            ++cur;
        }
        if (cur==v[i].first) ++cur;
        sz=max(sz,cur);
    }
    printf("%d\n",sz);
    return 0;
}