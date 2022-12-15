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
int l[300005],r[300005],cnt[300005],a[300005],n;
int main() {
    int T = 1;
    cin >> T;
    while (T--) {
        int ans=0,tot=0,lst=0,now=0;
        cin>>n;
        for(int i=1;i<=n;i++) cnt[i]=0;
        for(int i=1;i<=n;i++) scanf("%d",&a[i]),cnt[a[i]]++,r[a[i]]=i;
        for(int i=n;i>=1;i--) l[a[i]]=i;
        for(int i=1;i<=n;i++){
            if(!cnt[i]) continue;
            if(l[i]<=r[lst]) lst=0,now=0;
            lst=i,now++;
            ans=max(ans,now),tot++;
        }
        printf("%d\n",tot-ans);
    }
    return 0;
}
//
/// 
//01
//