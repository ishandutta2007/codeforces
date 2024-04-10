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
int n,m,r,a[555][555];
int w[555],dif[1010],row[555][555],cc[555][555];
int ma_fr[555][555],ma_fr_cnt[555][555];
int ma_fl[555][555],ma_fl_cnt[555][555];
int get_row(int rr,int L,int R){
    return row[rr][R]-row[rr][L-1];
}
int main(){
    RIII(n,m,r);
    REPP(i,1,n+1)REPP(j,1,m+1)RI(a[i][j]);
    swap(n,m);
    REPP(i,1,501)REPP(j,i,501)swap(a[i][j],a[j][i]);
    REPP(i,1,n+1)REPP(j,1,m+1)row[i][j]=row[i][j-1]+a[i][j];
    if(1+r>min(n,m)-r){
        puts("0 0");
        return 0;
    }
    for(int i=0;i<=r;i++){
        int j=0;
        while((j+1)*(j+1)+i*i<=r*r)j++;
        w[i]=j;
    }
    REP(i,2*r+1){
        int ma=0;
        for(int j=0;j<=r;j++){
            if(j<i-r)continue;
            ma=max(ma,w[j]+1+w[abs(i-j)]);
        }
        dif[i]=ma;
    }
    for(int i=1+r;i<=n-r;i++){
        for(int j=1+r;j<=m-r;j++){
            for(int k=-r;k<=r;k++){
                cc[i][j]+=get_row(i+k,j-w[abs(k)],j+w[abs(k)]);
            }
            if(cc[i][j]>ma_fl[i][j-1]){
                ma_fl[i][j]=cc[i][j];
                ma_fl_cnt[i][j]=1;
            }
            else if(cc[i][j]==ma_fl[i][j-1]){
                ma_fl[i][j]=cc[i][j];
                ma_fl_cnt[i][j]=ma_fl_cnt[i][j-1]+1;
            }
            else{
                ma_fl[i][j]=ma_fl[i][j-1];
                ma_fl_cnt[i][j]=ma_fl_cnt[i][j-1];
            }
        }
        for(int j=m-r;j>=1+r;j--){
            if(cc[i][j]>ma_fr[i][j+1]){
                ma_fr[i][j]=cc[i][j];
                ma_fr_cnt[i][j]=1;
            }
            else if(cc[i][j]==ma_fr[i][j+1]){
                ma_fr[i][j]=cc[i][j];
                ma_fr_cnt[i][j]=ma_fr_cnt[i][j+1]+1;
            }
            else{
                ma_fr[i][j]=ma_fr[i][j+1];
                ma_fr_cnt[i][j]=ma_fr_cnt[i][j+1];
            }
        }
    }
    /*for(int i=1+r;i<=n-r;i++){
        for(int j=1+r;j<=m-r;j++){
            printf("l:(%d,%d) r:(%d,%d)   ",ma_fl[i][j],ma_fl_cnt[i][j],ma_fr[i][j],ma_fr_cnt[i][j]);
        }
        puts("");
    }*/
    int an1=0;
    long long an2=0;
    for(int i=1+r;i<=n-r;i++)
        for(int j=1+r;j<=m-r;j++){
            for(int k=1+r;k<=n-r;k++){
                if(abs(i-k)>2*r){
                    int now=cc[i][j]+ma_fr[k][1+r];
                    if(now>an1){
                        an1=now;
                        an2=ma_fr_cnt[k][1+r];
                    }
                    else if(now==an1){
                        an2+=ma_fr_cnt[k][1+r];
                    }
                }
                else{
                    int dd=abs(i-k);
                    int ny=j+dif[dd];
                    if(ny<=m-r){
                        int now=cc[i][j]+ma_fr[k][ny];
                        if(now>an1){
                            an1=now;
                            an2=ma_fr_cnt[k][ny];
                        }
                        else if(now==an1){
                            an2+=ma_fr_cnt[k][ny];
                        }
                    }
                    ny=j-dif[dd];
                    if(ny>=1+r){
                        int now=cc[i][j]+ma_fl[k][ny];
                        if(now>an1){
                            an1=now;
                            an2=ma_fl_cnt[k][ny];
                        }
                        else if(now==an1){
                            an2+=ma_fl_cnt[k][ny];
                        }
                    }
                }
            }
        }
    printf("%d %I64d\n",an1,an2/2);
    return 0;
}