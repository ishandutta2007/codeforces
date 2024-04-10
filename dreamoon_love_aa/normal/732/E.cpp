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
const int INF = 1e9+7;
const int SIZE = 1e6+10;
set<PII>C;
VPII socket;
void print_array(int arr[],int n){
    REP(i,n){
        if(i)printf(" ");
        printf("%d",arr[i]);
    }
    puts("");
}
int an[2][SIZE],use,cnt;
int main(){
    DRII(n,m);
    C.insert(MP(INF,0));
    REP(i,n){
        DRI(x);
        C.insert(MP(x,i+1));
    }
    REP(i,m){
        DRI(x);
        socket.PB(MP(x,i+1));
    }
    sort(ALL(socket));
    REP(i,SZ(socket)){
        int x=socket[i].F;
        int id=socket[i].S;
        int v=0;
        while(1){
            set<PII>::iterator it=C.lower_bound(MP(x,0));
            if(it->F==x){
                cnt++;
                use+=v;
                an[1][it->S]=id;
                an[0][id]=v;
                C.erase(it);
                break;
            }
            if(x==1)break;
            v++;
            x=(x+1)/2;
        }
    }
    printf("%d %d\n",cnt,use);
    print_array(an[0]+1,m);
    print_array(an[1]+1,n);
    return 0;
}