#include<bits/stdc++.h>

using namespace std;

vector<vector<int> > v;
vector<vector<int> > pfx;
vector<vector<int> > sfx;
int n,m;

int calc(int x,int y){
    int lx=sfx[x][y],rx=pfx[x][y];
    if(x!=0&&y!=0) lx-=sfx[x-1][y-1];
    if(x!=n-1&&y!=m-1) rx-=pfx[x+1][y+1];
    return lx+rx-v[x][y];
}

int main(){
    ios::sync_with_stdio(0);
    int q;
    cin>>q;
    while(q--){
        cin>>n>>m;
        v.clear();pfx.clear();sfx.clear();
        for(int i=0;i<n;i++){
            vector<int> t,t1;
            for(int j=0;j<m;j++){
                char v;
                cin>>v;
                if(v=='.') t.push_back(1);
                else t.push_back(0);
                t1.push_back(0);
            }
            v.push_back(t);
            pfx.push_back(t1);
            sfx.push_back(t1);
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                sfx[i][j]=v[i][j];
                if(i==0&&j==0){
                    sfx[i][j]+=0;
                }else if(i==0){
                    sfx[i][j]+=sfx[i][j-1];
                }else if(j==0){
                    sfx[i][j]+=sfx[i-1][j];
                }else{
                    sfx[i][j]+=sfx[i-1][j]+sfx[i][j-1]-sfx[i-1][j-1];
                }
            }
        }
        for(int i=n-1;i>=0;i--){
            for(int j=m-1;j>=0;j--){
                pfx[i][j]=v[i][j];
                if(i==n-1&&j==m-1){
                    pfx[i][j]+=0;
                }else if(i==n-1){
                    pfx[i][j]+=pfx[i][j+1];
                }else if(j==m-1){
                    pfx[i][j]+=pfx[i+1][j];
                }else{
                    pfx[i][j]+=pfx[i+1][j]+pfx[i][j+1]-pfx[i+1][j+1];
                }
            }
        }
        int ans=n*m;
        for(int i=0;i<n;i++)for(int j=0;j<m;j++) ans=min(ans,calc(i,j));
        cout<<ans<<'\n';
    }
    return 0;
}