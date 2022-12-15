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
int a[200005],l[200005],r[200005];
vector <int> v[200005];
map <int,set<int>> mp;
map <int,int> pp;
int f[200005],nxt[200005],mn[200005],mx[200005],near[200005];
int main() {
    int T = 1, kase = 0;
    cin >> T;
    while (T--) {
        int n,m,rr=0;
        scanf("%d%d",&n,&m),mp.clear(),pp.clear();
        for(int i=1;i<=n;i++) scanf("%d",&a[i]),v[i].clear(),f[i]=0;
        for(int i=1;i<=m;i++){
            scanf("%d%d",&l[i],&r[i]);
            v[l[i]].push_back(r[i]);
        }
        for(int i=1;i<=n;i++) mp[a[i]].insert(i);
        for(int i=n;i>=1;i--){
            if(!pp[a[i]]) near[i]=n+1;
            else near[i]=pp[a[i]];
            pp[a[i]]=i;
        }
        multiset <int> s;
        for(int i=1;i<=n;i++){
            for(auto t:v[i]) s.insert(t);
            if(!s.size()) continue;
            auto it=s.end();
            --it;
            int pos=*it;
            if(pos<=i) continue;
            auto itt=mp[a[i]].upper_bound(pos);
            --itt;
            if(*itt>i) f[i]=1,nxt[i]=*itt,rr=i;
        }
        if(!rr){
            puts("0");
            continue;
        }
        //for(int i=1;i<=n;i++) cout<<nxt[i]<<" ";puts("");
        mn[0]=INT_MAX,mx[0]=0;
        for(int i=1;i<=n;i++){
            mn[i]=mn[i-1],mx[i]=mx[i-1];
            if(f[i]) mn[i]=min(mn[i],near[i]),mx[i]=max(mx[i],nxt[i]);
        }
        int ans=n+1;
        for(int i=1;i<=n;i++){
            if(mn[i-1]<i) continue;
            int tr=max(rr,mx[i-1]);
            //cout<<i<<" "<<tr<<endl;
            ans=min(ans,tr-i+1);
        }
        printf("%d\n",ans);
    }
    return 0;
}
//unordered_map
//cf