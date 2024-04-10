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
int main(){
    string s;
    cin>>s;
    vector<string>an[2];
    for(int i=0,j;;i=j){
        bool err=0;
        string str;
        for(j=i;j<SZ(s)&&s[j]!=';'&&s[j]!=',';j++){
            str+=s[j];
            if(s[j]<'0'||s[j]>'9')err=1;
        }
        if(i==j)err=1;
        if(s[i]=='0'&&i+1<j)err=1;
        if(!err){
            an[0].PB(str);
        }
        else an[1].PB(str);
        j++;
        if(j>SZ(s))break;
    }
    REP(i,2){
        if(SZ(an[i])==0){
            puts("-");
            continue;
        }
        printf("\"");
        REP(j,SZ(an[i])){
            if(j)printf(",");
            cout<<an[i][j];
        }
        puts("\"");
    }
    return 0;
}