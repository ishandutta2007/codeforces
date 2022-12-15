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
char s[3][105];
int main() {
    int T = 1;
    cin >> T;
    while (T--) {
        int n,f=1;
        cin>>n;
        for(int i=1;i<=2;i++) scanf("%s",s[i]+1);
        for(int i=1;i<=n;i++) if(s[1][i]=='1'&&s[2][i]=='1') f=0;
        puts(f?"YES":"NO");
    }
    return 0;
}
//
/// 
//01
//