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
char s[100005];
int main() {
    int T = 1, kase = 0;
    cin >> T;
    while (T--) {
        int n,k;
        scanf("%d%d",&n,&k);
        scanf("%s",s+1);
        long long now=0,ans=INT_MAX;
        int mx=0,mn=0;
        for(int i=1;i<=n;i++){
            if(i<n) now+=(s[i]-'0')*10+s[i+1]-'0';
            if(s[i]=='1') mx=max(mx,i);
            if(s[i]=='1'&&mn==0) mn=i;
        }
        if(mn==0&&mx==0){
            puts("0");
            continue;
        }
        ans=now;
        if(mn==mx){
            if(mn==1){
                if(n-mn<=k) ans=min(ans,now-9);
            }
            else if(mn!=n){
                if(n-mn<=k) ans=min(ans,now-10);
                if(mn-1<=k) ans=min(ans,now-1);
            }
        }
        else {
            if (mx < n && n - mx <= k) ans = min(ans, now - 10);
            if (mn > 1 && mn - 1 <= k) ans = min(ans, now - 1);
            if (mx < n && mn > 1 && n - mx + mn - 1 <= k) ans = min(ans, now - 11);
        }
        printf("%lld\n",ans);
    }
    return 0;
}