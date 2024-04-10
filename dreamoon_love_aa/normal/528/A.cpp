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
int main(){
    DRIII(w,h,n);
    multiset<int>len[2];
    set<int>p[2];
    p[0].insert(0);
    p[0].insert(w);
    p[1].insert(0);
    p[1].insert(h);
    len[0].insert(w);
    len[1].insert(h);
    REP(i,n){
        char s[4];
        RS(s);
        DRI(x);
        int id;
        if(s[0]=='V'){
            id=0;
        }
        else{
            id=1;
        }
        p[id].insert(x);
        set<int>::iterator me=p[id].find(x);
        set<int>::iterator L=me;L--;
        set<int>::iterator R=me;R++;
        len[id].erase(len[id].find(*R-*L));
        len[id].insert(*me-*L);
        len[id].insert(*R-*me);
        printf("%I64d\n",*len[0].rbegin()*((LL)(*len[1].rbegin())));
    }
    return 0;
}