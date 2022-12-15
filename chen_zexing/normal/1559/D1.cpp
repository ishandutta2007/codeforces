#include <stdio.h>
#include <iostream>
#include <string>
#include <string.h>
#include <vector>
#include <cmath>
#include <assert.h>
#include <algorithm>
#include <queue>
#include <climits>
#include <set>
#include <unordered_map>
#include <time.h>
#include <map>
#include <stack>
#include <unordered_set>
#include <bitset>
#define hash hassh
#define li __int128_t
using namespace std;
int fa[2][1005];
int find(int x,int id){
    return fa[id][x]==x?x:fa[id][x]=find(fa[id][x],id);
}
int main() {
    int T = 1;
    //cin >> T;
    while (T--){
        int n,m1,m2;
        cin>>n>>m1>>m2;
        for(int i=1;i<=n;i++) fa[0][i]=fa[1][i]=i;
        for(int i=1,x,y;i<=m1;i++){
            scanf("%d%d",&x,&y);
            x=find(x,0),y=find(y,0);
            fa[0][y]=x;
        }
        for(int i=1,x,y;i<=m2;i++){
            scanf("%d%d",&x,&y);
            x=find(x,1),y=find(y,1);
            fa[1][y]=x;
        }
        printf("%d\n",n-1-max(m1,m2));
        for(int i=1;i<=n;i++)
            for(int j=i+1;j<=n;j++){
                int x1=find(i,0),y1=find(j,0),x2=find(i,1),y2=find(j,1);
                if(x1!=y1&&x2!=y2){
                    fa[0][y1]=x1,fa[1][y2]=x2;
                    printf("%d %d\n",i,j);
                }
            }
    }
    return 0;
}
//
/// 
//01
//
//!