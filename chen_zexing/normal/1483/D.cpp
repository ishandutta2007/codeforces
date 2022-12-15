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
long long d[605][605],lim[605][605];
int a[360005],b[360005],c[360005];
int main() {
    int T=1;
    //cin>>T;
    while(T--) {
        int n,m;
        cin>>n>>m;
        for(int i=1;i<=n;i++)
            for(int j=1;j<=n;j++)
                d[i][j]=LLONG_MAX/10,lim[i][j]=LLONG_MIN/10;
        for(int i=1;i<=m;i++){
            scanf("%d%d%d",&a[i],&b[i],&c[i]);
            d[a[i]][b[i]]=d[b[i]][a[i]]=c[i];
        }
        for(int i=1;i<=n;i++) d[i][i]=0;
        for(int k=1;k<=n;k++)
            for(int j=1;j<=n;j++)
                for(int i=1;i<=n;i++)
                    d[j][i]=min(d[j][k]+d[k][i],d[j][i]);
        int q;
        cin>>q;
        for(int i=1;i<=q;i++){
            int x,y,z;
            scanf("%d%d%d",&x,&y,&z);
            lim[x][y]=lim[y][x]=z;
        }
        for(int i=1;i<=n;i++)
            for(int j=1;j<=n;j++)
                for(int k=1;k<=n;k++)
                    lim[i][j]=max(lim[i][j],lim[i][k]-d[j][k]),lim[j][i]=max(lim[j][i],lim[i][k]-d[j][k]);
        int ans=0;
        for(int i=1;i<=m;i++){
            for(int j=1;j<=n;j++)
                if(d[a[i]][j]+c[i]<=lim[b[i]][j])
                {
                    ans++;
                    break;
                }
        }
        /*
        for(int i=1;i<=n;i++,puts(""))
            for(int j=1;j<=n;j++)
                printf("%lld ",d[i][j]);
        for(int i=1;i<=n;i++,puts(""))
            for(int j=1;j<=n;j++)
                printf("%lld ",lim[i][j]);
                */
        cout<<ans<<endl;
    }
    return 0;
}
//
/// 
//01
// 
//
//dp