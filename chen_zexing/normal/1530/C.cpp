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
int a[100005],b[100005];
long long prea[100005],preb[100005];
bool cmp(int a,int b){
    return a>b;
}
int main() {
    int T = 1;
    cin >> T;
    while (T--) {
        long long sa=0,sb=0;
        int n;
        cin>>n;
        for(int i=1;i<=n;i++) scanf("%d",&a[i]);
        sort(a+1,a+n+1,cmp);
        for(int i=1;i<=n;i++) prea[i]=prea[i-1]+a[i];
        for(int i=1;i<=n;i++) scanf("%d",&b[i]);
        sort(b+1,b+n+1,cmp);
        for(int i=1;i<=n;i++) preb[i]=preb[i-1]+b[i];
        long long l=0,r=1e9;
        while(l<r){
            long long mid=(l+r)>>1;
            int tot=n+mid,re=tot-tot/4;
            long long tota=0,totb=0;
            if(re<=mid){
                tota=1LL*re*100;
                if(re<=n) totb=preb[re];
                else totb=preb[n];
            }
            else{
                tota=1LL*mid*100+prea[re-mid];
                if(re<=n) totb=preb[re];
                else totb=preb[n];
            }
            if(tota>=totb) r=mid;
            else l=mid+1;
        }
        printf("%lld\n",l);
    }
    return 0;
}
//
/// 
//01
// 
//
//dp
//