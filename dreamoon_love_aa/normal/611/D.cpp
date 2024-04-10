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
int dp[5011][5011];
char s[5050];
int from[5011];
int same[5011][5011];
bool my_strncmp(int x,int y,int n){
    return from[x]<from[y]&&same[from[x]][from[y]]<n;
}
int main(){
    DRI(n);
    RS(s+1);
    string str=string(s+1);
    vector<pair<string,int> >strs;
    REP(i,n)strs.PB(MP(str.substr(i),i+1));
    sort(ALL(strs));
    REP(i,n)from[strs[i].S]=i;
    REPP(i,1,n){
        int j=0;
        for(;j<SZ(strs[i].F)&&j<SZ(strs[i-1].F)&&strs[i].F[j]==strs[i-1].F[j];j++);
        same[i-1][i]=j;
    }
    REP(i,n)for(int j=i-2;j>=0;j--)same[j][i]=min(same[j][i-1],same[j+1][i]);
    LL an=0;
    REPP(len,1,n+1){
        for(int ll=1;ll+len<=n+1;ll++){
            int rr=len+ll-1;
            if(ll==1)dp[ll][rr]=1;
            else{
                if(s[ll]!='0'){
                    int lt=ll-len;
                    dp[ll][rr]=dp[max(lt+1,1)][ll-1];
                    if(lt>=1&&s[lt]!='0'&&my_strncmp(lt,ll,len)){
                        dp[ll][rr]+=dp[lt][ll-1]-dp[lt+1][ll-1];
                        if(dp[ll][rr]>=MOD)dp[ll][rr]-=MOD;
                        else if(dp[ll][rr]<0)dp[ll][rr]+=MOD;
                    }
                }
            }
            if(rr==n){
                an+=dp[ll][rr];
            }
            dp[ll][rr]+=dp[ll+1][rr];
            if(dp[ll][rr]>=MOD)dp[ll][rr]-=MOD;
        }
    }
    cout<<an%MOD<<endl;
    return 0;
}