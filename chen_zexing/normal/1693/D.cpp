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
int mx[200005],mn[200005];
int main() {
    int T = 1, kase = 0;
    //cin >> T;
    while (T--) {
        int n;
        cin>>n;
        for(int i=1;i<=n;i++) scanf("%d",&a[i]);
        mx[0]=INT_MAX,mn[0]=INT_MIN;
        for(int i=1;i<=n;i++) mx[i] = INT_MIN, mn[i] = INT_MAX;
        int r=0;
        long long ans=0;
        for(int l=1;l<=n;l++) {
            mx[l-1]=INT_MAX,mn[l-1]=INT_MIN;
            for (int i = l; i <= n; i++) {
                int premx=mx[i],premn=mn[i];
                if (i == l || a[i] > a[i - 1]) mx[i] = max(mx[i], mx[i - 1]);
                if (i>l && a[i] > mn[i - 1]) mx[i] = max(mx[i], a[i - 1]);
                if (i == l || a[i] < a[i - 1]) mn[i] = min(mn[i], mn[i - 1]);
                if (i>l && a[i] < mx[i - 1]) mn[i] = min(mn[i], a[i - 1]);
                if((mx[i]!=INT_MIN||mn[i]!=INT_MAX)&&i>r) r=i;
                if(premx==mx[i]&&premn==mn[i]) break;
            }
            ans+=r-l+1;
            //cout<<l<<" "<<r<<endl;
        }
        printf("%lld\n",ans);
    }
    return 0;
}