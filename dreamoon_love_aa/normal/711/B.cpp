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
LL a[555][555];
int main(){
    DRI(n);
    PII me;
    REP(i,n)REP(j,n){
        cin>>a[i][j];
        if(!a[i][j])me=MP(i,j);
    }
    if(n==1)puts("1");
    else{
        int row=0;
        if(me.F==row)row++;
        LL sum=0;
        REP(i,n)sum+=a[row][i];
        LL now=0;
        REP(i,n)now+=a[me.F][i];
        a[me.F][me.S]=sum-now;
        if(sum-now<1)return 0*puts("-1");
        else{
            REP(i,n){
                LL ker=0;
                REP(j,n)ker+=a[i][j];
                if(ker!=sum)return 0*puts("-1");
                ker=0;
                REP(j,n)ker+=a[j][i];
                if(ker!=sum)return 0*puts("-1");
            }
            LL ker2=0;
            REP(i,n)ker2+=a[i][i];
            if(ker2!=sum)return 0*puts("-1");
            ker2=0;
            REP(i,n)ker2+=a[i][n-1-i];
            if(ker2!=sum)return 0*puts("-1");
            cout<<sum-now<<endl;
        }
    }
    return 0;
}