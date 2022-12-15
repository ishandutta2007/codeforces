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
long long a[300005],b[300005];
long long nd[300005];
int main() {
    int T=1;
    cin>>T;
    while(T--) {
        int n;
        scanf("%d",&n);
        for(int i=1;i<=n;i++) scanf("%lld%lld",&a[i],&b[i]);
        long long mn=LLONG_MAX,tot=0;
        for(int i=1;i<=n;i++){
            nd[i%n+1]=max(0LL,a[i%n+1]-b[i]);
            mn=min(mn,a[i%n+1]-nd[i%n+1]);
            tot+=nd[i%n+1];
        }
        printf("%lld\n",tot+mn);
    }
    return 0;
}