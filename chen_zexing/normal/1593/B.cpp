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
char s[25];
int main() {
    int T = 1;
    cin >> T;
    while(T--){
        scanf("%s",s+1);
        int n=strlen(s+1),ans=n-1;
        for(int i=1;i<=n;i++)
            for(int j=i+1;j<=n;j++){
                int temp=(s[i]-'0')*10+s[j]-'0';
                if(temp%25==0) ans=min(ans,n-i+1-2);
            }
        printf("%d\n",ans);
    }
    return 0;
}
//
/// 
//01
//