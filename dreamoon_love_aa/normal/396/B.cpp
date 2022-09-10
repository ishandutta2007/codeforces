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
bitset<100000>p;
vector<int>pp;
bool prime(int x){
    if(x==2)return true;
    if(!(x&1))return false;
    for(int i=0;pp[i]*pp[i]<=x;i++){
        if(x%pp[i]==0)return false;
    }
    return true;
}
int main(){
    for(int i=2;i<100000;i++){
        if(!p[i]){
            pp.PB(i);
            for(int j=i+i;j<100000;j+=i)p[j]=1;
        }
    }
    CASET{
        DRI(n);
        long long now=n,nxt=n+1;
        while(!prime(now))now--;
        while(!prime(nxt))nxt++;
        long long p=now*nxt+2*(n-now-nxt+1),q=2*now*nxt;
        long long np=p,nq=q;
        long long gg=__gcd(np,nq);
        p=np/gg;
        q=nq/gg;

        cout<<p<<"/"<<q<<endl;
    }

    return 0;
}