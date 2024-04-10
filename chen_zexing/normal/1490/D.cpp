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
int a[105],dep[105];
void build(int l,int r,int d){
    if(l>r) return;
    if(l==r){
        dep[l]=d;
        return;
    }
    int mx=0,p=-1;
    for(int i=l;i<=r;i++)
        if(mx<a[i])
            mx=a[i],p=i;
    dep[p]=d;
    build(l,p-1,d+1);
    build(p+1,r,d+1);
}
int main() {
    int T=1;
    cin>>T;
    while(T--){
        int n;
        cin>>n;
        for(int i=1;i<=n;i++) scanf("%d",&a[i]);
        build(1,n,0);
        for(int i=1;i<=n;i++) printf("%d ",dep[i]);
        puts("");
    }
    return 0;
}