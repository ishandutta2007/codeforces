#include<bits/stdc++.h>
using namespace std;

int n,m,ga[1005],gb[1005];
char g[1005][1005];

void mian(){
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>g[i]+1;
    }
    if(n==2&&g[1][2]!=g[2][1]&&(m&1^1)){
        cout<<"NO\n";
        return;
    }
    cout<<"YES\n";
    bool grt=false;
    int gx[2];
    for(int i=1;i<=n;i++){
        ga[i]=gb[i]=-1;
        for(int j=1;j<=n;j++)if(i!=j){
            if(g[i][j]==g[j][i]){
                grt=true;
                gx[0]=i;gx[1]=j;
            }
            if(g[i][j]=='a')ga[i]=j;
            if(g[i][j]=='b')gb[i]=j;
        }
    }
    if(grt){
        for(int i=0;i<=m;i++)cout<<gx[i&1]<<' ';
        cout<<'\n';
        return;
    }
    if(m&1^1){
        int res[3];
        for(int i=1;i<=n;i++)if(ga[i]!=-1&&gb[i]!=-1){
            res[0]=ga[i];
            res[1]=i;
            res[2]=gb[i];
            break;
        }
        if(m&2){
            cout<<res[0]<<' ';
            for(int i=1;i<=m-2>>1;i++){
                cout<<res[i&1]<<' ';
            }
            cout<<res[1]<<' '<<res[2]<<' ';
            for(int i=0;i<m-2>>1;i++){
                cout<<res[(i&1)+1]<<' ';
            }
            cout<<'\n';
        }else{
            cout<<res[1]<<' ';
            for(int i=0;i<m>>1;i++){
                cout<<res[i&1]<<' ';
            }
            for(int i=1;i<=m>>1;i++){
                cout<<res[(i&1)+1]<<' ';
            }
            cout<<'\n';
        }
    }else{
        for(int i=0;i<=m;i++){
            cout<<(i&1)+1<<' ';
        }
        cout<<'\n';
    }
}

int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int T;
    cin>>T;
    while(T--)mian();

    return 0;
}