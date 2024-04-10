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
char s[100005],t[100005];
int main() {
    int T = 1;
    cin >> T;
    while (T--) {
        scanf("%s",s+1);
        scanf("%s",t+1);
        int l1=strlen(s+1),l2=strlen(t+1);
        if(l1<l2){
            puts("NO");
            continue;
        }
        int nd,now=1,f=0;
        if(l1%2) nd=l2%2;
        else nd=(l2%2)^1;
        for(int i=1;i<=l1;i++){
            if(i%2!=nd) continue;
            if(s[i]==t[now]){
                now++,nd^=1;
                if(now>l2){
                    f=1;
                    break;
                }
            }
        }
        puts(f?"YES":"NO");
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