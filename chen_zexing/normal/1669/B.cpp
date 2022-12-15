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
int cnt[200005];
int main() {
    int T = 1, kase = 0;
    cin >> T;
    while (T--) {
        int n;
        scanf("%d",&n);
        for(int i=1;i<=n;i++) cnt[i]=0;
        for(int i=1,x;i<=n;i++) scanf("%d",&x),cnt[x]++;
        int f=0;
        for(int i=1;i<=n;i++) if(cnt[i]>=3){
                printf("%d\n",i);
                f=1;
                break;
            }
        if(!f) puts("-1");
    }
    return 0;
}
//unordered_map