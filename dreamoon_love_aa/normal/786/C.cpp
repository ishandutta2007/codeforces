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
int a[SIZE];
int an[SIZE];
int n;
int used[SIZE],tt;
void build(int L,int R){
    if(L>R)return;
    if(an[L-1]==an[R+1]){
        REPP(i,L,R+1)an[i]=an[i-1];
        return;
    }
    int mm=(L+R)/2;
    tt++;
    int cnt=0;
    int now=0;
    REP(i,n){
        if(used[a[i]]!=tt){
            used[a[i]]=tt;
            cnt++;
            if(cnt>mm){
                tt++;
                now++;
                cnt=1;
                used[a[i]]=tt;
            }
        }
    }
    now++;
    an[mm]=now;
    build(L,mm-1);
    build(mm+1,R);
}
int main(){
    DRI(input_n);
    {
        int now=1;
        REP(i,input_n){
            DRI(x);
            if(!n||a[n-1]!=x)a[n++]=x;
        }
    }
    int col_num=0;
    {
        tt++;
        REP(i,n){
            if(used[a[i]]!=tt){
                used[a[i]]=tt;
                col_num++;
            }
        }
    }
    an[1]=n;
    REPP(i,col_num,input_n+1)an[i]=1;
    build(2,col_num-1);
    REPP(i,1,input_n+1)printf("%d%c",an[i]," \n"[i==input_n]);
    return 0;
}