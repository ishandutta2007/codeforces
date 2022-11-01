#include<bits/stdc++.h>
using namespace std;

int dx[]={0,1,0,-1};
int dy[]={1,0,-1,0};

int n,m,q;
bool g[1005][1005];
int ans;

int expand(int x,int y,int d){
    int res=0;
    while(!g[x][y]){
        res++;
        x+=dx[d];
        y+=dy[d];
        d^=1;
    }
    return res;
}

int pass(int x,int y){
    //#X
    //.#
    int lu=expand(x,y,2);
    int rd=expand(x,y,1);
    int res=-1;
    res+=lu*rd;
    //#.
    //X#
    lu=expand(x,y,3);
    rd=expand(x,y,0);
    res+=lu*rd;
    return res;
}

int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin>>n>>m>>q;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            int d=n-i+1,r=m-j+1;
            ans++;
            ans+=(min(r,d)-1)*2+(d>r);
            ans+=(min(r,d)-1)*2+(r>d);
        }
    }
    for(int i=1;i<=n;i++)g[i][0]=g[i][m+1]=1;
    for(int i=1;i<=m;i++)g[0][i]=g[n+1][i]=1;
    while(q--){
        int x,y;
        cin>>x>>y;
        if(g[x][y]){
            g[x][y]=0;
            ans+=pass(x,y);
        }else{
            ans-=pass(x,y);
            g[x][y]=1;
        }
        cout<<ans<<'\n';
    }

    return 0;
}