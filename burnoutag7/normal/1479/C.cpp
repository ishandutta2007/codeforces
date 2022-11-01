#include<bits/stdc++.h>
using namespace std;

int l,r,k,g[30][30];

int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin>>l>>r;
    cout<<"YES\n";//Dire Promise lmao
    for(k=-1;1<<k+1<=r-l+1;k++){
        g[1][k+3]=1;
        for(int x=2;x<=k+2;x++)g[x][k+3]=1<<x-2;
    }
    k-=r-l+1==(1<<k);
    g[1][k+3]=1;
    int rr=r-l;
    for(int i=0;i<=k;i++)if(rr>>i&1){
        rr&=~(1<<i);
        g[i+2][k+3]=1+rr;
    }
    k+=3;
    g[k][k+1]=l-1;
    k+=l>1;
    int m=0;
    for(int i=1;i<k;i++)for(int j=i+1;j<=k;j++)m+=(bool)g[i][j];
    cout<<k<<' '<<m<<'\n';
    for(int i=1;i<k;i++)for(int j=i+1;j<=k;j++)if(g[i][j])cout<<i<<' '<<j<<' '<<g[i][j]<<'\n';

    return 0;
}