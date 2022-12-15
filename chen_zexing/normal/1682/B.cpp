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
int main() {
    int T = 1, kase = 0;
    cin >> T;
    while (T--) {
        int n,ans;
        scanf("%d",&n),ans=-1;
        for(int i=1;i<=n;i++) scanf("%d",&a[i]);
        for(int i=1;i<=n;i++) if(a[i]!=i-1){
                if(ans==-1) ans=i-1;
                else ans&=(i-1);
            }
        printf("%d\n",ans);
    }
    return 0;
}