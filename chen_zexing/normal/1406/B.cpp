#include <stdio.h>
#include<iostream>
#include<string>
#include <algorithm>
#include <string.h>
#include <vector>
#include <cmath>
#include <map>
#include <unordered_map>
using namespace std;
int a[200005];
bool cmp(int a,int b){
    return a<b;
}
int main() {
    int T;
    cin>>T;
    while(T--){
        int n;
        long long ans=LLONG_MIN;
        scanf("%d",&n);
        for(int i=1;i<=n;i++) scanf("%d",&a[i]);
        sort(a+1,a+n+1,cmp);
        for(int i=0;i<=5;i++)
        {
            long long cnt=1;
            for(int j=1;j<=i;j++) cnt*=a[j];
            for(int j=n;j>=n-4+i;j--) cnt*=a[j];
            ans=max(ans,cnt);
        }
        printf("%lld\n",ans);
    }
    return 0;
}