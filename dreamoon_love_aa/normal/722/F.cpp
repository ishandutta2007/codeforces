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
const int SIZE = 1e5+10;
VI fac[41];
VPII pp[SIZE];
int k[SIZE];
int sed[41],cnt[41],base[41],far[41];
bool valid(int p,int pos){
    int now=far[p];
    while(now!=1){
        if(now>p){
            if(sed[now]!=-1&&sed[now]%p!=pos)return 0;
        }
        else{
            if(sed[now]!=-1&&sed[now]!=pos%now)return 0;
        }
        now/=base[now];
    }
    return 1;
}
int main(){
    REPP(i,2,41){
        if(SZ(fac[i])==0){
            int ma=i;
            while(ma*i<41)ma*=i;
            for(int j=i;j<41;j+=i){
                int x=i;
                while(j%(x*i)==0)x*=i;
                base[x]=i;
                far[x]=ma;
                fac[j].PB(x);
            }
        }
    }
    DRII(n,m);
    REP(i,n){
        RI(k[i]);
        REP(j,k[i]){
            DRI(x);
            pp[x].PB(MP(i,j));
        }
    }
    REPP(x,1,m+1){
        int res=0;
        MS1(sed);
        MS0(cnt);
        int ll=0;
        REP(i,SZ(pp[x])){
            int me_id=pp[x][i].F;
            int me_pos=pp[x][i].S;
            if(i&&pp[x][i].F!=pp[x][i-1].F+1){
                for(;ll<i;ll++){
                    int line_id=pp[x][ll].F;
                    REP(j,SZ(fac[k[line_id]])){
                        int p=fac[k[line_id]][j];
                        cnt[p]--;
                        if(cnt[p]==0)sed[p]=-1;
                    }
                }
            }
            REP(j,SZ(fac[k[me_id]])){
                int p=fac[k[me_id]][j];
                for(;ll<i&&!valid(p,me_pos%p);ll++){
                    int line_id=pp[x][ll].F;
                    REP(j2,SZ(fac[k[line_id]])){
                        int p2=fac[k[line_id]][j2];
                        cnt[p2]--;
                        if(cnt[p2]==0)sed[p2]=-1;
                    }
                }
                sed[p]=me_pos%p;
                cnt[p]++;
            }
            res=max(res,i-ll+1);
        }
        printf("%d\n",res);
    }
    return 0;
}