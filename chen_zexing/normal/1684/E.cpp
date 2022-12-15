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
int a[100005],cnt[100005];
map <int,int> mp;
int main() {
    int T = 1, kase = 0;
    cin >> T;
    while (T--) {
        int n,k;
        scanf("%d%d",&n,&k),mp.clear();
        for(int i=1;i<=n;i++) scanf("%d",&a[i]),cnt[i]=0,mp[a[i]]++;
        cnt[0]=0;
        for(int i=1;i<=n;i++) if(a[i]<=n) cnt[a[i]]++;
        int l=0,r=n-1;
        while(l<r){
            int mid=(l+r)/2+1,nd=0,oth=n;
            for(int i=0;i<=mid;i++){
                if(cnt[i]) oth--;
                else nd++;
            }
            if(oth>=nd&&nd<=k) l=mid;
            else r=mid-1;
        }
        //cout<<l<<endl;
        int nd=k;
        vector <int> v;
        for(auto t:mp){
            if(t.first>l) v.push_back(t.second);
        }
        sort(v.begin(),v.end());
        int ans=v.size();
        for(auto t:v){
            if(t<=nd) ans--,nd-=t;
            else break;
        }
        printf("%d\n",ans);
    }
    return 0;
}
//unordered_map
//cf