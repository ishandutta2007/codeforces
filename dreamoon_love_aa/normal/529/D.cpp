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
int d[SIZE],an[SIZE];
void print_array(int arr[],int n){
    REP(i,n){
        printf("%d\n",arr[i]);
    }
}
int main(){
    DRIII(n,M,T);
    REP(i,n){
        char s[12];
        RS(s);
        for(int j=0;s[j];j++)
            if(s[j]==':')s[j]=' ';
        stringstream ss(s);
        int x,y,z;
        ss>>x>>y>>z;
        d[i]=x*3600+y*60+z;
    }
    int id=0,now=0;
    int ll=0;
    bool suc=0;
    REP(i,n){
        while(d[ll]+T<=d[i]){
            if(an[ll]!=an[ll+1])now--;
            ll++;
        }
        if(now==M)an[i]=an[i-1];
        else{
            an[i]=++id;
            now++;
        }
        if(now==M)suc=1;
    }
    if(suc){
        printf("%d\n",id);
        print_array(an,n);
    }
    else puts("No solution");
    return 0;
}