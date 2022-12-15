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
        int n,ans=2,ac=0;
        cin>>n;
        for(int i=1;i<=n;i++) scanf("%d",&a[i]);
        if(a[1]==a[n]){
            puts("0");
            continue;
        }
        for(int k=1;k<=n-1;k++) {
            if(k<n-1&&a[k]==a[k+1]){
                ac++;
                continue;
            }
            int pre1 = a[k], pre2 = a[k+1],temp=ac+2;
            for (int i = k+2; i <= n; i++) {
                int pos = lower_bound(a +i, a + n + 1, pre2 * 2 - pre1) - a;
                if (pos == n + 1) break;
                temp++, pre2 = a[pos],i=pos;
            }
            //cout<<k<<" "<<temp<<endl;
            ans=max(ans,temp),ac=0;
        }
        printf("%d\n",n-ans);
    }
    return 0;
}