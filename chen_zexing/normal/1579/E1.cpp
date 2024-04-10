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
int a[200005],mn[200005],cnt[200005],nd;
void solve(int n){
    if(n==0) return;
    int pos;
    for(int i=n;i>=1;i--){
        cnt[a[i]]=1;
        if(a[i]==nd){
            pos=i;
            break;
        }
    }
    printf("%d ",a[pos]);
    while(cnt[nd]==1) nd++;
    solve(pos-1);
    for(int i=pos+1;i<=n;i++) printf("%d ",a[i]);
}
int main() {
    int T = 1;
    cin >> T;
    while (T--) {
        int n;
        cin>>n;
        for(int i=1;i<=n;i++) scanf("%d",&a[i]),cnt[i]=0;
        nd=1,solve(n),puts("");
    }
    return 0;
}
//
/// 
//01
//