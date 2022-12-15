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
struct person{
    long long l,r,t;
}a[105];
bool cmp(person a,person b){
    return a.t<b.t;
}
int main() {
    int T;
    cin>>T;
    while(T--){
        int n,m;
        cin>>n>>m;
        for(int i=1;i<=n;i++) scanf("%lld%lld%lld",&a[i].t,&a[i].l,&a[i].r);
        sort(a+1,a+n+1,cmp);
        a[0].l=a[0].r=m;
        long long f=1,l=m,r=m;
        for(int i=1;i<=n;i++){
            l-=a[i].t-a[i-1].t;
            r+=a[i].t-a[i-1].t;
            if(l>a[i].r||r<a[i].l){
                f=0;
            }
            l=max(l,a[i].l);
            r=min(r,a[i].r);
        }
        if(f) puts("YES");
        else puts("NO");
    }
    return 0;
}