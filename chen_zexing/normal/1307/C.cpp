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
char s[200005];
int cnt[200005][26];
long long c[26][26];
int main() {
    int T = 1;
    //cin >> T;
    while (T--) {
        scanf("%s",s+1);
        int n=strlen(s+1);
        long long ans=0;
        for(int i=1;i<=n;i++){
            for(int j=0;j<26;j++) cnt[i][j]=cnt[i-1][j];
            cnt[i][s[i]-'a']++;
            ans=max(ans,1LL*cnt[i][s[i]-'a']);
        }
        for(int i=2;i<=n;i++){
            for(int j=0;j<26;j++)
                c[s[i]-'a'][j]+=cnt[i-1][j];
        }
        for(int i=0;i<26;i++)
            for(int j=0;j<26;j++)
                ans=max(ans,c[i][j]);
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