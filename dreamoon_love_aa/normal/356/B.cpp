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
#define SIZE 1000010
long long n,m,lx,ly;
char x[SIZE],y[SIZE];
int cnt[2][SIZE][26];
int main(){
    cin>>n>>m;
    RS(x);
    RS(y);
    lx=LEN(x);
    ly=LEN(y);
    long long gg=__gcd(lx,ly);
    long long k=n/(ly/gg);
    for(int i=0;i<lx;i++){
        cnt[0][i%gg][x[i]-'a']++;
    }
    for(int i=0;i<ly;i++){
        cnt[1][i%gg][y[i]-'a']++;
    }
    long long res=lx/gg*ly;
    for(int i=0;i<gg;i++){
        REP(j,26)res-=(long long)cnt[0][i][j]*cnt[1][i][j];
    }
    cout<<res*k<<endl;
    return 0;
}