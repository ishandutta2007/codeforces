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
int cnt[10005];
int main() {
    int T = 1, kase = 0;
    cin >> T;
    while (T--) {
        int n,ans=0;
        cin>>n;
        memset(cnt,0,sizeof(cnt));
        for(int i=1,x;i<=n;i++){
            scanf("%d",&x);
            cnt[x]++;
            if(cnt[x]==1) ans++;
        }
        if((n-ans)%2) ans--;
        printf("%d\n",ans);
    }
    return 0;
}
//cf