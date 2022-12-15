#include <stdio.h>
#include <iostream>
#include <string>
#include <string.h>
#include <vector>
#include <cmath>
#include <assert.h>
#include <algorithm>
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
using namespace std;
char s[55];
int a[55];
int main() {
    int T = 1;
    cin >> T;
    while (T--) {
        int n,ans=0;
        cin>>n;
        scanf("%s",s+1);
        for(int i=1;i<=n;i++) a[i]=s[i]-'a';
        sort(a+1,a+n+1);
        for(int i=1;i<=n;i++) if(s[i]!=a[i]+'a') ans++;
        printf("%d\n",ans);
    }
    return 0;
}
//
/// 
//01
// 
//
//dp
//