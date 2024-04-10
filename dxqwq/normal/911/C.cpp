#include<cstdio>
#include<iostream>
using namespace std;
int vis[1505];
int main(){
    int k1,k2,k3;
    scanf("%d%d%d",&k1,&k2,&k3);
    vis[k1]++;
    vis[k2]++;
    vis[k3]++;
    if(vis[1]) puts("YES"); 
    else if(vis[2]>=2) puts("YES");
    else if(vis[3]>=3) puts("YES");
    else if(vis[2]&&vis[4]>=2) puts("YES");
    else puts("NO");
    return 0;
}