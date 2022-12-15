#include <stdio.h>
#include <iostream>
#include <string>
#include <string.h>
#include <vector>
#include <cmath>
#include <assert.h>
#include <algorithm>
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
using namespace std;
char s[200005];
int pre[200005][26];
int main() {
    int T = 1;
    //cin >> T;
    while (T--) {
        int n,q;
        cin>>n>>q;
        scanf("%s",s+1);
        for(int i=1;i<=n;i++){
            for(int j=0;j<26;j++) pre[i][j]=pre[i-1][j];
            pre[i][s[i]-'a']++;
        }
        while(q--){
            int l,r;
            scanf("%d%d",&l,&r);
            int cnt[26];
            for(int j=0;j<26;j++) cnt[j]=pre[r][j]-pre[l-1][j];
            long long ans=0;
            for(int j=0;j<26;j++) if(cnt[j]) ans+=1LL*cnt[j]*(j+1);
            printf("%lld\n",ans);
        }
    }
    return 0;
}
//
/// 
//01
// 
//
//dp