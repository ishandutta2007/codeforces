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
const int SIZE = 1e6+10;
// template end here
char s[3][SIZE];
int n[3],d[3][26];
int main(){
    REP(i,3){
        RS(s[i]);
        n[i]=LEN(s[i]);
        REP(j,n[i])d[i][s[i][j]-'a']++;
    }
    int t1=0,t2=0,res1=0,res2=0;
    while(1){
        int tmp[26]={};
        REP(i,26)tmp[i]=d[0][i];
        bool err=0;
        REP(i,26){
            tmp[i]-=d[1][i]*t1;
            if(tmp[i]<0)err=1;
        }
        if(err)break;
        t2=1e9;
        REP(i,26){
            if(d[2][i])t2=min(t2,tmp[i]/d[2][i]);
        }
        if(t1+t2>res1+res2){
            res1=t1;
            res2=t2;
        }
        t1++;
    }
    int tmp[26]={};
    REP(i,26)tmp[i]=d[0][i];
    REP(i,res1){
        printf("%s",s[1]);
        REP(j,n[1])tmp[s[1][j]-'a']--;
    }
    REP(i,res2){
        printf("%s",s[2]);
        REP(j,n[2])tmp[s[2][j]-'a']--;
    }
    REP(i,26)
        while(tmp[i]){
            putchar('a'+i);
            tmp[i]--;
        }
    puts("");
    return 0;
}