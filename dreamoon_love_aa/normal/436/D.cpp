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
int need[20110],a[1001010],pos[211010],dp[1001010],sum[1001010];
vector<pair<int,int> >reg;
inline int get(int L,int R){
    if(L>R)return 0;
    if(L==0)return sum[R];
    return sum[R]-sum[L-1];
}
int main(){
    int an=0;
    DRII(n,m);
    REP(i,n)RI(a[i]);
    sort(a,a+n);
    REP(i,m)RI(pos[i]);
    sort(pos,pos+m);
    for(int i=0,j;i<n;i=j){
        for(j=i+1;j<n&&a[j]-a[i]==j-i;j++);
        reg.PB(MP(a[i],j-i));
    }
    REP(i,m)need[i]=SZ(reg)-1;
    sum[0]=reg[0].S;
    REPP(i,1,SZ(reg)){
        sum[i]=sum[i-1]+reg[i].S;
    }
    int now=0;
    REP(i,SZ(reg)){
        if(i)dp[i]=max(dp[i],dp[i-1]);
        while(now<m&&pos[now]<reg[i].F)now++;
        int yo=dp[i-1];
        REP(j,now){
            while(need[j]>=0&&get(need[j],i-1)<reg[i].F-pos[j])need[j]--;
            if(need[j]>=0){
                if(need[j]==0)yo=max(yo,now-j);
                else yo=max(yo,now-j+dp[need[j]-1]);
            }
        }
        REPP(j,now,m){
            while(need[j]>i&&get(i,need[j]-1)>=pos[j]-reg[i].F+1)need[j]--;
            if(get(i,need[j])>=pos[j]-reg[i].F+1){
                dp[need[j]]=max(dp[need[j]],yo+j-now+1);
            }
        }
        dp[i]=max(dp[i],yo);
    }
    an=dp[SZ(reg)-1];
    cout<<an<<endl;
    return 0;
}