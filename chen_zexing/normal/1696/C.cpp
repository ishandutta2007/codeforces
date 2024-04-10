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
int a[50005],b[50005];
vector <pair<long long,long long>> v;
int main() {
    int T = 1, kase = 0;
    cin >> T;
    while (T--) {
        int n,k,m;
        scanf("%d%d",&n,&k);
        v.clear();
        for(int i=1;i<=n;i++){
            scanf("%d",&a[i]);
            long long now=a[i],cnt=1;
            while(now%k==0) now/=k,cnt*=k;
            if(v.size()&&v.back().first==now) cnt+=v.back().second,v.pop_back();
            v.push_back(make_pair(now,cnt));
        }
        //for(auto t:v) cout<<t.first<<" "<<t.second<<endl;
        scanf("%d",&m);
        long long pos=0,f=1,used=0;
        for(int i=1;i<=m;i++){
            scanf("%d",&b[i]);
            if(f==0) continue;
            if(pos>=v.size()){
                f=0;
                continue;
            }
            long long now=b[i],cnt=1;
            while(now%k==0) now/=k,cnt*=k;
            if(now!=v[pos].first||cnt+used>v[pos].second){
                //cout<<i<<" "<<pos<<endl;
                f=0;
                continue;
            }
            used+=cnt;
            if(used==v[pos].second) pos++,used=0;
        }
        puts(f&&pos==v.size()?"YES":"NO");
    }
    return 0;
}
//cf