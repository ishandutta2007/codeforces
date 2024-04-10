#include <bits/stdc++.h>

using namespace std;

const int N=100;
int n,m;
int nr_12;
int nr_21;
int nr_22;
int v[N+5][N+5],sol[N+5][N+5];
int y=0;

bool valid(int r,int c){
    if(1<=r && 1<=c && r<=n && c<=m && v[r][c]==-1)
        return 1;
    return 0;
}

bool valid2(int r,int c){
    if(1<=r && 1<=c && r<=n && c<=m)
        return 1;
    return 0;
}

int dr[]={-1,0,1,0};
int dc[]={0,1,0,-1};
bool viz[N+5][N+5];

void color(int r,int c){

    memset(viz,0,sizeof(viz));
    queue< pair<int,int> >q;
    q.push(make_pair(r,c));
    viz[r][c]=1;

    bool ap[100];
    memset(ap,0,sizeof(ap));

    while(!q.empty()){
        int rx=q.front().first;
        int cx=q.front().second;
        q.pop();
        for(int i=0;i<4;i++){
            int rn=rx+dr[i];
            int cn=cx+dc[i];
            if(valid2(rn,cn)==1){
                if(v[rn][cn]==v[r][c]){
                    if(viz[rn][cn]==0){
                        q.push(make_pair(rn,cn));
                        viz[rn][cn]=1;
                    }
                }
                else{
                    if(sol[rn][cn]!=-1)
                        ap[sol[rn][cn]]=1;
                }
            }
        }
    }

    int val=-1;
    for(int i=0;i<26;i++){
        if(ap[i]==0){
            val=i;
            break;
        }
    }

    memset(viz,0,sizeof(viz));
    q.push(make_pair(r,c));
    viz[r][c]=1;
    sol[r][c]=val;
    while(!q.empty()){
        int rx=q.front().first;
        int cx=q.front().second;
        q.pop();
        for(int i=0;i<4;i++){
            int rn=rx+dr[i];
            int cn=cx+dc[i];
            if(valid2(rn,cn)==1 && v[rn][cn]==v[r][c] && viz[rn][cn]==0){
                viz[rn][cn]=1;
                sol[rn][cn]=val;
            }
        }
    }

}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>n>>m>>nr_12>>nr_21>>nr_22;
    if(n%2==1 && m%2==1){
        puts("IMPOSSIBLE");
        return 0;
    }
    if(nr_12*2+nr_21*2+nr_22*4<n*m){
        puts("IMPOSSIBLE");
        return 0;
    }
    memset(v,-1,sizeof(v));
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(nr_22>=1 && valid(i,j)==1 && valid(i,j+1)==1 && valid(i+1,j)==1 && valid(i+1,j+1)==1){
                nr_22--;
                y++;
                v[i][j]=v[i][j+1]=v[i+1][j]=v[i+1][j+1]=y;
            }
        }
    }
    if(m%2==1){
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(nr_12>=2 && valid(i,j)==1 && valid(i,j+1)==1 && valid(i+1,j)==1 && valid(i+1,j+1)==1){
                    nr_12-=2;
                    y++;
                    v[i][j]=v[i][j+1]=y;
                    y++;
                    v[i+1][j]=v[i+1][j+1]=y;
                }
            }
        }
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(nr_21>=2 && valid(i,j)==1 && valid(i,j+1)==1 && valid(i+1,j)==1 && valid(i+1,j+1)==1){
                    nr_21-=2;
                    y++;
                    v[i][j]=v[i+1][j]=y;
                    y++;
                    v[i][j+1]=v[i+1][j+1]=y;
                }
            }
        }
    }
    else{
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(nr_21>=2 && valid(i,j)==1 && valid(i,j+1)==1 && valid(i+1,j)==1 && valid(i+1,j+1)==1){
                    nr_21-=2;
                    y++;
                    v[i][j]=v[i+1][j]=y;
                    y++;
                    v[i][j+1]=v[i+1][j+1]=y;
                }
            }
        }
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(nr_12>=2 && valid(i,j)==1 && valid(i,j+1)==1 && valid(i+1,j)==1 && valid(i+1,j+1)==1){
                    nr_12-=2;
                    y++;
                    v[i][j]=v[i][j+1]=y;
                    y++;
                    v[i+1][j]=v[i+1][j+1]=y;
                }
            }
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(nr_12>=1 && valid(i,j)==1 && valid(i,j+1)==1){
                nr_12--;
                y++;
                v[i][j]=v[i][j+1]=y;
            }
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(nr_21>=1 && valid(i,j)==1 && valid(i+1,j)==1){
                nr_21--;
                y++;
                v[i][j]=v[i+1][j]=y;
            }
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(v[i][j]==-1){
                puts("IMPOSSIBLE");
                return 0;
            }
        }
    }
    memset(sol,-1,sizeof(sol));
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(sol[i][j]!=-1)
                continue;
            color(i,j);
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            cout<<char(sol[i][j]+'a');
           /// cout<<sol[i][j]<<" ";
        }
        cout<<"\n";
    }
    return 0;
}