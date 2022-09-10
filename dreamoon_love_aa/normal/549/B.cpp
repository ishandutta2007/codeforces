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
void print_array(vector<int>&arr){
    REP(i,SZ(arr)){
        if(i)printf(" ");
        printf("%d",arr[i]);
    }
    puts("");
}
int a[SIZE],now[SIZE];
char s[125][125];
int main(){
    DRI(N);
    REP(i,N){
        RS(s[i]);
    }
    REP(i,N){
        RI(a[i]);
    }
    vector<int>res;
    while(1){
        int id=-1;
        REP(i,N){
            if(a[i]==now[i]){
                id=i;
                break;
            }
        }
        if(id==-1)break;
        res.PB(id+1);
        REP(i,N)
            if(s[id][i]=='1')now[i]++;
    }
    printf("%d\n",SZ(res));
    print_array(res);
    puts("");
    return 0;
}