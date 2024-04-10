#include<bits/stdc++.h>
using namespace std;

int n,m,k;
int a[1000][1000];
int dx[]={-1,0,1,0};
int dy[]={0,1,0,-1};
vector<pair<int,int> > col[40];
int d[40][1000][1000];

void precalc(int cc){
    queue<pair<int,int> > q;
    for(pair<int,int> p:col[cc]){
        q.push(p);
        d[cc][p.first][p.second]=0;
    }
    bool u[40];
    memset(u,0,sizeof(u));
    while(!q.empty()){
        int x=q.front().first;
        int y=q.front().second;
        q.pop();
        if(!u[a[x][y]]){
            u[a[x][y]]=true;
            for(pair<int,int> p:col[a[x][y]]){
                if(d[cc][p.first][p.second]>d[cc][x][y]+1){
                    d[cc][p.first][p.second]=d[cc][x][y]+1;
                    q.push(p);
                }
            }
        }
        for(int i=0;i<4;i++){
            int nx=x+dx[i];
            int ny=y+dy[i];
            if(nx>=0&&ny>=0&&nx<n&&ny<m&&d[cc][nx][ny]>d[cc][x][y]+1){
                d[cc][nx][ny]=d[cc][x][y]+1;
                q.push(make_pair(nx,ny));
            }
        }
    }
}

int q;

int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin>>n>>m>>k;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>a[i][j];
            a[i][j]--;
            col[a[i][j]].push_back(make_pair(i,j));
        }
    }
    memset(d,0x3f,sizeof(d));
    for(int i=0;i<k;i++){
        precalc(i);
    }
    cin>>q;
    while(q--){
        int r1,c1,r2,c2;
        cin>>r1>>c1>>r2>>c2;
        r1--;c1--;r2--;c2--;
        int ans=abs(r2-r1)+abs(c2-c1);
        for(int i=0;i<k;i++){
            ans=min(d[i][r1][c1]+1+d[i][r2][c2],ans);
        }
        cout<<ans<<endl;
    }

    return 0;
}