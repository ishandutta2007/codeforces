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
const int SIZE = 1e6+10;
map<int,int>A,B;
int an[SIZE],d[SIZE],n,a,b;
void NO(){puts("NO");exit(0);}
void grab(int id){
    an[id]=1;
    int you=a-d[id];
    if(you!=d[id]&&A.count(you)){
        B[you]=A[you];
        A.erase(you);
        grab(B[you]);
    }
    int nxt=b-d[id];
    if(!B.count(nxt)){
        if(A.count(nxt)){
            B[nxt]=A[nxt];
            A.erase(nxt);
            grab(B[nxt]);
        }
        else NO();
    }
}
int main(){
    RIII(n,a,b);
    REP(i,n){
        RI(d[i]);
        A[d[i]]=i;
    }
    REP(i,n){
        if(!an[i]){
            if(!A.count(a-d[i])){
                A.erase(d[i]);
                B[d[i]]=i;
                grab(i);
            }
        }
    }
    puts("YES");
    REP(i,n)printf("%d ",an[i]);
    return 0;
}