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
int a[300005],b[300005],c[300005];
int main() {
    int T=1;
    //cin>>T;
    while(T--) {
        long long sum1=0,sum2=0,sum3=0;
        int n1,n2,n3;
        cin>>n1>>n2>>n3;
        for(int i=1;i<=n1;i++) scanf("%d",&a[i]),sum1+=a[i];
        for(int i=1;i<=n2;i++) scanf("%d",&b[i]),sum2+=b[i];
        for(int i=1;i<=n3;i++) scanf("%d",&c[i]),sum3+=c[i];
        if(sum1>sum2) swap(sum1,sum2);
        if(sum1>sum3) swap(sum1,sum3);
        long long ans1=sum2+sum3-sum1;
        long long ans2=sum1+sum2+sum3;
        sort(a+1,a+n1+1);
        sort(b+1,b+n2+1);
        sort(c+1,c+n3+1);
        if(a[1]<b[1]) swap(a[1],b[1]);
        if(a[1]<c[1]) swap(a[1],c[1]);
        ans2-=2LL*b[1]+2LL*c[1];
        printf("%lld\n",max(ans1,ans2));
    }
    return 0;
}