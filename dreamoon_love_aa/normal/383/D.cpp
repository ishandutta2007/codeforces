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
LL an;
int sum[1001],a[1001];
void ADD(LL &x,LL v){x=(x+v)%MOD;}
int used1[2][10001],used2[2][10001],tt1,tt2;
LL dp1[2][10001],dp2[2][10001],cnt1[10001],cnt2[10001];
void f(int L,int R){
    if(L+1>=R)return;
    int mm=(L+R)/2;
    tt1++;
    int up=a[mm];
    int now1=0,nxt1=1;
    dp1[0][a[mm]]=1;
    used1[0][a[mm]]=tt1;
    memset(cnt1,0,sizeof(LL)*(sum[R-1]-sum[mm-1]+1));
    REPP(i,mm+1,R){
        for(int j=up;j>=0;j--){
            if(used1[now1][j]==tt1){
                int nv=j+a[i];
                if(used1[nxt1][nv]==tt1+1)ADD(dp1[nxt1][nv],dp1[now1][j]);
                else{
                    used1[nxt1][nv]=tt1+1;
                    dp1[nxt1][nv]=dp1[now1][j];
                }
                nv=abs(j-a[i]);
                if(used1[nxt1][nv]==tt1+1)ADD(dp1[nxt1][nv],dp1[now1][j]);
                else{
                    used1[nxt1][nv]=tt1+1;
                    dp1[nxt1][nv]=dp1[now1][j];
                }
                ADD(cnt1[j],dp1[now1][j]);
            }
        }
        up+=a[i];
        tt1++;
        swap(now1,nxt1);
    }
    memset(cnt2,0,sizeof(LL)*(sum[mm-1]-sum[L-1]+1));
    tt2++;
    int now2=0,nxt2=1;
    dp2[now2][a[mm-1]]=1;
    used2[now2][a[mm-1]]=tt2;
    up=a[mm-1];
    for(int i=mm-2;i>=L;i--){
        for(int j=up;j>=0;j--){
            if(used2[now2][j]==tt2){
                int nv=j+a[i];
                if(used2[nxt2][nv]==tt2+1)ADD(dp2[nxt2][nv],dp2[now2][j]);
                else{
                    used2[nxt2][nv]=tt2+1;
                    dp2[nxt2][nv]=dp2[now2][j];
                }
                nv=abs(j-a[i]);
                if(used2[nxt2][nv]==tt2+1)ADD(dp2[nxt2][nv],dp2[now2][j]);
                else{
                    used2[nxt2][nv]=tt2+1;
                    dp2[nxt2][nv]=dp2[now2][j];
                }
                ADD(cnt2[j],dp2[now2][j]);
            }
        }
        up+=a[i];
        tt2++;
        swap(now2,nxt2);
    }
    up=min(sum[R-1]-sum[mm-1],sum[mm-1]-sum[L-1]);
    REP(i,up+1){
        if(used1[now1][i]==tt1)ADD(cnt1[i],dp1[now1][i]);
        if(used2[now2][i]==tt2)ADD(cnt2[i],dp2[now2][i]);
        if(!i)
            ADD(an,cnt1[i]*cnt2[i]*4);
        else
            ADD(an,cnt1[i]*cnt2[i]*2);
    }
    f(L,mm);
    f(mm,R);
}
int main(){
    DRI(n);
    REP(i,n){
        RI(a[i+1]);
        sum[i+1]=sum[i]+a[i+1];
    }
    f(1,n+1);
    cout<<an;
    return 0;
}