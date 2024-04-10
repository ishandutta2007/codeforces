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
long long a[100005];
int main() {
    int T=1;
    cin>>T;
    while(T--){
        int n;
        cin>>n;
        long long mx=INT_MIN,mn=INT_MAX;
        for(int i=1;i<=n;i++) scanf("%lld",&a[i]);
        int f=0;
        long long nowmx=0;
        a[n+1]=0;
        for(int i=1;i<=n;i++) {
            if (a[i] != -1 && (a[i - 1] == -1 || a[i + 1] == -1))
                mn = min(mn, a[i]), mx = max(mx, a[i]), f = 1;
            if(i!=1&&a[i]!=-1&&a[i-1]!=-1) nowmx=max(nowmx,abs(a[i-1]-a[i])),f=1;
        }
        long long ans,p;
        if(!f){
            ans=0,p=1;
        }
        else {
            p = (mn + mx) / 2;
            ans = (mx-mn+1)/2;
        }
        cout<<max(nowmx,ans)<<" "<<p<<endl;
    }
    return 0;
}