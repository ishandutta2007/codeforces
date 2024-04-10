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
int cnt[200005],a[200005],large[200005],c[200005],id[200005];
vector <int> v[200005];
bool cmp(int x,int y){
    return a[x]>a[y];
}
int main() {
    int n,k;
    cin>>n>>k;
    for(int i=1;i<=n;i++) scanf("%d",&a[i]),cnt[a[i]]++,id[i]=i;
    sort(id+1,id+n+1,cmp);
    for(int i=k;i>=1;i--) large[i]=large[i+1]+cnt[i];
    for(int i=1;i<=k;i++) scanf("%d",&c[i]);
    int l=1,r=n;
    while(l<r){
        int mid=(l+r)/2;
        int f=1;
        for(int i=1;i<=k;i++)
            if(large[i]>1LL*c[i]*mid)
                f=0;
        if(f) r=mid;
        else l=mid+1;
    }
    printf("%d\n",l);
    int x=0;
    for(int i=0;x<n;i++){
        v[i].push_back(id[++x]);
        if(i==l-1) i-=l;
    }
    for(int i=0;i<l;i++) {
        printf("%d ",v[i].size());
        for(int j=0;j<v[i].size();j++) printf("%d ",a[v[i][j]]);
        printf("\n");
    }
    return 0;
}