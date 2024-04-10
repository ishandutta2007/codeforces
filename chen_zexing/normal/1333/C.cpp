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
map<long long,int> mp;
int a[200005];
long long pre[200005];
int main() {
    int T=1;
    //cin>>T;
    while(T--) {
        int n;
        int lb=-1;
        long long ans=0;
        cin>>n;
        for(int i=1;i<=n;i++) scanf("%d",&a[i]),pre[i]=pre[i-1]+a[i];
        mp[0]=1;
        for(int i=1;i<=n;i++){
            if(!mp[pre[i]]) ans+=i-max(lb,0);
            else {
                ans += i - max(lb, mp[pre[i]]);
                //cout<<i<<" "<<max(lb,mp[pre[i]])<<endl;
                lb = max(lb, mp[pre[i]]);
            }
            mp[pre[i]]=i+1;
            //cout<<ans<<endl;
        }
        cout<<ans<<endl;
    }
    return 0;
}
//
/// 
//01
// 
//