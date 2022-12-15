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
int a[100005];
int main() {
    int T;
    cin>>T;
    while(T--){
        long long sum=0;
        int mx=0;
        int n;
        cin>>n;
        for(int i=1;i<=n;i++) scanf("%d",&a[i]),sum+=a[i],mx=max(mx,a[i]);
        long long ans=0;
        if(1LL*mx*(n-1)>sum) ans=1LL*mx*(n-1)-sum;
        else if(sum%(n-1)==0) ans=0;
        else ans=(n-1)-sum%(n-1);
        printf("%lld\n",ans);
    }
    return 0;
}