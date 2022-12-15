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
    cin >> T;
    while (T--) {
        int n;
        scanf("%s",s+1);
        n=strlen(s+1);
        int f=1;
        for(int i=1;i<=n;i++) if(s[i]=='0') f=0;
        if(f) {
            puts("0");
            continue;
        }
        int cnt=0;
        for(int i=1;i<=n;i++) if(s[i]=='0'&&(i==n||s[i]!=s[i+1])) cnt++;
        if(cnt==1) puts("1");
        else puts("2");
    }
    return 0;
}
//
/// 
//01
//