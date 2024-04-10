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
#define F first
#define S second
typedef long long LL;
using namespace std;
const int MOD = 1e9+7;
const int SIZE = 1e6+10;
char s[SIZE];
int main(){
    DRII(n,p);
    p--;
    RS(s);
    int ll=n;
    int rr=-1;
    int an=0;
    for(int i=0;i<n-1-i;i++){
        int j=n-1-i;
        if(s[i]!=s[j]){
            ll=min(ll,i);
            rr=max(rr,i);
            int dif=abs((int)s[i]-(int)s[j]);
            an+=min(dif,26-dif);
        }
    }
    if(ll>rr){
        puts("0");
        return 0;
    }
    int mov=1e9;
    mov=min(mov,abs(p-ll)+abs(rr-ll));
    mov=min(mov,abs(p-rr)+abs(rr-ll));
    ll=n-1-ll;
    rr=n-1-rr;
    mov=min(mov,abs(p-ll)+abs(rr-ll));
    mov=min(mov,abs(p-rr)+abs(rr-ll));
    cout<<an+mov<<endl;
    return 0;
}