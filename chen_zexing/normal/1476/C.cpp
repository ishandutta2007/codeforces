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
long long a[100005],b[100005],c[100005],mx[100005];
int main() {
    int T = 1;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        for(int i=1;i<=n;i++) scanf("%lld",&c[i]);
        for(int i=1;i<=n;i++) scanf("%lld",&a[i]);
        for(int i=1;i<=n;i++) scanf("%lld",&b[i]);
        mx[1]=abs(a[2]-b[2]);
        long long ans=0;
        for(int i=2;i<=n;i++){
            ans=max(ans,c[i]-1+2+mx[i-1]);
            if(a[i+1]!=b[i+1]) mx[i]=max(c[i]+1+mx[i-1]-abs(a[i+1]-b[i+1]),abs(a[i+1]-b[i+1]));
            else mx[i]=0;
        }
        printf("%lld\n",ans);
    }
    return 0;
}