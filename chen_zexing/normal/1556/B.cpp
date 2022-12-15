#include <stdio.h>
#include <iostream>
#include <string>
#include <string.h>
#include <vector>
#include <cmath>
#include <assert.h>
#include <algorithm>
#include <stdlib.h>
#include <queue>
#include <climits>
#include <set>
#include <unordered_map>
#include <time.h>
#include <map>
#include <stack>
#include <unordered_set>
#include <bitset>
#define hash hassh
#define li __int128_t
#define ull unsigned long long
using namespace std;
int a[100005];
int main() {
    int T = 1;
    cin >> T;
    while (T--) {
        int n,cnt[2]={};
        scanf("%d",&n);
        for(int i=1;i<=n;i++) scanf("%d",&a[i]),cnt[a[i]%2]++;
        if(abs(cnt[0]-cnt[1])>=2){
            puts("-1");
            continue;
        }
        if(cnt[0]-cnt[1]==1){
            long long ans=0,c=0;
            for(int i=1;i<=n;i++)
                if(a[i]%2) c++,ans+=abs(i-c*2);
            printf("%lld\n",ans);
        }
        else if(cnt[1]-cnt[0]==1){
            long long ans=0,c=0;
            for(int i=1;i<=n;i++)
                if(a[i]%2==0) c++,ans+=abs(i-c*2);
            printf("%lld\n",ans);
        }
        else{
            long long ans1=0,ans2=0,c=0,ans;
            for(int i=1;i<=n;i++) if(a[i]%2) c++,ans1+=abs(i-c*2);
            c=0;
            for(int i=1;i<=n;i++) if(a[i]%2==0) c++,ans2+=abs(i-c*2);
            ans=min(ans1,ans2);
            printf("%lld\n",ans);
        }
    }
    return 0;
}
//
/// 
//01
//