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
#define SIZE 100010
long long n,l,r,Ql,Qr,w[SIZE];
long long f(int x){
    if(x>0)return (x-1)*Ql;
    if(x<0)return (-x-1)*Qr;
    return 0;
}
int main(){
    cin>>n>>l>>r;
    cin>>Ql>>Qr;
    long long sum=0;
    REP(i,n){
        cin>>w[i];
        sum+=w[i];
    }
    long long an=sum*r+(n-1)*Qr;
    long long now=0;
    int cnt=0;
    REP(i,n){
        cnt++;
        now+=w[i];
        an=min(an,now*l+(sum-now)*r+f(cnt-(n-cnt)));
    }
    cout<<an<<endl;
    return 0;
}