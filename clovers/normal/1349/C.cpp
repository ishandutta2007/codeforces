#include<bits/stdc++.h>
using namespace std;
const int N=1001;
int n,m,T;
char s[N][N];
int dx[]={0,1,-1,0};
int dy[]={1,0,0,-1};
int idx(int x,int y){
    return (x-1)*m+y;
}
int dis[N*N];
queue<int> q;
void init(){
    memset(dis,0x3f,sizeof(dis));
    scanf("%d%d%d",&n,&m,&T);
    for(int i=1;i<=n;i++) scanf("%s",s[i]+1);
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            for(int k=0;k<4;k++){
                int x=i+dx[k],y=j+dy[k];
                if(x<1||y<1||x>n||y>m) continue;
                if(s[i][j]==s[x][y]){
                    q.push(idx(i,j));
                    dis[idx(i,j)]=1;
               }
            }
        }
    }
    while(!q.empty()){
        int u=q.front();
        q.pop();
        for(int k=0;k<4;k++){
            int x=(u%m==0 ? u/m : u/m+1)+dx[k],y=(u%m ==0 ? m : u%m)+dy[k];
            if(x<1||y<1||x>n||y>m||dis[idx(x,y)]<n+m) continue;
            dis[idx(x,y)]=dis[u]+1; q.push(idx(x,y));
        }
    }
}

void solve(){
    while(T--){
        int x,y; long long p;
        scanf("%d%d%lld",&x,&y,&p);
        if(s[x][y]=='0'){
            p-=dis[idx(x,y)];
            if(p<0||dis[idx(x,y)]>n+m) puts("0");
            else{
                if(p%2==0) puts("1");
                else puts("0");
            }
        }
        else{
            p-=dis[idx(x,y)];
            if(p<0||dis[idx(x,y)]>n+m) puts("1");
            else{
                if(p%2==0) puts("0");
                else puts("1");
            }
        }
    }
}

int main(){
    init();
    solve();
    return 0;
}