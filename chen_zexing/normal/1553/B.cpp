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
char s[505],t[1005];
int main() {
    int T = 1;
    cin >> T;
    while (T--) {
        scanf("%s",s+1);
        scanf("%s",t+1);
        int l1=strlen(s+1),l2=strlen(t+1),f=0;
        for(int i=1;i<=l1;i++) {
            for (int j = i; j <= l1&&j-i+1<=l2; j++){
                int len=l2-(j-i+1),now=0;
                if(j<=len) continue;
                char tar[1005];
                for(int k=i;k<=j;k++) tar[++now]=s[k];
                for(int k=j-1;k>=j-len;k--) tar[++now]=s[k];
                int fl=1;
                for(int k=1;k<=l2;k++) if(t[k]!=tar[k]) fl=0;
                if(fl) f=1;
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