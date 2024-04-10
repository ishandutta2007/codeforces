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
const int SIZE = 2555;
int N,M,K,dd[SIZE][SIZE];
char s[SIZE];
int get(int x1,int y1,int x2,int y2){
    x1--;y1--;
    return dd[x2][y2]-dd[x2][y1]-dd[x1][y2]+dd[x1][y1];
}
long long an;
void divide(int x1,int y1,int x2,int y2){
    if(x1==x2&&y1==y2){
        if(get(x1,y1,x2,y2)==K)an++;
        return;
    }
    int ty=1;
    if(x2-x1>y2-y1)ty=0;
    if(ty==0){
        int mm=(x1+x2)>>1;
        for(int i=y1;i<=y2;i++){
            int cnt[2][7]={};
            for(int j=y2;j>=i;j--){
                for(int k=0;k<=K;k++)
                    while(cnt[0][k]<=mm-x1&&get(mm-cnt[0][k],i,mm,j)<=k)cnt[0][k]++;
                for(int k=0;k<=K;k++)
                    while(cnt[1][k]<x2-mm&&get(mm+1,i,mm+cnt[1][k]+1,j)<=k)cnt[1][k]++;
                for(int k=0;k<=K;k++)
                    an+=(cnt[0][k]-(k?cnt[0][k-1]:0))*(cnt[1][K-k]-(K-k?cnt[1][K-k-1]:0));
            }
        }
        divide(x1,y1,mm,y2);
        divide(mm+1,y1,x2,y2);
    }
    else{
        int mm=(y1+y2)>>1;
        for(int i=x1;i<=x2;i++){
            int cnt[2][7]={};
            for(int j=x2;j>=i;j--){
                for(int k=0;k<=K;k++)
                    while(cnt[0][k]<=mm-y1&&get(i,mm-cnt[0][k],j,mm)<=k)cnt[0][k]++;
                for(int k=0;k<=K;k++)
                    while(cnt[1][k]<y2-mm&&get(i,mm+1,j,mm+cnt[1][k]+1)<=k)cnt[1][k]++;
                for(int k=0;k<=K;k++)
                    an+=(cnt[0][k]-(k?cnt[0][k-1]:0))*(cnt[1][K-k]-(K-k?cnt[1][K-k-1]:0));
            }
        }
        divide(x1,y1,x2,mm);
        divide(x1,mm+1,x2,y2);
    }
}
int main(){
    RIII(N,M,K);
    for(int i=1;i<=N;i++){
        RS(s+1);
        for(int j=1;j<=M;j++)
            dd[i][j]=dd[i][j-1]+dd[i-1][j]-dd[i-1][j-1]+s[j]-'0';
    }
    divide(1,1,N,M);
    cout<<an<<endl;
    return 0;
}