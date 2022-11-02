#include <bits/stdc++.h>
using namespace std;
constexpr int MAXN=1000;
bool arr[MAXN][MAXN];
int ind[MAXN][MAXN];
int di[]={0,1,0,-1};
int dj[]={1,0,-1,0};
int main(){
    ios_base::sync_with_stdio(false);
    int n,m,t;
    cin>>n>>m>>t;
    for(int i=0;i<n;++i){
        for(int j=0;j<m;++j){
            char ch;
            cin>>ch;
            arr[i][j]=(ch=='1');
        }
    }
    queue<pair<int,int>>q;
    for(int i=0;i<n;++i){
        for(int j=0;j<m;++j){
            bool has_neighbour=false;
            for(int k=0;k<4;++k){
                int ii=i+di[k];
                int jj=j+dj[k];
                if(ii>=0&&ii<n&&jj>=0&&jj<m&&arr[ii][jj]==arr[i][j]){
                    has_neighbour=true;
                }
            }
            if(has_neighbour){
                q.push({i,j});
            }
            ind[i][j]=-1;
        }
    }
    if(q.empty()){
        // service queries
        for(int i=0;i<t;++i){
            int x,y;
            long long p;
            cin>>x>>y>>p;
            --x;--y;
            cout<<arr[x][y]<<'\n';
        }
    }
    else{
        q.push({-1,-1});
        int dist=0;
        while(q.size()>1){
            pair<int,int> tmp=q.front();
            q.pop();
            if(tmp.first==-1){
                ++dist;
                q.push({-1,-1});
                continue;
            }
            if(ind[tmp.first][tmp.second]!=-1){
                continue;
            }
            ind[tmp.first][tmp.second]=dist;
            for(int k=0;k<4;++k){
                int ii=tmp.first+di[k];
                int jj=tmp.second+dj[k];
                if(ii>=0&&ii<n&&jj>=0&&jj<m&&ind[ii][jj]==-1){
                    q.push({ii,jj});
                }
            }
        }
        // service queries
        for(int i=0;i<t;++i){
            int x,y;
            long long p;
            cin>>x>>y>>p;
            --x;--y;
            if(p>=ind[x][y]){
                cout<<(arr[x][y]^((p-ind[x][y])&1))<<'\n';
            }
            else{
                cout<<arr[x][y]<<'\n';
            }
        }
    }
}