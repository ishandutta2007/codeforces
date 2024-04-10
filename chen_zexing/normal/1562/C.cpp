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
char s[20005];
int main() {
    int T = 1;
    cin >> T;
    while (T--) {
        int n,pos=-1;
        cin>>n;
        scanf("%s",s+1);
        for(int i=1;i<=n;i++) if(s[i]=='0') pos=i;
        if(pos==-1){
            printf("%d %d %d %d\n",1,n/2,2,n/2+1);
            continue;
        }
        if(pos<=n/2){
            printf("%d %d %d %d\n",pos,pos+n/2,pos+1,pos+n/2);
        }
        else printf("%d %d %d %d\n",pos-n/2,pos,pos-n/2,pos-1);
    }
    return 0;
}
//
/// 
//01
//