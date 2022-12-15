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
        int n;
        cin>>n;
        for(int i=1;i<=n;i++) scanf("%d",&a[i]);
        int l=1,r=n,ans=0;
        long long pre=a[1],suf=a[n];
        while(l<r){
            if(pre==suf){
                ans=l+n-r+1;
                l++,pre+=a[l];
            }
            else if(pre<suf) l++,pre+=a[l];
            else r--,suf+=a[r];
        }
        printf("%d\n",ans);
    }
    return 0;
}
//unordered_map