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
char s[105];
int main() {
    int T = 1;
    cin >> T;
    while (T--) {
        int n,pos=-1;
        cin>>n;
        scanf("%s",s+1);
        for(int i=1;i<=n;i++) if(s[i]=='8'){
                pos=i;
                break;
            }
        if(pos==-1||n-pos+1<11) puts("NO");
        else puts("YES");
    }
    return 0;
}
//
/// 
//01
//