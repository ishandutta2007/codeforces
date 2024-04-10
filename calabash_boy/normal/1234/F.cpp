#include<bits/stdc++.h>
#define left kldjaflskajs
#define right ejkljkldj
using namespace std;
const int maxn = 1e6 + 10;
const int maxmask  = (1<<20) + 100;
char s[maxn];
int n;
int cnt[maxmask];
int main(){
    scanf("%s",s+1);
    n = strlen(s+1);
    for (int i=1;i<=n;i++){
        int mask = 0;
        for(int j = i;j >=1;j--){
            int bit = 1 << (s[j] - 'a');
            if (mask & bit)break;
            mask |= bit;
            cnt[mask] = __builtin_popcount(mask);
        }
    }
    for (int mask = 0; mask < (1<<20);mask++){
        for (int i=0;i<20;i++){
            if (mask & (1<<i)){
                cnt[mask] = max(cnt[mask],cnt[mask ^ (1<<i)]);
            }
        }
    }
    int ans = 1;
    for (int mask = 1;mask < (1<<20);mask++){
        if (cnt[mask] == __builtin_popcount(mask)){
            ans = max(ans,cnt[mask] + cnt[((1<<20)-1) ^ mask]);
        }
    }
    cout<<ans<<endl;
//    assert(0);
    return 0;
}