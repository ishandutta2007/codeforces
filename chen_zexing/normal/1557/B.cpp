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
unordered_map <int,int> mp;
int a[100005],b[100005];
int main() {
    int T = 1;
    cin >> T;
    while (T--){
        int n,k;
        cin>>n>>k;
        mp.clear();
        for(int i=1;i<=n;i++) scanf("%d",&a[i]),b[i]=a[i];
        sort(a+1,a+n+1);
        for(int i=1;i<=n;i++) mp[a[i]]=i;
        for(int i=1;i<=n;i++) a[i]=mp[b[i]];
        int ans=0;
        for(int i=1;i<=n;i++) if(i==1||a[i]!=a[i-1]+1) ans++;
        puts(ans<=k?"Yes":"No");
    }
    return 0;
}
//
/// 
//01
//
//!