#include <stdio.h>
#include<iostream>
#include <string>
#include <string.h>
#include <vector>
#include <cmath>
#include <algorithm>
#include <queue>
#include <climits>
#include <set>
#include <unordered_map>
#include <map>
#include <stack>
#include <unordered_set>
#define hash hassh
using namespace std;
long long a[100005],b[100005],pre[100005];
int main() {
    int T=1;
    //cin>>T;
    while(T--){
        int n;
        cin>>n;
        for(int i=1;i<=n;i++) scanf("%lld",&a[i]);
        sort(a+1,a+n+1);
        for(int i=1;i<n;i++) b[i]=a[i+1]-a[i];
        sort(b+1,b+n);
        for(int i=1;i<n;i++) pre[i]=pre[i-1]+b[i];
        int q;
        long long x,y;
        cin>>q;
        for(int i=1;i<=q;i++){
            scanf("%lld%lld",&x,&y);
            x=y-x;
            int l=0,r=n-1;
            while(l<r){
                int mid=(l+r)>>1;
                mid++;
                if(b[mid]<=x) l=mid;
                else r=mid-1;
            }
            printf("%lld ",pre[l]+1LL*(n-l)*(x+1));
        }
    }
    return 0;
}