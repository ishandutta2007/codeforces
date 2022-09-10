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
void mk(char str[],int nt[][26],int n){
    REP(i,n){
        REPP(j,i+1,n+1){
            if(nt[i][str[j]-'A']==0)nt[i][str[j]-'A']=j;
        }
    }
}
char s[2][110],virus[110];
int nxt[2][110][26],len[2],back[110][26],vn;
void pre(){
    char tmp[110];
    REP(i,vn){
        tmp[i]=virus[i];
        REP(j,26){
            tmp[i+1]='A'+j;
            for(int k=i+1;k>0;k--){
                if(strncmp(virus+1,tmp+i+2-k,k)==0){
                    back[i][j]=k;
                    break;
                }
            }
        }
    }
}
int dp[110][110][110],last[110][110][110],use[110][110][110];
void print(int x,int y,int z){
    if(x==0&&y==0&&z==0)return;
    int ker=last[x][y][z];
    print(ker>>14,(ker>>7)&127,ker&127);
    printf("%c",use[x][y][z]+'A');
}
struct data{
    int x,y,z,v;
    data(int _x=0,int _y=0,int _z=0,int _v=0):x(_x),y(_y),z(_z),v(_v){}
}bfs[1100000];
int main(){
    int an=0;
    RS(s[0]+1);
    RS(s[1]+1);
    REP(i,2)len[i]=LEN(s[i]+1);
    RS(virus+1);
    vn=LEN(virus+1);
    REP(i,2)mk(s[i],nxt[i],len[i]);
    pre();
    bfs[0]=data(0,0,0,0);
    int ma=0,id=0;
    MS1(dp);
    dp[0][0][0]=0;
    REP(i,len[0]+1)
        REP(j,len[1]+1)
            REP(r,vn){
                if(dp[i][j][r]==-1)continue;
                REP(k,26){
                    int nx=nxt[0][i][k];
                    int ny=nxt[1][j][k];
                    if(!nx||!ny)continue;
                    int nz=back[r][k];
                    if(nz==vn)continue;
                    if(dp[i][j][r]+1>dp[nx][ny][nz]){
                        use[nx][ny][nz]=k;
                        dp[nx][ny][nz]=dp[i][j][r]+1;
                        last[nx][ny][nz]=(i<<14)|(j<<7)|r;
                        if(dp[nx][ny][nz]>ma){
                            ma=dp[nx][ny][nz];
                            id=(nx<<14)|(ny<<7)|nz;
                        }
                    }
                }
            }
    if(ma==0)puts("0");
    else print(id>>14,(id>>7)&127,id&127);
    return 0;
}