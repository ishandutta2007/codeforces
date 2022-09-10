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
const int SIZE = 1010;
const int MAX_N = 1003;
template <class T>
void maa(T& x,T y){
    if(x<y)x=y;
}
template <class T>
void mii(T& x,T y){
    if(x>y)x=y;
}
char A[SIZE],s[SIZE];
int A_A[SIZE],B[SIZE][SIZE];
int dp[SIZE][SIZE],last_digit[SIZE];
int c[10];
int n,non_zero;
int order[SIZE];
void solve(){
    MS1(dp);
    dp[0][0]=0;
    REP(i,n)order[i]=i;
    REP(col,MAX_N){
        int adv[10]={},sum[10]={};
        REP(digit,10){
            REP(i,n){
                int nxt=B[i][col]+digit;
                if(nxt>=10)adv[digit]++;
                if(nxt){
                    sum[digit]+=c[nxt%10];
                }
                else{
                    if(col<last_digit[i])sum[digit]+=c[0];
                }
            }
        }
        REP(i,n+1){
            if(dp[col][i]!=-1){
                REPP(digit,col==non_zero?1:0,10){
                    if(A_A[col]!=-1&&A_A[col]!=digit)continue;
                    maa(dp[col+1][adv[digit]],dp[col][i]+sum[digit]);
                }
            }
            if(i==n)break;
            int me=order[i];
            REP(digit,10){
                int nxt=B[me][col]+digit+1;
                if(nxt==10)adv[digit]++;
                sum[digit]+=c[nxt%10];
                if(nxt>1)
                    sum[digit]-=c[(nxt-1)%10];
                else{
                    if(col<last_digit[me])sum[digit]-=c[0];
                }
            }
        }

        VI nd[10];
        REP(i,n){
            nd[B[order[i]][col]].PB(order[i]);
        }
        {
            int it=0;
            for(int i=9;i>=0;i--)REP(j,SZ(nd[i])){
                order[it++]=nd[i][j];
            }
        }
    }
    printf("%d\n",dp[MAX_N][0]);
}
int main(){
    RS(A);
    int A_n=LEN(A);
    non_zero=A_n-1;
    reverse(A,A+A_n);
    REP(i,A_n){
        if(A[i]=='?')A_A[i]=-1;
        else A_A[i]=A[i]-'0';
    }
    RI(n);
    REP(i,n){
        RS(s);
        int l=LEN(s);
        REP(j,l)B[i][j]=s[l-1-j]-'0';
        last_digit[i]=max(l,A_n);
    }
    REP(i,10)RI(c[i]);
    solve();
    return 0;
}