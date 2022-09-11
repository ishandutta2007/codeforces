#include<stdio.h>
#define SIZE 2001
bool used[SIZE][SIZE];
struct data{
    int x,y;
    void scan(){scanf("%d%d",&x,&y);}
}bfs[SIZE*SIZE];
int dx[4]={1,0,-1,0};
int dy[4]={0,1,0,-1};
int n,m;
bool Out(int x,int y){
    if(x<=0||y<=0||x>n||y>m)return 1;
    return 0;
}
main(){
    int K,i,j,k;
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    scanf("%d%d",&n,&m);
    scanf("%d",&K);
    for(j=0;j<K;j++){
        bfs[j].scan();
        used[bfs[j].x][bfs[j].y]=1;
    }
    for(i=0;i<j;i++){
        for(k=0;k<4;k++){
            if(Out(bfs[i].x+dx[k],bfs[i].y+dy[k]))continue;
            if(used[bfs[i].x+dx[k]][bfs[i].y+dy[k]])continue;
            used[bfs[i].x+dx[k]][bfs[i].y+dy[k]]=1;
            bfs[j++]=(data){bfs[i].x+dx[k],bfs[i].y+dy[k]};
        }
    }
    i--;
    printf("%d %d\n",bfs[i].x,bfs[i].y);
}