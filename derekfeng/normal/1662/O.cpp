#include<bits/stdc++.h>
using namespace std;

int n;
bool vis[25][365],as[25][365],ds[25][365],cw[25][365],ccw[25][365];

void mian(){
    cin>>n;
    memset(vis,0,sizeof(vis));
    memset(as,1,sizeof(as));
    memset(as[20],0,sizeof(as[20]));
    memset(ds,1,sizeof(ds));
    memset(ds[0],0,sizeof(ds[0]));
    memset(cw,1,sizeof(cw));
    memset(ccw,1,sizeof(ccw));
    for(int i=0;i<n;i++){
        char typ;
        cin>>typ;
        if(typ=='C'){
            int r,a1,a2;
            cin>>r>>a1>>a2;
            for(int i=a1;i!=a2;i=(i+1)%360){
                as[r-1][i]=0;
                ds[r][i]=0;
            }
        }else{
            int r1,r2,a;
            cin>>r1>>r2>>a;
            for(int i=r1;i<r2;i++){
                cw[i][(a+359)%360]=0;
                ccw[i][a]=0;
            }
        }
    }
    queue<pair<int,int>> q;
    q.emplace(0,0);
    vis[0][0]=1;
    while(!q.empty()){
        int r,a;
        tie(r,a)=q.front();
        q.pop();
        if(as[r][a]&&!vis[r+1][a]){
            q.emplace(r+1,a);
            vis[r+1][a]=1;
        }
        if(ds[r][a]&&!vis[r-1][a]){
            q.emplace(r-1,a);
            vis[r-1][a]=1;
        }
        if(cw[r][a]&&!vis[r][(a+1)%360]){
            q.emplace(r,(a+1)%360);
            vis[r][(a+1)%360]=1;
        }
        if(ccw[r][a]&&!vis[r][(a+359)%360]){
            q.emplace(r,(a+359)%360);
            vis[r][(a+359)%360]=1;
        }
    }
    cout<<(*max_element(vis[20],vis[20]+360)?"YES\n":"NO\n");
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