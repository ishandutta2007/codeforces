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

int main(){
    string s,t;
    cin>>s>>t;
    int n=SZ(s),m=SZ(t);
    VPII res;
    REP(i,m){
        res.PB(MP(0,0));
        int k;
        REP(j,n){
            for(k=0;j+k<n&&i+k<m&&s[j+k]==t[i+k];k++);
            if(k>abs(res.back().F-res.back().S)){
                res.back()=MP(j+1,j+k);
            }
        }
        if(res.back().F==0)return 0*puts("-1");
        REP(j,n){
            for(k=0;j-k>=0&&i+k<m&&s[j-k]==t[i+k];k++);
            if(k>abs(res.back().F-res.back().S)){
                res.back()=MP(j+1,j+2-k);
            }
        }
        i+=abs(res.back().F-res.back().S);
    }
    cout<<SZ(res)<<endl;
    REP(i,SZ(res))printf("%d %d\n",res[i].F,res[i].S);
    return 0;
}