#include <stdio.h>
#include<iostream>
#include <string>
#include <string.h>
#include <vector>
#include <cmath>
#include <algorithm>
#include <queue>
#include <climits>
#include <set>
#include <unordered_map>
#include <map>
#include <stack>
#include <unordered_set>
#define hash hassh
using namespace std;
unordered_map <long long ,int> mp;
int a[200005],c[200005];
int main() {
    int T=1;
    //cin>>T;
    while(T--){
        int n;
        long long ans=0;
        cin>>n;
        for(int i=1;i<=n;i++) scanf("%d",&a[i]),ans+=a[i];
        int q;
        cin>>q;
        for(int i=1;i<=q;i++){
            int x,y,z;
            scanf("%d%d%d",&x,&y,&z);
            long long t=1LL*x*1e9+y;
            if(mp[t]){
                c[mp[t]]--;
                if(c[mp[t]]<a[mp[t]]) ans++;
            }
            mp[t]=z;
            if(mp[t]) {
                c[mp[t]]++;
                if (c[mp[t]] <= a[mp[t]]) ans--;
            }
            printf("%lld\n",ans);
        }
    }
    return 0;
}