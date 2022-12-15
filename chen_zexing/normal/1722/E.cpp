#pragma GCC optimize("Ofast,unroll-loops")
#include <bits/stdc++.h>
using namespace std;
long long pre[1005][1005];
long long a[1005][1005];
int main() {
    int T = 1, kase = 0;
    cin >> T;
    while (T--){
        memset(pre,0,sizeof(pre));
        memset(a,0,sizeof(a));
        int n,q;
        scanf("%d%d",&n,&q);
        for(int i=1,x,y;i<=n;i++) scanf("%d%d",&x,&y),a[x][y]+=x*y;
        for(int i=1;i<=1000;i++)
            for(int j=1;j<=1000;j++)
                pre[i][j]=pre[i-1][j]+pre[i][j-1]+a[i][j]-pre[i-1][j-1];
        for(int i=1,x,xx,y,yy;i<=q;i++){
            scanf("%d%d%d%d",&xx,&yy,&x,&y);
            printf("%lld\n",pre[x-1][y-1]-pre[xx][y-1]-pre[x-1][yy]+pre[xx][yy]);
        }
    }
    return 0;
}