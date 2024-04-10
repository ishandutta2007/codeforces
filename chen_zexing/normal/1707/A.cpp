#pragma GCC optimize("Ofast,unroll-loops")
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
int a[100005];
int main() {
    int T = 1, kase = 0;
    cin >> T;
    while (T--) {
        int n,q;
        scanf("%d%d",&n,&q);
        for(int i=1;i<=n;i++) scanf("%d",&a[i]);
        int l=0,r=n;
        while(l<r){
            int mid=(l+r)/2+1;
            int now=q,temp=0,cnt=0;
            for(int i=1;i<=n;i++){
                if(a[i]<=now) temp++,cnt++;
                else{
                    if(!now) break;
                    if(n-i+cnt<mid) now--,temp++,cnt++;
                }
            }
            if(temp>=mid) l=mid;
            else r=mid-1;
        }
        int now=q,temp=0,cnt=0;
        for(int i=1;i<=n;i++){
            if(a[i]<=now) temp++,cnt++,printf("1");
            else if(n-i+cnt<l) now--,temp++,cnt++,printf("1");
            else printf("0");
        }
        puts("");
    }
    return 0;
}
//unordered_map
//cf