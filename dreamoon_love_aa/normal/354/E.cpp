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
int fs[43][2],d[20],dp[20][10],r[20][10],from[20][10];
vector<int>pos;
int main(){
    MS1(fs);
    for(int i=0;i<=6;i++)
        for(int j=0;i+j<=6;j++){
            fs[i*7+j*4][0]=i;
            fs[i*7+j*4][1]=j;
        }
    for(int i=0;i<=42;i++){
        if(fs[i][0]!=-1)pos.PB(i);
    }
    CASET{
        long long n;
        cin>>n;
        for(int i=0;i<20;i++){
            d[i]=n%10;
            n/=10;
        }
        MS1(dp);
        MS0(r);
        dp[0][0]=0;
        for(int i=0;i<19;i++){
            for(int j=0;j<10;j++){
                if(dp[i][j]!=-1){
                    for(int k=0;k<SZ(pos);k++){
                        if(pos[k]%10==(d[i]-j+100)%10){
                            dp[i+1][(j+pos[k])/10]=k;
                            from[i+1][(j+pos[k])/10]=j;
                        }
                    }
                }
            }
        }
        if(dp[19][0]!=-1){
            int x=19,y=0;
            while(x){
                int v=pos[dp[x][y]];
                int cnt=0;
                for(int i=0;i<fs[v][0];i++)r[x-1][cnt++]=7;
                for(int i=0;i<fs[v][1];i++)r[x-1][cnt++]=4;
                y=from[x][y];
                x--;
            }
            for(int i=0;i<6;i++){
                long long tmp=0;
                for(int j=18;j>=0;j--)tmp=tmp*10+r[j][i];
                if(i)printf(" ");
                cout<<tmp;
            }
            puts("");
        }
        else puts("-1");
    }
    return 0;
}