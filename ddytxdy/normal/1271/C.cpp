#include<bits/stdc++.h>
using namespace std;
const int N=2e5+50;
int n,fx,fy,nu,nd,nl,nr,d;
int main(){
    scanf("%d%d%d",&n,&fx,&fy);
    for(int i=1,x,y;i<=n;i++){
        scanf("%d%d",&x,&y);
        if(x>fx)nd++;
        if(x<fx)nu++;
        if(y>fy)nr++;
        if(y<fy)nl++;
    }
    d=max(max(nu,nd),max(nl,nr));
    printf("%d\n",d);
    if(nu==d)printf("%d %d\n",fx-1,fy),exit(0);
    if(nd==d)printf("%d %d\n",fx+1,fy),exit(0);
    if(nl==d)printf("%d %d\n",fx,fy-1),exit(0);
    if(nr==d)printf("%d %d\n",fx,fy+1),exit(0);
    return 0;
}