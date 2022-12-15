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
int deg[100005];
bool cmp(int a,int b){
    return a>b;
}
int ver[200005],w[200005];
int main() {
    int T;
    cin>>T;
    while(T--){
        int n;
        cin>>n;
        for(int i=1;i<=n;i++) scanf("%d",&w[i]),deg[i]=0;
        for(int i=1;i<n;i++){
            int x,y;
            scanf("%d%d",&x,&y);
            deg[x]++,deg[y]++;
        }
        int x=0;
        for(int i=1;i<=n;i++)
            for(int j=1;j<=deg[i]-1;j++)
                ver[++x]=w[i];
        sort(ver+1,ver+x+1,cmp);
        //for(int i=1;i<=x;i++) printf("%d ",ver[i]);
        //puts("");
        long long ans=0;
        for(int i=1;i<=n;i++) ans+=w[i];
        for(int i=1;i<n;i++){
            printf("%lld ",ans);
            ans+=ver[i];
        }
        puts("");
    }
    return 0;
}