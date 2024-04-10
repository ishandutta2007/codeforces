#include <cstdio>
#include <iostream>
#include <unordered_map>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <climits>
#include <algorithm>
#include <complex>
#include <string.h>
#include <iomanip>
using namespace std;
char s[55];
int cnt[26];
int main() {
    int T = 1;
    cin >> T;
    while(T--) {
        memset(cnt,0,sizeof(cnt));
        scanf("%s",s+1);
        int n=strlen(s+1);
        for(int i=1;i<=n;i++) cnt[s[i]-'a']++;
        for(int i=0;i<26;i++) if(cnt[i]==2) printf("%c",'a'+i);
        for(int i=0;i<26;i++) if(cnt[i]==2) printf("%c",'a'+i);
        for(int i=0;i<26;i++) if(cnt[i]==1) printf("%c",'a'+i);
        puts("");
    }
    return 0;
}