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
#include <assert.h>
#include <random>
using namespace std;
int a[200005];
int cnt[32];
int main() {
    int T = 1, kase = 0;
    cin >> T;
    while (T--) {
        int n,k;
        cin>>n>>k;
        memset(cnt,0,sizeof(cnt));
        for(int i=1;i<=n;i++){
            scanf("%d",&a[i]);
            for(int j=0;j<31;j++) if((1<<j)&a[i]) cnt[j]++;
        }
        int ans=0;
        for(int i=30;i>=0;i--)
            if(k>=n-cnt[i])
                k-=n-cnt[i],ans+=1<<i;
        printf("%d\n",ans);
    }
    return 0;
}
//unordered_map