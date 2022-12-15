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
int main() {
    int T = 1;
    cin >> T;
    while (T--) {
        char s[105];
        int cnt[26]={},f=1,ct=0;
        scanf("%s",s+1);
        int n=strlen(s+1);
        for(int i=1;i<=n;i++) cnt[s[i]-'a']++;
        for(int i=0;i<26;i++) if(cnt[i]>1) f=0;
        for(int i=0;i<26;i++)
            if(cnt[i]==1){
                if(i==0) ct++;
                else if(cnt[i-1]==0) ct++;
            }
        if(ct>1||!f) puts("NO");
        else puts("YES");
    }
    return 0;
}
//
/// 
//01
//