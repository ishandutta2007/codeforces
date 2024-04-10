#include <stdio.h>
#include <iostream>
#include <string>
#include <string.h>
#include <vector>
#include <cmath>
#include <algorithm>
#include <queue>
#include <climits>
#include <set>
#include <unordered_map>
#include <time.h>
#include <map>
#include <stack>
#include <unordered_set>
#define hash hassh
using namespace std;
int a[300005],c[300005];
int fa[300005][20];
int main() {
    int T = 1;
    //cin >> T;
    while (T--) {
        int q;
        cin>>q>>a[0]>>c[0];
        for(int i=1,t;i<=q;i++){
            scanf("%d",&t);
            if(t==1){
                int p;
                scanf("%d%d%d",&p,&a[i],&c[i]);
                fa[i][0]=p;
                for(int j=1;j<=19;j++) fa[i][j]=fa[fa[i][j-1]][j-1];
            }
            else{
                int temp,w;
                scanf("%d%d",&temp,&w);
                int rest=w,x,cnt=0;
                long long ans=0;
                while(rest) {
                    x=temp;
                    for (int j = 19; j >= 0; j--) if (a[fa[x][j]]) x = fa[x][j];
                    if(!a[x]) break;
                    if(rest>=a[x]) ans+=1LL*a[x]*c[x],cnt+=a[x],rest-=a[x],a[x]=0;
                    else ans+=1LL*rest*c[x],cnt+=rest,a[x]-=rest,rest=0;
                }
                printf("%d %lld\n",cnt,ans);
                fflush(stdout);
            }
        }
    }
    return 0;
}
//
/// 
//01
// 
//
//dp