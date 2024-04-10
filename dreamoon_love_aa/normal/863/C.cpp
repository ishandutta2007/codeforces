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
#define VL vector<long long>
#define VPII vector<pair<int,int> >
#define PLL pair<long long,long long>
#define VPLL vector<pair<long long,long long> >
#define F first
#define S second
typedef long long LL;
using namespace std;
const int MOD = 1e9+7;
const int SIZE = 1e6+10;
int d[2][3][3];
int pos[3][3];
PII gg[9];
int main(){
    LL n,a,b;
    cin>>n>>a>>b;
    a--;b--;
    REP(r,2)REP(i,3)REP(j,3){
        RI(d[r][i][j]);
        d[r][i][j]--;
    }
    pos[a][b]=0;
    MS1(pos);
    gg[0]=MP(a,b);
    LL an1=0,an2=0;
    REP(i,min(12LL,n)){
        if((a+3-b)%3==1)an1++;
        if((a+3-b)%3==2)an2++;
        int x=d[0][a][b];
        int y=d[1][a][b];
        a=x;
        b=y;
        if(pos[x][y]!=-1){
            int lt=pos[x][y];
            LL mul=(n-lt)/(i+1-lt)-1;
            int r=(n-lt)%(i+1-lt);
            REPP(j,lt,i+1){
                if((gg[j].F+3-gg[j].S)%3==1){
                    an1+=mul;
                }
                else if((gg[j].F+3-gg[j].S)%3==2){
                    an2+=mul;
                }
                if(j-lt<r){
                    if((gg[j].F+3-gg[j].S)%3==1){
                        an1++;
                    }
                    else if((gg[j].F+3-gg[j].S)%3==2){
                        an2++;
                    }
                }
            }
            break;
        }
        pos[x][y]=i+1;
        gg[i+1]=MP(x,y);
    }
    cout<<an1<<" "<<an2<<endl;
    return 0;
}