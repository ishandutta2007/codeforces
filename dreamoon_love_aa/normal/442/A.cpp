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
#define F first
#define S second
typedef long long LL;
using namespace std;
char cc[10]="RGBYW";
int d[5][5];
int cnt(int x){
    int res=0;
    while(x){
        res+=x&1;
        x>>=1;
    }
    return res;
}
int main(){
    DRI(n);
    REP(i,n){
        char s[10];
        RS(s);
        int x,y;
        REP(j,5){
            if(s[0]==cc[j])
            {
                x=j;
                break;
            }
        }
        y=s[1]-'1';
        d[x][y]++;
    }
    int an=10;
    REP(i,32)
        REP(j,32){
            int ha[6][6]={};
            REP(k1,5)REP(k2,5){
                if(d[k1][k2]){
                    if(((i>>k1)&1)&&((j>>k2)&1)){
                        ha[k1+1][k2+1]++;
                    }
                    else if(((i>>k1)&1)&&((j>>k2)&1)==0){
                        ha[k1+1][0]++;
                    }
                    else if(((i>>k1)&1)==0&&((j>>k2)&1)){
                        ha[0][k2+1]++;
                    }
                    else ha[0][0]++;
                }
            }
            bool err=false;
            REP(k1,6)REP(k2,6){
                if(ha[k1][k2]>1)err=true;
            }
            if(!err)an=min(an,cnt(i)+cnt(j));
        }
    printf("%d\n",an);
    return 0;
}