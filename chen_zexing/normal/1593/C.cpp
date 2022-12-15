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
int a[400005];
int main() {
    int T = 1;
    cin >> T;
    while(T--){
        int n,k;
        scanf("%d%d",&n,&k);
        for(int i=1;i<=k;i++) scanf("%d",&a[i]);
        sort(a+1,a+k+1);
        int ans=0,tot=0;
        for(int i=k;i>=1;i--){
            if(tot+n-a[i]<n) tot+=n-a[i],ans++;
        }
        printf("%d\n",ans);
    }
    return 0;
}
//
/// 
//01
//