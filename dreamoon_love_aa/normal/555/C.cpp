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
int an[SIZE];
int stk[SIZE],sn;
map<int,int>tt;
int main(){
    DRII(N,Q);
    REP(i,Q){
        DRII(x,y);
        char c[4];
        RS(c);
        if(tt.count(x))continue;
        if(c[0]=='L')tt[x]=-(i+1);
        else tt[x]=i+1;
    }

    for(map<int,int>::iterator it=tt.begin();it!=tt.end();it++){
        int i=it->F;
        int me=it->S;
        if(me==0)continue;
        if(me<0){
            while(sn&&abs(me)<tt[stk[sn-1]]){
                an[tt[stk[sn-1]]]=(N+1-stk[sn-1])-(N+1-i);
                sn--;
            }
            if(!sn)an[abs(me)]=i;
            else an[abs(me)]=i-stk[sn-1];
        }
        else{
            an[me]=N+1-i;
            stk[sn++]=i;
        }
    }
    REPP(i,1,Q+1)printf("%d\n",an[i]);
    return 0;
}