#include<bits/stdc++.h>
using namespace std;

int n,sn,m,q,tx[100005][15],ty[100005][15];
char g[100005][15];

void calc(int lb,int rb){
    rb=min(rb,n);
    for(int i=lb;i<=rb;i++){
        memset(tx[i],0,sizeof(tx[0]));
        memset(ty[i],0,sizeof(tx[0]));
        if(g[i][1]=='<')tx[i][1]=i,ty[i][1]=0;
        if(g[i][m]=='>')tx[i][m]=i,ty[i][m]=m+1;
        for(int j=1;j<=m;j++){
            if(g[i][j]=='^'){
                tx[i][j]=i==lb?i-1:tx[i-1][j];
                ty[i][j]=i==lb?j:ty[i-1][j];
            }else if(g[i][j]=='>'&&g[i][j+1]=='<'){
                tx[i][j]=tx[i][j+1]=ty[i][j]=ty[i][j+1]=-1;
            }
        }
        for(int j=1;j<=m;j++)if(!tx[i][j]&&!ty[i][j]&&g[i][j]=='<'){
            tx[i][j]=tx[i][j-1];
            ty[i][j]=ty[i][j-1];
        }
        for(int j=m;j>=1;j--)if(!tx[i][j]&&!ty[i][j]){
            tx[i][j]=tx[i][j+1];
            ty[i][j]=ty[i][j+1];
        }
    }
}

int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin>>n>>m>>q;
    sn=275;
    for(int i=1;i<=n;i++){
        cin>>g[i]+1;
    }
    for(int l=1;l<=n;l+=sn){
        calc(l,l+sn-1);
    }
    while(q--){
        char typ,op;
        int x,y;
        cin>>typ>>x>>y;
        if(typ=='A'){
            while(x>=1&&y>=1&&y<=m){
                tie(x,y)=make_pair(tx[x][y],ty[x][y]);
            }
            cout<<x<<' '<<y<<'\n';
        }else{
            cin>>op;
            g[x][y]=op;
            calc(x,(x+sn-1)/sn*sn);
        }
    }

    return 0;
}