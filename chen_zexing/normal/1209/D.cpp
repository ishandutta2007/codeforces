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
int fa[200005],sz[200005];
int find(int x){
    return fa[x]==x?x:fa[x]=find(fa[x]);
}
int main() {
    int T = 1;
    //cin >> T;
    while (T--) {
        int n,k;
        cin>>n>>k;
        for(int i=1;i<=n;i++) fa[i]=i,sz[i]=1;
        for(int i=1,x,y;i<=k;i++){
            scanf("%d%d",&x,&y);
            x=find(x),y=find(y);
            if(x!=y){
                fa[y]=x,sz[x]+=sz[y];
            }
        }
        int tot=0;
        for(int i=1;i<=n;i++)
            if(fa[i]==i)
                tot+=sz[i]-1;
        cout<<k-tot<<endl;
    }
    return 0;
}
//
/// 
//01
// 
//
//dp