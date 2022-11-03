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
#include <queue>
#include <memory.h>

using namespace std;

int x[100005],y[100005];

multiset <int> f;

pair <int,int> v[100005];
pair <int,int> up[100005],down[100005];

void update(pair <int,int> & ret,pair <int,int> val) {
    ret.first=min(ret.first,val.first);
    ret.second=max(ret.second,val.second);
}

int main() {
//  freopen("input.txt","r",stdin);
//  freopen("output.txt","w",stdout);
    int n,a,b;
    scanf("%d",&n);
    for(int i=0;i<n;++i) {
        scanf("%d%d",&a,&b);
        x[i]=a-b; y[i]=a+b;
        v[i]=make_pair(y[i],i);
    }
    sort(v,v+n);
    for(int i=0;i<n;++i) {
        up[i]=down[i]=make_pair(x[v[i].second],x[v[i].second]);
        if (i) update(up[i],up[i-1]);
    }
    for(int i=n-2;i>=0;--i)
        update(down[i],down[i+1]);
    double l=0,r=2e+9;
    while((r-l)>r*2e-6) {
        double m=(l+r)/2;
        int add=0,rem=0;
        bool ok=false;
        for(int i=0;i<n;++i) {
            int npos=v[i].first;
            while(rem<n&&v[rem].first<=npos) {
                ++rem;
            }
            while(add<n&&v[add].first+1e-9<npos-2*m) {
                ++add;
            }
            pair <int,int> cur=make_pair(2000000004,-2000000004);
            if (add>0) update(cur,up[add-1]);
            if (rem<n) update(cur,down[rem]);
            double diff=0;
            if (cur.first<=cur.second) {
                diff=cur.second;
                diff-=cur.first;
                diff/=2;
            }
            if (diff+1e-9<m) {
                ok=true;
                break;
            }
        }
        if (ok) r=m;
        else l=m;
    }
    printf("%.7lf\n",(l+r)/2);
    return 0;
}