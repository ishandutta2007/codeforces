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
int a[200005];
int main() {
    int T = 1, kase = 0;
    cin >> T;
    while (T--) {
        int n,s,tot=0;
        scanf("%d%d",&n,&s);
        for(int i=1;i<=n;i++) scanf("%d",&a[i]),tot+=a[i];
        if(tot<s){
            puts("-1");
            continue;
        }
        int cnt=a[1],r=1,ans=0;
        while(cnt<s){
            r++;
            if(a[r]==1) cnt++;
        }
        ans=max(ans,r);
        for(int i=1;i<=n;i++){
            while(r<=n&&cnt<=s){
                if(cnt<s) r++,cnt+=r<=n&&a[r];
                else if(r<n&&a[r+1]==0) r++;
                else break;
            }
            if(cnt<s) break;
            ans=max(ans,r-i+1);
            cnt-=a[i];
        }
        printf("%d\n",n-ans);
    }
    return 0;
}
//cf