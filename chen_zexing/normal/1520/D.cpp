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
#include <time.h>
#include <map>
#include <stack>
#include <unordered_set>
#define hash hassh
using namespace std;
int a[200005];
map<int,int>mp,f;
int main() {
    int T = 1;
    cin >> T;
    while (T--) {
        int n;
        cin>>n;
        mp.clear(),f.clear();
        for(int i=1;i<=n;i++) scanf("%d",&a[i]),a[i]-=i,mp[a[i]]++;
        long long ans=0;
        for(int i=1;i<=n;i++)
            if(!f[a[i]]){
                f[a[i]]=1;
                ans+=1LL*mp[a[i]]*(mp[a[i]]-1)/2;
            }
        printf("%lld\n",ans);
    }
    return 0;
}
//
/// 
//01
// 
//
//dp