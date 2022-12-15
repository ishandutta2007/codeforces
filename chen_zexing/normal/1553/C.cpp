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
#define li __int128_t
using namespace std;
char s[15],t[15];
int main() {
    int T = 1;
    cin >> T;
    while (T--) {
        scanf("%s",s+1);
        int l=strlen(s+1),cnt=0,ans=10;
        for(int i=1;i<=l;i++) if(s[i]=='?') cnt++;
        for(int i=0;i<(1<<cnt);i++){
            int now=0,r1=5,r2=5,t1=0,t2=0;
            for(int j=1;j<=l;j++){
                if(s[j]!='?'){
                    t[j]=s[j];
                    continue;
                }
                if((1<<now)&i) t[j]='1';
                else t[j]='0';
                now++;
            }
            for(int j=1;j<=l;j++){
                if(j%2) r1--;
                else r2--;
                if(t[j]=='1'){
                    if(j%2) t1++;
                    else t2++;
                }
                if(t1>t2+r2||t2>t1+r1) ans=min(ans,j);
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}
//
/// 
//01
// 
//
//dp
//