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
LL an;
char s[SIZE];
bool is(char c){
    if(c>='0'&&c<='9')return 1;
    return c=='.';
}
int main(){
    RS(s);
    for(int i=0;s[i];i++){
        if(is(s[i])){
            LL v=0;
            int dot=-1;
            while(is(s[i])){
                if(s[i]!='.')v=v*10+s[i]-'0';
                else dot=i;
                i++;
            }
            if(i-dot==4||dot==-1)v*=100;
            an+=v;
            i--;
        }
    }
    if(an<100){
        printf("0.%02d\n",an);
        return 0;
    }
    VI res;
    while(an){
        res.PB(an%10);
        an/=10;
    }
    reverse(ALL(res));
    REP(i,SZ(res)-2){
        printf("%d",res[i]);
        if((SZ(res)-i)%3==0&&i!=SZ(res)-3)printf(".");
    }
    if(res.back()||res[SZ(res)-2])printf(".%d%d\n",res[SZ(res)-2],res.back());
    else puts("");
    return 0;
}