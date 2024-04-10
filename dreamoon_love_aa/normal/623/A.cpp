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
const int SIZE = 1e3+10;
int e[SIZE][SIZE];
char used[SIZE];
bool fill(int x,int v,int n){
    used[x]=v+'a';
    REPP(i,1,n+1){
        if(i==x)continue;
        if(!e[i][x]){
            if(used[i]){
                if(used[i]==used[x])return 0;
            }
            else{
                if(!fill(i,2-v,n))return 0;
            }
        }
    }
    return 1;
}
int main(){
    DRII(n,m);
    REP(i,m){
        DRII(x,y);
        e[x][y]=e[y][x]=1;
    }
    REPP(i,1,n+1){
        if(used[i])continue;
        bool r=0;
        REPP(j,1,n+1){
            if(i==j)continue;
            if(!e[i][j])r=1;
        }
        if(!r)used[i]='b';
        else{
            if(!fill(i,0,n))return 0*puts("No");
        }
    }
    REPP(i,1,n+1)REPP(j,1,i){
        if((abs(used[i]-used[j])<=1)!=e[i][j])
            return 0*puts("No");
    }
    puts("Yes");
    puts(used+1);
    return 0;
}