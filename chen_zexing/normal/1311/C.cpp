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
long long tot[26];
int main() {
    int T=1;
    cin>>T;
    while(T--) {
        int n,m;
        cin>>n>>m;
        scanf("%s",s+1);
        for(int i=1;i<=n;i++){
            for(int j=0;j<26;j++) cnt[i][j]=cnt[i-1][j];
            cnt[i][s[i]-'a']++;
        }
        memset(tot,0,sizeof(tot));
        for(int i=0;i<26;i++) tot[i]+=cnt[n][i];
        for(int i=1;i<=m;i++){
            int t;
            scanf("%d",&t);
            for(int j=0;j<26;j++) tot[j]+=cnt[t][j];
        }
        for(int i=0;i<26;i++) printf("%lld ",tot[i]);
        puts("");
    }
    return 0;
}
//
/// 
//01
// 