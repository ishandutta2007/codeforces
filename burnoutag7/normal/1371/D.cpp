#include<bits/stdc++.h>
using namespace std;

int T,n,k;
char g[305][305];
int r[305],c[305];

void mian(){
    memset(g,'0',sizeof(g));
    memset(r,0,sizeof(r));
    memset(c,0,sizeof(c));
    scanf("%d%d",&n,&k);
    int x=1,y=1;
    while(k--){
        r[x]++;
        c[y]++;
        g[x++][y++]='1';
        if(x>n)x-=n,y++;
        if(y>n)y-=n;
    }
    int mnr=*min_element(r+1,r+1+n);
    int mxr=*max_element(r+1,r+1+n);
    int mnc=*min_element(c+1,c+1+n);
    int mxc=*max_element(c+1,c+1+n);
    mxr-=mnr;
    mxc-=mnc;
    printf("%d\n",mxr*mxr+mxc*mxc);
    for(int i=1;i<=n;i++){
        g[i][n+1]=0;
        puts(g[i]+1);
    }
}

int main(){

    scanf("%d",&T);
    while(T--){
        mian();
    }

    return 0;
}