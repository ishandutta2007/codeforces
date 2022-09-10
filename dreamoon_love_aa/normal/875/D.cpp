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
const int SIZE = 200010;
int a[SIZE];
VI bit_cnt[31];
int nxt[SIZE][30];
int main(){
    DRI(n);
    REP(i,n){
        RI(a[i]);
        int bn=0;
        int now=a[i];
        while(now){
            bn+=now&1;
            now>>=1;
        }
        bit_cnt[bn].PB(i);
    }
    REP(i,30)nxt[n][i]=n;
    for(int i=n-1;i>=0;i--){
        REP(j,30){
            if((a[i]>>j)&1)nxt[i][j]=i;
            else nxt[i][j]=nxt[i+1][j];
        }
    }
    LL an=0;
    REP(i,n){
        PII stk[35];
        int sn=0;
        VI add;
        REP(j,30)add.PB(nxt[i][j]);
        sort(ALL(add));
        add.PB(n);
        REP(j,31){
            int it=lower_bound(ALL(bit_cnt[j]),i)-bit_cnt[j].begin();
            if(it==SZ(bit_cnt[j]))continue;
            int pos=bit_cnt[j][it];
            while(sn&&stk[sn-1].S>=pos)sn--;
            stk[sn++]=MP(j,pos);
        }
        stk[sn]=MP(31,n);
        int cnt=0;
        int it=0;
        for(int j=0,k;j<30&&add[j]<n;j=k){
            for(k=j;k<30&&add[k]==add[j];k++);
            cnt+=k-j;
            while(it<sn&&stk[it].F<cnt)it++;
            an+=max(0,min(add[k],stk[it].S)-add[j]);
        }
    }
    cout<<an<<endl;
    return 0;
}