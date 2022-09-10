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
#define VPII vector<pair<int,int> >
#define PLL pair<long long,long long>
#define F first
#define S second
typedef long long LL;
using namespace std;
const int MOD = 1e9+7;
const int SIZE = 2e5+10;
bool res[2][SIZE*10];
LL a[SIZE],b[SIZE],x[SIZE],y[SIZE],t[SIZE];
int n,l;
char an[SIZE*10];
PII tmp[SIZE];
bool get(bool ha[],LL d[]){
    REP(i,n){
        if((t[i]+d[i])%2)return 0;
        d[i]=(t[i]+d[i])/2;
        if(d[i]>t[i]||d[i]<0)return 0;
    }
    static bool first_come=1;
    if(first_come){
        REP(i,n)tmp[i]=MP(t[i]%l,i);
        sort(tmp,tmp+n);
        first_come=0;
    }
    int mi=l+1,id=-1;
    tmp[n]=tmp[0];
    tmp[n].F+=l;
    vector<int>check;
    int base=0;
    REPP(i,1,n+1){
        if(t[tmp[i].S]/l!=t[tmp[i-1].S]/l+(i==n)){
            check.PB(i);
            if(tmp[i].F-tmp[i-1].F<mi){
                id=i;
                mi=tmp[i].F-tmp[i-1].F;
            }
        }
        else{
            int one=d[tmp[i].S]-d[tmp[i-1].S];
            if(one>tmp[i].F-tmp[i-1].F)return 0;
            REP(j,one)ha[(tmp[i-1].F+j)%l]=1;

        }
    }
    REP(one,mi+1){
        int x=tmp[id-1].S;
        int y=tmp[id].S;
        LL all=(d[y]-(d[x]+one))/((t[y]/l-(t[x]+mi)/l));
        if(all>l)continue;
        bool err=0;
        int check_sum=0;
        REP(i,SZ(check)){
            int nx=tmp[check[i]-1].S;
            int ny=tmp[check[i]].S;
            LL dd=(tmp[check[i]].F-tmp[check[i]-1].F+l)%l;
            check_sum+=dd;
            int nxt_one=d[ny]-d[nx]-all*((t[ny]/l-(t[nx]+dd)/l));
            if(nxt_one>dd||nxt_one<0){
                err=1;
                break;
            }
        }
        if(!err){
            REP(i,SZ(check)){
                int nx=tmp[check[i]-1].S;
                int ny=tmp[check[i]].S;
                LL dd=(tmp[check[i]].F-tmp[check[i]-1].F+l)%l;
                int nxt_one=d[ny]-d[nx]-all*((t[ny]/l-(t[nx]+dd)/l));
                REP(j,nxt_one)ha[(tmp[check[i]-1].F+j)%l]=1;
            }
            if(!check_sum){
                REP(j,all)ha[j]=1;
            }
            return 1;
        }
    }
    return 0;
}
int main(){
    RII(n,l);
    n++;
    REPP(i,1,n)scanf("%I64d%I64d%I64d",&t[i],&x[i],&y[i]);
    REP(i,n){
        a[i]=x[i]+y[i];
        b[i]=x[i]-y[i];
    }
    if(!get(res[0],a)||!get(res[1],b))puts("NO");
    else{
        REP(i,l){
            if(res[0][i]&&res[1][i])an[i]='R';
            else if(res[0][i])an[i]='U';
            else if(res[1][i])an[i]='D';
            else an[i]='L';
        }
        puts(an);
    }
    return 0;
}