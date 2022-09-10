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
char s[555][555];
int dp[2][500][500];
int dx[4]={1,0,-1,0};
int dy[4]={0,1,0,-1};
void ADD(int& x,int v){
    x+=v;
    if(x>=MOD)x-=MOD;
}
int main(){
    DRII(n,m);
    REP(i,n)RS(s[i]);
    if(s[0][0]!=s[n-1][m-1])return 0*puts("0");
    int L=0,R=n+m-2;
    dp[0][0][n-1]=1;
    int now=0,nxt=1;
    while(L<=R){
        if(L+1==R){
            int an=0;
            REP(i,n){
                ADD(an,dp[now][i][i]);
                if(i+1<n){
                    ADD(an,dp[now][i][i+1]);
                }
            }
            cout<<an<<endl;
            return 0;
        }
        if(L==R){
            int an=0;
            REP(i,n)ADD(an,dp[now][i][i]);
            cout<<an<<endl;
            return 0;
        }
        MS0(dp[nxt]);
        REP(i,n){
            int x1=i,y1=L-i;
            REPP(j,i,n){
                int x2=j,y2=R-j;
                REP(k1,2){
                    int nx1=x1+dx[k1];
                    int ny1=y1+dy[k1];
                    REPP(k2,2,4){
                        int nx2=x2+dx[k2];
                        int ny2=y2+dy[k2];
                        if(nx1>nx2||ny1>ny2||s[nx1][ny1]!=s[nx2][ny2])continue;
                        ADD(dp[nxt][nx1][nx2],dp[now][i][j]);
                    }
                }
            }
        }
        L++;
        R--;
        swap(now,nxt);
    }
    return 0;
}