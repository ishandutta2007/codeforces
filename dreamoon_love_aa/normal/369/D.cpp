#include<stdio.h>
#include<string>
#include<math.h>
#include<stdlib.h>
#include<set>
#include<bitset>
#include<map>
#include<vector>
#include<string.h>
#include<algorithm>
#include<iostream>
#include<queue>
#define SZ(X) ((int)(X).size())
#define ALL(X) (X).begin(), (X).end()
#define REP(I, N) for (int I = 0; I < (N); ++I)
#define REPP(I, A, B) for (int I = (A); I < (B); ++I)
#define REPC(I, C) for (int I = 0; !(C); ++I)
#define RI(X) scanf("%d", &(X))
#define RII(X, Y) scanf("%d%d", &(X), &(Y))
#define RIII(X, Y, Z) scanf("%d%d%d", &(X), &(Y), &(Z))
#define DRI(X) int (X); scanf("%d", &X)
#define DRII(X, Y) int X, Y; scanf("%d%d", &X, &Y)
#define DRIII(X, Y, Z) int X, Y, Z; scanf("%d%d%d", &X, &Y, &Z)
#define RS(X) scanf("%s", (X))
#define CASET int ___T, case_n = 1; scanf("%d ", &___T); while (___T-- > 0)
#define MP make_pair
#define PB push_back
#define MS0(X) memset((X), 0, sizeof((X)))
#define MS1(X) memset((X), -1, sizeof((X)))
#define LEN(X) strlen(X)
#define F first
#define S second
using namespace std;
const int SIZE = 3010;
int a[SIZE],two[SIZE],back[SIZE],n,K;
bool used[SIZE][SIZE][2];
struct data{
    int x,y,step,stop;
    data(int _x=0,int _y=0,int _step=0,int _stop=0):x(_x),y(_y),step(_step),stop(_stop){}
}bfs[SIZE*SIZE];
int nxt(int x){
    if(x>n)return 0;
    return x;
}
int main(){
    RII(n,K);
    REPP(i,1,n+1){
        DRI(x);
        if(x==100)a[i]=2;
        else if(x)a[i]=1;
    }
    if(n==1){
        puts("1");
        return 0;
    }
    for(int i=n;i>0;i--){
        back[i]=back[i+1];
        back[i]=max(a[i],back[i+1]);
    }
    bfs[0]=data(1,2,0,0);
    used[1][2][0]=true;
    int an=0;
    for(int i=0,j=1;i<j;i++){
        int x=bfs[i].x;
        int y=bfs[i].y;
        if(bfs[i].step==K||y==0){
            ;
        }
        else{
            int ff=back[y];
            int ss=a[x];
            if(ff==2&&ss==2){
                bfs[j]=data(nxt(y+1),nxt(y+2),bfs[i].step+1,bfs[i].stop);
                if(!used[bfs[j].x][bfs[j].y][bfs[j].stop]){
                    used[bfs[j].x][bfs[j].y][bfs[j].stop]=true;
                    j++;
                }
            }
            else if(ff==2&&ss==1){
                bfs[j]=data(nxt(y),nxt(y+1),bfs[i].step+1,bfs[i].stop);
                if(!used[bfs[j].x][bfs[j].y][bfs[j].stop]){
                    used[bfs[j].x][bfs[j].y][bfs[j].stop]=true;
                    j++;
                }
                bfs[j]=data(nxt(y+1),nxt(y+2),bfs[i].step+1,bfs[i].stop);
                if(!used[bfs[j].x][bfs[j].y][bfs[j].stop]){
                    used[bfs[j].x][bfs[j].y][bfs[j].stop]=true;
                    j++;
                }
            }
            else if(ff==2&&ss==0){
                bfs[j]=data(nxt(y),nxt(y+1),bfs[i].step+1,bfs[i].stop);
                if(!used[bfs[j].x][bfs[j].y][bfs[j].stop]){
                    used[bfs[j].x][bfs[j].y][bfs[j].stop]=true;
                    j++;
                }
            }
            else if(ff==1&&ss==2){
                bfs[j]=data(nxt(x),nxt(y+1),bfs[i].step+1,bfs[i].stop);
                if(!used[bfs[j].x][bfs[j].y][bfs[j].stop]){
                    used[bfs[j].x][bfs[j].y][bfs[j].stop]=true;
                    j++;
                }
                bfs[j]=data(nxt(y+1),nxt(y+2),bfs[i].step+1,bfs[i].stop);
                if(!used[bfs[j].x][bfs[j].y][bfs[j].stop]){
                    used[bfs[j].x][bfs[j].y][bfs[j].stop]=true;
                    j++;
                }
            }
            else if(ff==1&&ss==1){
                bfs[j]=data(x,y,bfs[i].step+1,1);
                if(!used[bfs[j].x][bfs[j].y][bfs[j].stop]){
                    used[bfs[j].x][bfs[j].y][bfs[j].stop]=true;
                    j++;
                }
                bfs[j]=data(x,nxt(y+1),bfs[i].step+1,bfs[i].stop);
                if(!used[bfs[j].x][bfs[j].y][bfs[j].stop]){
                    used[bfs[j].x][bfs[j].y][bfs[j].stop]=true;
                    j++;
                }
                bfs[j]=data(y,nxt(y+1),bfs[i].step+1,bfs[i].stop);
                if(!used[bfs[j].x][bfs[j].y][bfs[j].stop]){
                    used[bfs[j].x][bfs[j].y][bfs[j].stop]=true;
                    j++;
                }
                bfs[j]=data(nxt(y+1),nxt(y+2),bfs[i].step+1,bfs[i].stop);
                if(!used[bfs[j].x][bfs[j].y][bfs[j].stop]){
                    used[bfs[j].x][bfs[j].y][bfs[j].stop]=true;
                    j++;
                }
            }
            else if(ff==1&&ss==0){
                bfs[j]=data(x,y,bfs[i].step+1,1);
                if(!used[bfs[j].x][bfs[j].y][bfs[j].stop]){
                    used[bfs[j].x][bfs[j].y][bfs[j].stop]=true;
                    j++;
                }
                bfs[j]=data(y,nxt(y+1),bfs[i].step+1,bfs[i].stop);
                if(!used[bfs[j].x][bfs[j].y][bfs[j].stop]){
                    used[bfs[j].x][bfs[j].y][bfs[j].stop]=true;
                    j++;
                }
            }
            else if(ff==0&&ss==2){
                bfs[j]=data(x,nxt(y+1),bfs[i].step+1,bfs[i].stop);
                if(!used[bfs[j].x][bfs[j].y][bfs[j].stop]){
                    used[bfs[j].x][bfs[j].y][bfs[j].stop]=true;
                    j++;
                }
            }
            else if(ff==0&&ss==1){
                bfs[j]=data(x,y,bfs[i].step+1,1);
                if(!used[bfs[j].x][bfs[j].y][bfs[j].stop]){
                    used[bfs[j].x][bfs[j].y][bfs[j].stop]=true;
                    j++;
                }
                bfs[j]=data(x,nxt(y+1),bfs[i].step+1,bfs[i].stop);
                if(!used[bfs[j].x][bfs[j].y][bfs[j].stop]){
                    used[bfs[j].x][bfs[j].y][bfs[j].stop]=true;
                    j++;
                }
            }
            else if(ff==0&&ss==0){
                bfs[j]=data(x,y,bfs[i].step+1,1);
                if(!used[bfs[j].x][bfs[j].y][bfs[j].stop]){
                    used[bfs[j].x][bfs[j].y][bfs[j].stop]=true;
                    j++;
                }
            }
        }
    }
    an=0;
    for(int i=0;i<=n;i++)
        for(int j=0;j<=n;j++){
            if(used[i][j][0]||used[i][j][1])an++;
        }
    printf("%d\n",an);
    return 0;
}