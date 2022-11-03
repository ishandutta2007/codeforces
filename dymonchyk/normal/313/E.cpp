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

int arr[100005];
map <int,int> f;
map <int,int>::iterator it;
int ans[100005],mod;

int get_max(int val) {
    if (f.size()==0) return 0;
    it=f.end(); --it;
    int ret=it->first+val;
    if (ret>=mod) ret-=mod;
    it=f.upper_bound(mod-val-1);
    if (it!=f.begin()) {
        --it;
        int nval=val+it->first;
        if (nval>=mod) nval-=mod;
        ret=max(ret,nval);
    }
    return ret;
}

priority_queue < pair <int,int> > q;

int main() {
//  freopen("input.txt","r",stdin);
//  freopen("output.txt","w",stdout);
    int n,a;
    scanf("%d%d",&n,&mod);
    for(int i=0;i<n;++i) {
        scanf("%d",&a);
        arr[a]++;
    }
    for(int i=0;i<n;++i) {
        scanf("%d",&a);
        f[a]++;
    }
    for(int i=mod-1;i>=0;--i) {
        int best=get_max(i);
        for(int j=0;j<arr[i];++j)
            q.push(make_pair(best,i));
    }
    int left=n;
    while(left) {
        pair <int,int> top=q.top(); q.pop();
        int need=top.first-top.second;
        if (need<0) need+=mod;
        if (!f.count(need)) {
            int best=get_max(top.second);
            q.push(make_pair(best,top.second));
            continue;
        }
        ans[top.first]++;
        f[need]--;
        if (f[need]==0) f.erase(f.find(need));
        --left;
    }
    for(int i=mod-1;i>=0;--i) {
        while(ans[i]) {
            ans[i]--;
            printf("%d ",i);
        }
    }
    printf("\n");
    return 0;
}