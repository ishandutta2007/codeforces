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
struct node{
    long long a,b;
}a[100005];
bool cmp(node a,node b){
    return a.b<b.b;
}
int main() {
    int T = 1;
    //cin >> T;
    while (T--) {
        int n;
        long long sum=0,ans=0;
        cin>>n;
        for(int i=1;i<=n;i++) scanf("%lld%lld",&a[i].a,&a[i].b),sum+=a[i].a,ans+=a[i].a*2;
        sort(a+1,a+n+1,cmp);
        long long l=0,r=sum;
        while(l<r){
            long long mid=(l+r)/2+1;
            long long rest=mid,pre=sum-mid,f=1;
            for(int i=1;i<=n&&rest>0;i++){
                if(pre<a[i].b) f=0;
                pre+=a[i].a,rest-=a[i].a;
            }
            if(f) l=mid;
            else r=mid-1;
        }
        printf("%lld\n",ans-l);
    }
    return 0;
}
//
/// 
//01
// 
//
//dp