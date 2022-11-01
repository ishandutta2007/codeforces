#include<bits/stdc++.h>
using namespace std;
//Copying rng_58's code by hand

int X,Y,D,R;
int x[305],y[305];
char board[1005][1005];
int filled[1005][1005];

queue<int> q;
int dx[]={-1,0,1,0};
int dy[]={0,1,0,-1};
bool used[20][20];

vector<pair<int,int> > neighbor(int sx,int sy){
    vector<pair<int,int> > ans;
    for(int i=10-D;i<=10+D;i++){
        for(int j=10-D;j<=10+D;j++){
            used[i][j]=false;
        }
    }
    q.push(sx);
    q.push(sy);
    q.push(0);
    used[10][10]=true;
    while(!q.empty()){
        int x=q.front();q.pop();
        int y=q.front();q.pop();
        int d=q.front();q.pop();
        ans.push_back(make_pair(x,y));
        if(d+1<=D){
            for(int i=0;i<4;i++){
                int nx=x+dx[i];
                int ny=y+dy[i];
                if(board[nx][ny]!='X'&&!used[nx-sx+10][ny-sy+10]){
                    q.push(nx);
                    q.push(ny);
                    q.push(d+1);
                    used[nx-sx+10][ny-sy+10]=true;
                }
            }
        }
    }
    return ans;
}

void fill_neighbor(int sx,int sy,int val){
    for(int i=10-D;i<=10+D;i++){
        for(int j=10-D;j<=10+D;j++){
            used[i][j]=false;
        }
    }
    q.push(sx);
    q.push(sy);
    q.push(0);
    used[10][10]=true;
    while(!q.empty()){
        int x=q.front();q.pop();
        int y=q.front();q.pop();
        int d=q.front();q.pop();
        filled[x][y]+=val;
        if(d+1<=D){
            for(int i=0;i<4;i++){
                int nx=x+dx[i];
                int ny=y+dy[i];
                if(board[nx][ny]!='X'&&!used[nx-sx+10][ny-sy+10]){
                    q.push(nx);
                    q.push(ny);
                    q.push(d+1);
                    used[nx-sx+10][ny-sy+10]=true;
                }
            }
        }
    }
}

bool check(){
    for(int i=0;i<R;i++)if(filled[x[i]][y[i]]==0)return false;
    return true;
}

bool func1(int px,int py){
    vector<pair<int,int> > v=neighbor(px,py);
    for(int i=0;i<v.size();i++){
        filled[v[i].first][v[i].second]++;
    }
    int i,j,k;
    for(i=0;i<R;i++){
        if(filled[x[i]][y[i]]==0)break;
    }
    if(i==R){
        for(j=0;j<X;j++){
            for(k=0;k<Y;k++){
                if(board[j][k]!='X'&&(j!=px||k!=py)){
                    cout<<px+1<<' '<<py+1<<' '<<j+1<<' '<<k+1<<endl;
                    return true;
                }
            }
        }
    }
    vector<pair<int,int> > w=neighbor(x[i],y[i]);
    for(i=0;i<w.size();i++){
        int qx=w[i].first,qy=w[i].second;
        fill_neighbor(qx,qy,1);
        if(check()){
            cout<<px+1<<' '<<py+1<<' '<<qx+1<<' '<<qy+1<<endl;
            return true;
        }
        fill_neighbor(qx,qy,-1);
    }
    for(i=0;i<v.size();i++)filled[v[i].first][v[i].second]--;
    return false;
}

int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);

    cin>>X>>Y>>D;
    for(int i=0;i<X;i++)cin>>board[i];
    for(int i=0;i<X;i++){
        for(int j=0;j<Y;j++){
            if(board[i][j]=='R'){
                if(R>300){
                    cout<<-1<<endl;
                    return 0;
                }
                x[R]=i;y[R]=j;R++;
            }
        }
    }

    vector<pair<int,int> > v=neighbor(x[0],y[0]);
    for(int i=0;i<v.size();i++){
        if(func1(v[i].first,v[i].second)){
            return 0;
        }
    }
    cout<<-1<<endl;

    return 0;
}