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
char s[100005];
int main() {
    int T = 1;
    //cin >> T;
    while (T--) {
        int n;
        cin>>n;
        scanf("%s",s+1);
        int t=(n-11)/2,cnt=0,rest=t;
        for(int i=1;i<=n;i++){
            if(s[i]=='8') cnt++;
            else{
                if(rest) rest--;
                else break;
            }
        }
        if(cnt>t) puts("YES");
        else puts("NO");
    }
    return 0;
}
//
/// 
//01
//