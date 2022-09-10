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
int cnt[5];
const int MAX = (int)1e9;
int main(){
    int sum=0;
    DRI(n);
    REP(i,n){
        DRI(x);
        cnt[x]++;
        sum+=x;
    }
    int mi=MAX;
    cnt[0]+=1000000000;
    for(int i=0;i*3<=sum;i++){
        if((sum-i*3)%4==0){
            int j=(sum-i*3)>>2;
            if(cnt[4]>=j){
                int need=0;
                int r=i-(cnt[4]-j);
                for(int k=3;k>=0&&r;k--){
                    int tmp=min(r,cnt[k]);
                    need+=tmp*(3-k);
                    r-=tmp;
                }
                mi=min(mi,need);
            }
            else{
                int cc[5]={},need=0;
                for(int k=0;k<=4;k++)cc[k]=cnt[k];
                int r=j;
                for(int k=4;k>=0&&r;k--){
                    int tmp=min(r,cc[k]);
                    need+=tmp*(4-k);
                    cc[k]-=tmp;
                    r-=tmp;
                }
                r=i;
                for(int k=3;k>=0&&r;k--){
                    int tmp=min(r,cc[k]);
                    need+=tmp*(3-k);
                    cc[k]-=tmp;
                    r-=tmp;
                }
                mi=min(mi,need);
            }
        }
    }
    if(mi==MAX)puts("-1");
    else{
        printf("%d\n",mi);
    }
    return 0;
}