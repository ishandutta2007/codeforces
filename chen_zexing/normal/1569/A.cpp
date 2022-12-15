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
char s[55];
int main() {
    int T = 1;
    cin >> T;
    while (T--) {
        int n,f=0;
        cin>>n;
        scanf("%s",s+1);
        for(int i=1;i<n;i++) if(s[i]!=s[i+1]){
                printf("%d %d\n",i,i+1),f=1;
                break;
            }
        if(!f) puts("-1 -1");
    }
    return 0;
}
//
/// 
//01
//