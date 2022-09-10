#include <bits/stdc++.h>
#define SZ(X) ((int)(X).size())
#define ALL(X) (X).begin(), (X).end()
#define REP(I, N) for (int I = 0; I < (N); ++I)
#define REPP(I, A, B) for (int I = (A); I < (B); ++I)
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
#define PII pair<int,int>
#define VI vector<int>
#define VPII vector<pair<int,int> >
#define PLL pair<long long,long long>
#define VPLL vector<pair<long long,long long> >
#define F first
#define S second
typedef long long LL;
using namespace std;
const int MOD = 1e9+7;
const int SIZE = 1e6+10;
int v[SIZE],d[SIZE],p[SIZE];
int n;
void cry(int id){
    int now=d[id];
    VI cer;
    REPP(i,id+1,n){
        if(p[i]>=0){
            p[i]-=now;
            if(p[i]<0)cer.PB(i);
        }
    }
    REP(i,SZ(cer))cry(cer[i]);
}
void cure(int id){
    int now=v[id];
    VI cer;
    REPP(i,id+1,n){
        if(p[i]>=0){
            p[i]-=now--;
            if(p[i]<0)cer.PB(i);
        }
        if(now<=0)break;
    }
    REP(i,SZ(cer))cry(cer[i]);
}
int main(){
    RI(n);
    REP(i,n)RIII(v[i],d[i],p[i]);
    int an=0;
    VI res;
    REP(i,n){
        if(p[i]<0)continue;
        an++;
        res.PB(i+1);
        cure(i);
    }
    cout<<an<<endl;
    REP(i,SZ(res))printf("%d ",res[i]);
    return 0;
}