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
int a[200005],b[200005];
int main() {
    int T = 1, kase = 0;
    cin >> T;
    while (T--) {
        int n;
        scanf("%d",&n);
        for(int i=1;i<=n;i++) scanf("%d%d",&a[i],&b[i]);
        int l=1,r=n;
        while(l<r){
            int mid=(l+r)/2+1,cnt=0;
            for(int i=1;i<=n&&cnt<mid;i++){
                if(b[i]>=cnt&&a[i]>=mid-cnt-1) cnt++;
            }
            if(cnt==mid) l=mid;
            else r=mid-1;
        }
        printf("%d\n",l);
    }
    return 0;
}