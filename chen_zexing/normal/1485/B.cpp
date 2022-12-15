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
int a[100005],op[100005];
int pre[100005];
int main() {
    int T=1;
    //cin>>T;
    while(T--) {
        int n,q,k;
        cin>>n>>q>>k;
        for(int i=1;i<=n;i++) scanf("%d",&a[i]);
        a[n+1]=INT_MAX;
        for(int i=1;i<=n;i++) op[i]=min(a[i+1],k+1)-a[i-1]-2;
        for(int i=1;i<=n;i++) pre[i]=pre[i-1]+op[i];
        while(q--){
            int l,r;
            scanf("%d%d",&l,&r);
            if(l==r){
                printf("%d\n",k-1);
                continue;
            }
            //cout<<pre[r-1]-pre[l]<<endl;
            printf("%d\n",pre[r-1]-pre[l]+a[l+1]-2+k-a[r-1]-1);
        }
    }
    return 0;
}