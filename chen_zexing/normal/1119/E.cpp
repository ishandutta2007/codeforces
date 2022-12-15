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
long long a[300005];
int main() {
    int T=1;
    //cin>>T;
    while(T--){
        int n;
        cin>>n;
        for(int i=1;i<=n;i++) scanf("%lld",&a[i]);
        long long ans=0;
        long long rest=0;
        for(int i=1;i<=n;i++){
            long long t=min(rest,a[i]/2);
            a[i]-=t*2,rest-=t,ans+=t;
            ans+=a[i]/3,rest+=a[i]%3;
        }
        cout<<ans<<endl;
    }
    return 0;
}