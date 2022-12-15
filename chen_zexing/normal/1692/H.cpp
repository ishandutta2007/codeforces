#include <cstdio>
#include <iostream>
#include <unordered_map>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <climits>
#include <algorithm>
#include <complex>
#include <string.h>
#include <iomanip>
#include <assert.h>
#include <random>
using namespace std;
int a[200005],b[200005];
vector <int> v[200005];
int main() {
    int T = 1, kase = 0;
    cin >> T;
    while (T--) {
        int n,l=0,r=0,tar=0,mx=0;
        scanf("%d",&n);
        for(int i=1;i<=n;i++) scanf("%d",&a[i]),b[i]=a[i],v[i].clear();
        sort(b+1,b+n+1);
        for(int i=1;i<=n;i++) a[i]=lower_bound(b+1,b+n+1,a[i])-b,v[a[i]].push_back(i);
        for(int i=1;i<=n;i++){
            if(!v[i].size()) continue;
            int now=0,pre=-1,nl=-1;
            for(auto t:v[i]){
                if(pre!=-1) now-=t-pre-1;
                else nl=t;
                pre=t;
                if(now<0) now=0,nl=t;
                now++;
                if(now>mx) l=nl,r=t,tar=b[i],mx=now;
            }
        }
        printf("%d %d %d\n",tar,l,r);
    }
    return 0;
}
//cf