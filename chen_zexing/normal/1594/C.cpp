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
#include <list>
#define hash hassh
#define li __int128_t
#define ull unsigned long long
using namespace std;
char s[300005];
int main() {
    int T = 1;
    cin >> T;
    while (T--) {
        int n;
        char c;
        scanf("%d %c",&n,&c);
        scanf("%s",s+1);
        int f=1,pos=-1;
        for(int i=1;i<=n;i++) if(s[i]!=c) f=0;
        if(f){
            puts("0");
            continue;
        }
        for(int i=n/2+1;i<=n;i++) if(s[i]==c){
                pos=i;
                break;
            }
        if(pos!=-1){
            puts("1");
            printf("%d\n",pos);
        }
        else printf("2\n%d %d\n",n,n-1);
    }
    return 0;
}
//
/// 
//01
//