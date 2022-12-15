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
char s[55];
int main() {
    int T = 1;
    cin >> T;
    while (T--) {
        int n;
        scanf("%s",s+1);
        n=strlen(s+1);
        int cnt=0;
        for(int i=1;i<=n;i++) s[i]=='B'?cnt++:cnt--;
        puts(cnt==0?"YES":"NO");
    }
    return 0;
}
//
/// 
//01
//