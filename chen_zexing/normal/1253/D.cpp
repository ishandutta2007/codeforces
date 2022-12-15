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
int fa[200005];
int find(int x){
    return fa[x]==x?x:fa[x]=find(fa[x]);
}
void merge(int x,int y){
    x=find(x),y=find(y);
    if(x>y) swap(x,y);
    fa[x]=y;
}
int main() {
    int T=1;
    //cin>>T;
    while(T--){
        int n,m,ans=0;
        cin>>n>>m;
        for(int i=1;i<=n;i++) fa[i]=i;
        for(int i=1;i<=m;i++){
            int x,y;
            scanf("%d%d",&x,&y);
            merge(x,y);
        }
        for(int i=1;i<=n;i++){
            int t=find(i);
            for(int j=i;j<=t;j++)
            {
                int p=find(j);
                if(p!=t){
                    ans++;
                    merge(p,t);
                    t=find(t);
                }
            }
            i=t;
        }
        cout<<ans<<endl;
    }
    return 0;
}