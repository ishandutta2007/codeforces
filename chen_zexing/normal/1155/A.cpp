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
char s[300005];
int mn[300005],pos[300005];
int main() {
    int T = 1;
    //cin >> T;
    while (T--) {
        int n;
        cin>>n;
        scanf("%s",s+1);
        mn[n]=s[n]-'a',pos[n]=n;
        for(int i=n-1;i>=1;i--){
            mn[i]=min(mn[i+1],int(s[i]-'a')),pos[i]=(mn[i]==s[i]-'a'?i:pos[i+1]);
            if(s[i]-'a'>mn[i]){
                printf("YES\n%d %d\n",i,pos[i]);
                exit(0);
            }
        }
        puts("NO");
    }
    return 0;
}
//
/// 
//01
//