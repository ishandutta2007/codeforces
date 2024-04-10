#pragma GCC optimize("Ofast,unroll-loops")
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
#define maxn 1005
int mch[maxn], vistime[maxn];
std::vector<int> e[maxn];
bool dfs(const int u, const int tag) {
    if (vistime[u] == tag) return false;
    vistime[u] = tag;
    for (auto v : e[u]) if ((mch[v] == 0) || dfs(mch[v], tag)) {
            mch[v] = u;
            return true;
        }
    return false;
}
int a[1005],b[1005];
int main() {
    int T = 1, kase = 0;
    //cin >> T;
    while (T--) {
        int n,m,x=0,y=0;
        cin>>n>>m;
        for(int i=1,val;i<=n;i++){
            cin>>val;
            if(val*3LL<=m) b[++y]=val;
            else a[++x]=val;
        }
        for(int i=1;i<=x;i++)
            for(int j=1;j<=y;j++)
                if(a[i]%b[j]==0&&2LL*a[i]+b[j]<=m)
                    e[i].push_back(j);
        int fl=1;
        for(int i=1;i<=x;i++) if(!dfs(i,i)) fl=0;
        if(!fl){
            puts("-1");
            continue;
        }
        printf("%d\n",y);
        for(int i=1;i<=y;i++){
            if(mch[i]) printf("%d %d\n",2*a[mch[i]]+b[i],a[mch[i]]+b[i]);
            else printf("%d %d\n",3*b[i],2*b[i]);
        }
    }
    return 0;
}
//unordered_map
//cf