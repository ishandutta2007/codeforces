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
const int SIZE = 5001;
char s[SIZE];
int d[SIZE][SIZE],cnt[SIZE];
int main(){
    DRII(n,m);
    REP(i,n){
        RS(s);
        for(int j=0,k;j<m;j=k){
            if(s[j]=='0')k=j+1;
            else{
                for(k=j+1;k<m&&s[k]=='1';k++);
                d[j][k-1]++;
            }
        }
    }
    int an=0;
    for(int i=0;i<m;i++){
        int sum=0;
        for(int j=m-1;j>=i;j--){
            cnt[j]+=d[i][j];
            sum+=cnt[j];
            an=max(an,sum*(j-i+1));
        }
    }
    printf("%d\n",an);
    return 0;
}