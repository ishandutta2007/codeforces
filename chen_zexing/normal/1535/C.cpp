#include <stdio.h>
#include <iostream>
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
char s[200005];
int a[200005],nxt[200005][2];
int main() {
    int T = 1;
    cin >> T;
    while (T--) {
        int n;
        scanf("%s",s+1);
        n=strlen(s+1);
        for(int i=1;i<=n;i++){
            if(s[i]=='?') a[i]=-1;
            else a[i]=(s[i]-'0'+i)%2;
        }
        nxt[n+1][0]=nxt[n+1][1]=n+1;
        for(int i=n;i>=1;i--){
            nxt[i][0]=nxt[i+1][0];
            nxt[i][1]=nxt[i+1][1];
            if(s[i]!='?') nxt[i][a[i]]=i;
        }
        long long ans=0;
        for(int i=1;i<=n;i++) ans+=max(nxt[i][0],nxt[i][1])-i;
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