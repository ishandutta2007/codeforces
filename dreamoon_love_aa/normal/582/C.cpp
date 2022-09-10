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
const int SIZE = 4e5+10;
int a[SIZE];
vector<int>gg[SIZE];
LL an;
int yes[SIZE],tt;
LL cnt[SIZE],cnt2[SIZE];
void go(int bb,int n){
    tt++;
    int good=0;
    REP(i,bb){
        int ma=0;
        for(int j=i;j<n;j+=bb){
            ma=max(ma,a[j]);
        }
        for(int j=i;j<n;j+=bb){
            if(a[j]==ma){
                yes[j]=tt;
                good++;
            }
        }
    }
    if(good==n){
        an+=(LL)n*SZ(gg[bb]);
    }
    else{
        int st=0;
        while(yes[st]==tt)st++;
        memset(cnt,0,sizeof(LL)*(SZ(gg[bb])+5));
        memset(cnt2,0,sizeof(LL)*(SZ(gg[bb])+5));
        REP(i,n){
            if(yes[(st+i)%n]==tt){
                int len=1;
                while(yes[(st+i+len)%n]==tt)len++;
                int it=upper_bound(ALL(gg[bb]),len)-gg[bb].begin();
                cnt[0]+=len+1;
                cnt[it]-=len+1;
                cnt2[0]++;
                cnt2[it]--;
                i+=len;
            }
        }
        REP(i,SZ(gg[bb])){
            if(i){
                cnt[i]+=cnt[i-1];
                cnt2[i]+=cnt2[i-1];
            }
            an+=cnt[i]-cnt2[i]*gg[bb][i];
        }
    }
}
int main(){
    DRI(n);
    REP(i,n)RI(a[i]);
    REPP(i,1,n+1)gg[__gcd(i,n)].PB(i);
    REPP(bb,1,n){
        if(n%bb==0){
            go(bb,n);
        }
    }
    cout<<an;
    return 0;
}