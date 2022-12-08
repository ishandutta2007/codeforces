#include<bits/stdc++.h>
using namespace std;
int vis[1505],k1,k2,k3;
int main(){
    scanf("%d%d%d",&k1,&k2,&k3);
    vis[k1]++; vis[k2]++; vis[k3]++;
    if(vis[1]) printf("YES\n");
    else if(vis[2]>=2) printf("YES\n");
    else if(vis[3]>=3) printf("YES\n");
    else if(vis[2]&&vis[4]>=2) printf("YES\n");
    else printf("NO\n");
    return 0;
}