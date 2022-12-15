#pragma GCC optimize(3)
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
#include <bitset>
using namespace std;
int query(int l,int r){
    printf("? %d %d\n",l,r);
    fflush(stdout);
    int cnt=0;
    for(int i=l,t;i<=r;i++) scanf("%d",&t),cnt+=(t>=l&&t<=r);
    return cnt;
}
int main() {
    int T = 1, kase = 0;
    cin >> T;
    while (T--) {
        int n;
        scanf("%d",&n);
        int l=1,r=n;
        while(l<r){
            int mid=(l+r)>>1;
            if(query(l,mid)%2) r=mid;
            else l=mid+1;
        }
        printf("! %d\n",l);
        fflush(stdout);
    }
    return 0;
}
//cf