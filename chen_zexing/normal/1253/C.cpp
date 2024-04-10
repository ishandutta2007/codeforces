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
long long pre[200005];
int main() {
    int T=1;
    //cin>>T;
    while(T--){
        int n,m;
        long long ans=0;
        cin>>n>>m;
        for(int i=1;i<=n;i++) scanf("%d",&a[i]);
        sort(a+1,a+n+1);
        for(int i=1;i<=n;i++) pre[i]=i<=m?a[i]:pre[i-m]+a[i];
        for(int i=1;i<=n;i++){
            ans+=pre[i];
            printf("%lld ",ans);
        }
    }
    return 0;
}