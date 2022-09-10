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
    VI a,b;
    DRI(N);
    REP(i,N){DRI(x);a.PB(x);}
    DRI(K);
    int it=0;
    vector<pair<int,char> >an;
    REP(i,K){
        set<int>H;
        DRI(x);
        int v=0;
        int ll=it;
        int ma=-1;
        while(it<N&&a[it]+v<=x){
            v+=a[it];
            ma=max(ma,a[it]);
            H.insert(a[it]);
            it++;
        }
        int rr=it;
        if(v!=x||(SZ(H)==1&&ll+1<rr))return 0*puts("NO");
        REPP(j,ll+1,rr){
            if(max(a[j],a[j-1])==ma&&min(a[j],a[j-1])!=ma){
                if(a[j-1]==ma){
                    REPP(k,j,rr){
                        an.PB(MP(j-ll+i,'R'));
                    }
                    for(int k=j-1;k>ll;k--){
                        an.PB(MP(i+k-ll+1,'L'));
                    }
                }
                else{
                    for(int k=j;k>ll;k--){
                        an.PB(MP(i+k-ll+1,'L'));
                    }
                    REPP(k,j,rr-1){
                        an.PB(MP(1+i,'R'));
                    }
                }
                break;
            }
        }
    }
    if(SZ(an)!=N-K)return 0*puts("NO");
    puts("YES");
    REP(i,SZ(an))printf("%d %c\n",an[i].F,an[i].S);
    return 0;
}