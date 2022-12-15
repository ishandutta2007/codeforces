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
int a[200005];
int main() {
    int T;
    cin>>T;
    while(T--) {
        int n;
        scanf("%d",&n);
        for(int i=1;i<=n;i++) scanf("%d",&a[i]);
        if(n<=2){
            puts("0");
            continue;
        }
        sort(a+1,a+n+1);
        int l=1,r=3;
        long long ans=0;
        while(l<=n-2){
            while(r<=n&&a[r]-a[l]<=2) r++;
            r--;
            ans+=1LL*(r-l)*(r-l-1)/2;
            l++;
        }
        printf("%lld\n",ans);
    }
    return 0;
}