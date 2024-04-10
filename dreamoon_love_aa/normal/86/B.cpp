#include<stdio.h>
#include<vector>
#include<queue>
using namespace std;
char Map[1024][1024];
bool used[1024][1024];
vector<int>S;
queue<int>Q;
int n,m,degree[1024][1024];
int To(int x,int y){return x*m+y;}
int dx[4]={1,0,-1,0};
int dy[4]={0,1,0,-1};
bool Out(int x,int y){return x<0||y<0||x>=n||y>=m;}
bool is_digit(char c){return c>='0'&&c<='9';}
int filled[10],cnt;
void Fill(vector<int>&X){
    cnt++;
    int x,y;
    int i,j,N=X.size();
    for(i=0;i<N;i++){
        x=X[i]/m;
        y=X[i]%m;
        for(j=0;j<4;j++){
            if(Out(x+dx[j],y+dy[j]))continue;
            if(Map[x+dx[j]][y+dy[j]]!='#')degree[x+dx[j]][y+dy[j]]--;
            if(is_digit(Map[x+dx[j]][y+dy[j]])){
                filled[Map[x+dx[j]][y+dy[j]]-'0']=cnt;
            }
        }
    }
    for(i=0;filled[i]==cnt;i++);
    for(j=0;j<N;j++){
        used[X[j]/m][X[j]%m]=1;
        Map[X[j]/m][X[j]%m]='0'+i;
    }
}
main(){
    int i,j,k,nx,ny;
    scanf("%d%d",&n,&m);
    for(i=0;i<n;i++)scanf("%s",Map[i]);
    for(i=0;i<n;i++){
        for(j=0;j<m;j++){
            if(Map[i][j]=='#'){
                used[i][j]=1;
                continue;
            }
            for(k=0;k<4;k++){
                int nx=i+dx[k],ny=j+dy[k];
                if(Out(nx,ny))continue;
                if(Map[nx][ny]=='#')continue;
                degree[i][j]++;
            }
            if(degree[i][j]==0)break;
        }
        if(j<m)break;
    }
    if(i<n){
        puts("-1");
    }
    else{
        for(i=0;i<n;i++){
            for(j=0;j<m;j++){
                if(used[i][j])continue;
                S.clear();
                S.push_back(To(i,j));
                if(!Out(i+1,j)&&!used[i+1][j]&&degree[i+1][j]==1)S.push_back(To(i+1,j));
                if(!Out(i,j+1)&&!used[i][j+1]&&degree[i][j+1]==1)S.push_back(To(i,j+1));
                if(S.size()==1){
                    if(!Out(i,j+1)&&!used[i][j+1]){
                        S.push_back(To(i,j+1));
                        if(!Out(i+1,j+1)&&!used[i+1][j+1]&&degree[i+1][j+1]==1)S.push_back(To(i+1,j+1));
                        if(!Out(i,j+2)&&!used[i][j+2]&&degree[i][j+2]==1)S.push_back(To(i,j+2));
                    }
                    if(S.size()==1){
                        if(!Out(i+1,j)&&!used[i+1][j]){
                            S.push_back(To(i+1,j));
                            if(!Out(i+1,j-1)&&!used[i+1][j-1]&&degree[i+1][j-1]==1)S.push_back(To(i+1,j-1));
                            if(!Out(i+1,j+1)&&!used[i+1][j+1]&&degree[i+1][j+1]==1)S.push_back(To(i+1,j+1));
                            if(!Out(i+2,j)&&!used[i+2][j]&&degree[i+2][j]==1)S.push_back(To(i+2,j));
                        }
                    }
                }
                Fill(S);
            }
        }
        for(i=0;i<n;i++)puts(Map[i]);
    }
}