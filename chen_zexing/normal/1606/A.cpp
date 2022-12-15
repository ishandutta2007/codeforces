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
    while(T--){
        scanf("%s",s+1);
        int n=strlen(s+1),cnt=0;
        for(int i=1;i<n;i++){
            if(s[i]=='a'&&s[i+1]=='b') cnt++;
            else if(s[i]=='b'&&s[i+1]=='a') cnt--;
        }
        if(cnt==0){
            for(int i=1;i<=n;i++) printf("%c",s[i]);
            puts("");
        }
        else {
            for (int i = 1; i < n; i++) printf("%c", s[i]);
            if (s[n] == 'a') puts("b");
            else puts("a");
        }
    }
    return 0;
}
//
/// 
//01
//