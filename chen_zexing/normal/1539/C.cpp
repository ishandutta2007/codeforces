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
using namespace std;
long long a[200005],b[200005];
int main() {
    int T = 1;
    //cin >> T;
    while (T--) {
        long long n,k,x,t=0,cnt=0;
        cin>>n>>k>>x;
        for(int i=1;i<=n;i++) scanf("%lld",&a[i]);
        sort(a+1,a+n+1);
        for(int i=2;i<=n;i++) if(a[i]-a[i-1]>x) b[++t]=(a[i]-a[i-1]-1)/x;
        sort(b+1,b+t+1);
        for(int i=1;i<=t;i++){
            if(k>=b[i]) k-=b[i],cnt++;
            else break;
        }
        printf("%lld\n",t-cnt+1);
    }
    return 0;
}
//
/// 
//01
// 
//
//dp