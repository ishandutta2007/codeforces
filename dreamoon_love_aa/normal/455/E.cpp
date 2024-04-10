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
const int SIZE = 1e5+5;
int a[SIZE],an[SIZE],sum[SIZE],bb[SIZE];
vector<pair<int,int> >qq[SIZE];
int get(int L,int R){return sum[R]-sum[L-1];}
int sk[SIZE],over[SIZE],sn;
int main(){
    DRI(n);
    REPP(i,1,n+1){
        RI(a[i]);
        sum[i]=a[i]+sum[i-1];
    }
    DRI(Q);
    REP(i,Q){
        DRII(x,y);
        qq[y].PB(MP(x,i));
    }

    REP(i,SZ(qq[1])){
        an[qq[1][i].S]=a[1];
    }
    sn=0;
    bb[sn]=0;
    sk[sn++]=1;
    REPP(i,2,n+1){
        if(a[i]>=a[i-1]){
            bb[sn]=i-1;
            sk[sn++]=i;
        }
        else{
            while(sn>0&&a[i]<=a[sk[sn-1]]){
                sn--;
            }
            while(sn>0){
                int nt=sk[sn-1];
                int part=get(nt+1,i)-a[i]*(i-nt);
                int dif=a[i]-a[nt];
                int need=(part+dif-1)/dif+(i-nt);
                if(need>i||(sn>=2&&i-need<=bb[sn-2]))sn--;
                else{
                    bb[sn-1]=i-need;
                    break;
                }
            }
            bb[sn]=i-1;
            sk[sn++]=i;
        }
        REP(j,SZ(qq[i])){
            int r=i-qq[i][j].F;
            int id=qq[i][j].S;
            int ll=0,rr=sn-1;
            while(ll<rr){
                int mm=(ll+rr)>>1;
                if(r<=bb[mm])rr=mm;
                else ll=mm+1;
            }
            int ld=sk[ll];
            an[id]=get(ld,i)+a[ld]*(qq[i][j].F-(i-ld+1));
        }
    }

    REP(i,Q)printf("%d\n",an[i]);
    return 0;
}