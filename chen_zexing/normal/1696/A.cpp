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
int a[2005];
int main() {
    int T = 1, kase = 0;
    cin >> T;
    while (T--) {
        int n,z,ans=0;
        scanf("%d%d",&n,&z);
        for(int i=1;i<=n;i++) scanf("%d",&a[i]),ans=max(ans,a[i]|z);
        printf("%d\n",ans);
    }
    return 0;
}
//cf