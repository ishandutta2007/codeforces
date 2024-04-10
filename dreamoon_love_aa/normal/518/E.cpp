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
const int INF = 1e9+7;
const int SIZE = 1e6+10;
char s[20];
int a[SIZE];
bool go(vector<int*>&d){
    int lt=0;
    while(lt!=SZ(d)-1){
        int now=lt+1;
        while(*d[now]==INF)now++;
        LL l=*d[lt];
        LL r=*d[now];
        if(r-l<now-lt)return 0;
        int mid=(lt+now)/2;
        for(int i=lt+1;i<now;i++){
            *d[i]=i-mid;
        }
        if(*d[lt+1]<=l){
            REPP(i,lt+1,now){
                *d[i]=*d[lt]+i-lt;
            }
        }
        else if(*d[now-1]>=r){
            REPP(i,lt+1,now){
                *d[i]=*d[now]-(now-i);
            }
        }
        lt=now;
    }
    return 1;
}
int main(){
    DRII(n,k);
    REP(i,n){
        RS(s);
        if(s[0]=='?')a[i]=INF;
        else a[i]=atoi(s);
    }
    int small=INF*-2,large=INF*2;
    REP(i,k){
        vector<int*>d;
        d.PB(&small);
        for(int j=i;j<n;j+=k)d.PB(&a[j]);
        d.PB(&large);
        if(!go(d)){
            puts("Incorrect sequence");
            return 0;
        }
    }
    REP(i,n){
        if(i)printf(" ");
        printf("%d",a[i]);
    }
    puts("");
    return 0;
}