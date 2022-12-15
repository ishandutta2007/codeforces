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
int a[200005],id[200005];
bool cmp(int x,int y){
    return a[x]>a[y];
}
int main() {
    int T;
    cin>>T;
    while(T--){
        int n,mn=INT_MAX,p1=0,p2=0,mx=-1,k;
        cin>>n>>k;
        for(int i=1;i<=n;i++){
            id[i]=i;
            scanf("%d",&a[i]);
            if(a[i]<mn){
                mn=a[i];
                p1=i;
            }
            if(a[i]>mx&&i!=p1){
                mx=a[i];
                p2=i;
            }
        }
        long long ans=0;
        sort(id+1,id+n+1,cmp);
        for(int i=1;i<=k+1;i++)
            ans+=a[id[i]];
        printf("%lld\n",ans);
    }
    return 0;
}