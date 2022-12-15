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
int a[200005],n,b[200005],pre[200005],k;
int check(int x){
    for(int i=1;i<=n;i++){
        if(a[i]>=x) b[i]=1;
        else b[i]=-1;
        pre[i]=pre[i-1]+b[i];
    }
    int mx=pre[n];
    for(int i=n-k;i>=0;i--){
        if(mx-pre[i]>0) return 1;
        mx=max(mx,pre[i+k-1]);
    }
    return 0;
}
int main() {
    int T=1;
    //cin>>T;
    while(T--){
        cin>>n>>k;
        for(int i=1;i<=n;i++) scanf("%d",&a[i]);
        int l=1,r=n;
        while(l<r){
            int mid=(l+r)>>1;
            mid++;
            if(check(mid)) l=mid;
            else r=mid-1;
        }
        cout<<l<<endl;
    }
    return 0;
}