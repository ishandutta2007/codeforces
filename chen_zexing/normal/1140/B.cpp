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
char s[105];
int main() {
    int T = 1;
    cin >> T;
    while (T--) {
        int n,p1=INT_MAX,p2=INT_MAX;
        cin>>n;
        scanf("%s",s+1);
        for(int i=1;i<=n;i++) if(s[i]=='>'){
                p1=i-1;
                break;
            }
        for(int i=n;i>=1;i--) if(s[i]=='<'){
                p2=n-i;
                break;
            }
        printf("%d\n",min(p1,p2));
    }
    return 0;
}
//
/// 
//01
//