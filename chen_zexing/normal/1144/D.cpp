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
int a[200005],cnt[200005];
int main() {
    int T = 1;
    //cin >> T;
    while (T--) {
        int n,mx=0,pos=-1,pp=-1;
        cin>>n;
        for(int i=1;i<=n;i++) scanf("%d",&a[i]),cnt[a[i]]++;
        for(int i=0;i<=2e5;i++) if(mx<cnt[i]) mx=cnt[i],pos=i;
        printf("%d\n",n-mx);
        for(int i=1;i<=n;i++) if(a[i]==pos) pp=i;
        for(int i=pp-1;i>=1;i--){
            if(a[i]==a[pp]) continue;
            else if(a[i]>a[pp]) printf("%d %d %d\n",2,i,i+1);
            else printf("%d %d %d\n",1,i,i+1);
        }
        for(int i=pp+1;i<=n;i++){
            if(a[i]==a[pp]) continue;
            else if(a[i]>a[pp]) printf("%d %d %d\n",2,i,i-1);
            else printf("%d %d %d\n",1,i,i-1);
        }
    }
    return 0;
}
//
/// 
//01
//