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
const int MM = 5e5;
const LL INF = 1e18;
char s[SIZE];
LL getH[SIZE],getW[SIZE];
void ADD(LL &x,LL v){
    x=(x+v)%MOD;
}
int main(){
    DRIII(n,h,w);
    REP(i,SIZE)getH[i]=getW[i]=INF;
    RS(s);
    int xx=0,yy=0;
    getW[MM]=getH[MM]=0;
    REP(i,n){
        if(s[i]=='R')xx++;
        else if(s[i]=='L')xx--;
        else if(s[i]=='U')yy++;
        else if(s[i]=='D')yy--;
        if(getW[xx+MM]==INF)getW[xx+MM]=i+1;
        if(getH[yy+MM]==INF)getH[yy+MM]=i+1;
    }
    if(xx){
        if(xx>0){
            REPP(j,MM,SIZE)
                if(getW[j]==INF)getW[j]=getW[j-xx]+n;
        }
        else{
            for(int j=MM;j>=0;j--){
                if(getW[j]==INF)getW[j]=getW[j-xx]+n;
            }
        }
    }
    if(yy){
        if(yy>0){
            REPP(j,MM,SIZE)
                if(getH[j]==INF)getH[j]=getH[j-yy]+n;
        }
        else{
            for(int j=MM;j>=0;j--){
                if(getH[j]==INF)getH[j]=getH[j-yy]+n;
            }
        }
    }
    int uu=1,dd=-1,rr=1,ll=-1;
    LL an=0;
    while(w>0&&h>0){
        if(getH[MM+uu]==INF&&getH[MM+dd]==INF&&getW[MM+rr]==INF&&getW[MM+ll]==INF)return 0*puts("-1");
        if(getH[MM+uu]<getH[MM+dd]&&getH[MM+uu]<getW[MM+ll]&&getH[MM+uu]<getW[MM+rr]){
            ADD(an,w*getH[MM+uu]);
            h--;
            uu++;
        }
        else if(getH[MM+dd]<getW[MM+ll]&&getH[MM+dd]<getW[MM+rr]){
            ADD(an,w*getH[MM+dd]);
            h--;
            dd--;
        }
        else if(getW[MM+ll]<getW[MM+rr]){
            ADD(an,h*getW[MM+ll]);
            w--;
            ll--;
        }
        else{
            ADD(an,h*getW[MM+rr]);
            w--;
            rr++;
        }
    }
    cout<<an;
    return 0;
}