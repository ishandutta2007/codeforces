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
const int MOD1 = (1<<23)-1;
const int MOD2 = 1e9+9;
const int MUL1=13777;
const int MUL2=127;
const int SIZE = 1e6+10;
vector<int> H[5001],H2[5001];
char hashh[MOD1+1];
int main(){
    string s;
    cin>>s;
    int n=5000;
    n=min(n,SZ(s));
    bool have[128]={};
    REP(i,SZ(s))have[s[i]]=1;
    REP(i,SZ(s)){
        LL now1=0;
        REPP(j,i,SZ(s)){
            now1^=0xabcdef;
            now1*=MUL1;
            now1=(now1+s[j])&MOD1;
            H[j-i+1].PB(now1);
        }
    }
    bool suc=0;
    cin>>s;
    REP(i,SZ(s)){
        if(have[s[i]])suc=1;
    }
    if(!suc)return 0*puts("-1");
    n=min(n,SZ(s));
    REP(i,SZ(s)){
        LL now1=0;
        REPP(j,i,SZ(s)){
            now1^=0xabcdef;
            now1*=MUL1;
            now1=(now1+s[j])&MOD1;
            H2[j-i+1].PB(now1);
        }
    }
    REPP(i,1,n+1){
        int it1=0,it2=0;
        bool same=0;
        REP(j,SZ(H[i]))
            hashh[H[i][j]]++;
        REP(j,SZ(H[i]))
            if(hashh[H[i][j]]!=1)hashh[H[i][j]]|=3;
        REP(j,SZ(H2[i])){
            if(hashh[H2[i][j]])hashh[H2[i][j]]++,same=1;
        }
        REP(j,SZ(H[i])){
            if(hashh[H[i][j]]==2)return 0*printf("%d\n",i);
            hashh[H[i][j]]=0;
        }
        if(!same)return 0*puts("-1");
    }
    puts("-1");
    return 0;
}