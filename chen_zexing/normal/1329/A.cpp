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
#define hash hassh
using namespace std;
int n,m,a[100005];
long long r[100005];
int main() {
    int mx=0,f=1;
    long long sum=0;
    cin>>n>>m;
    for(int i=1;i<=m;i++){
        scanf("%d",&a[i]),mx=max(mx,a[i]),sum+=a[i];
        if(n-a[i]<i-1) f=0;
    }
    if(!f||sum<n){
        puts("-1");
        return 0;
    }
    for(int i=m;i>=1;i--) r[i]=r[i+1]+a[i];
    for(int i=1;i<=m;i++) printf("%lld ",max(1LL*i,n-r[i]+1));
    return 0;
}