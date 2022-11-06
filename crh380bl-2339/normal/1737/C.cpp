#include<bits/stdc++.h>
using namespace std;
bool bo[4];
int calc(int x,int y){
    return 2*(x%2)+(y%2);
}
int id[5];
int r[5],c[5];
bool cmp(int x,int y){
    if(r[x]!=r[y])return r[x]<r[y];
    return c[x]<c[y];
}
void work(){
    int n,i;
    scanf("%d",&n);
    memset(bo,0,sizeof(bo));
    for(i=1;i<=4;++i){
        scanf("%d%d",&r[i],&c[i]);
        if(i<=3)bo[calc(r[i],c[i])]=1;
    }
    int sum=0,sum1=0;
    for(i=1;i<=3;++i){
        sum+=r[i]+c[i];
        sum1+=n-r[i]+1+c[i];
    }
    if(sum==8){
        if(r[4]==1||c[4]==1)puts("YES");
        else puts("NO");
    }
    else if(sum==n*6-2){
        if(r[4]==n||c[4]==n)puts("YES");
        else puts("NO");
    }
    else if(sum1==8){
        if(r[4]==n||c[4]==1)puts("YES");
        else puts("NO");
    }
    else if(sum1==n*6-2){
        if(r[4]==1||c[4]==n)puts("YES");
        else puts("NO");        
    }
    else if(bo[calc(r[4],c[4])])puts("YES");
    else puts("NO");
}
int main(){
    int T;
    scanf("%d",&T);
    while(T--){
        work();
    }
    return 0;
}