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
const int SIZE = 100010;
vector<pair<int,int> >an;
bitset<SIZE>p;
int used[SIZE];
int main(){
    DRI(n);
    for(int i=2;i<=n;i++){
        if(!p[i])
            for(int j=i+i;j<=n;j+=i)p[j]=1;
    }
    vector<int>two;
    for(int i=n/2;i>1;i--){
        if(!p[i]){
            vector<int>now;
            for(int j=i;j<=n;j+=i){
                if(!used[j]){
                    used[j]=1;
                    now.PB(j);
                }
            }
            if(SZ(now)%2==0){
                for(int j=0;j<SZ(now);j+=2)an.PB(MP(now[j],now[j+1]));
            }
            else{
                if(SZ(now)==1)
                {
                    if(now[0]%2==0)two.PB(now[0]);
                }
                else{
                    two.PB(now[1]);
                    an.PB(MP(now[0],now[2]));
                    for(int j=3;j<SZ(now);j+=2)an.PB(MP(now[j],now[j+1]));
                }
            }
        }
    }
    for(int i=0;i+1<SZ(two);i+=2)an.PB(MP(two[i],two[i+1]));
    printf("%d\n",SZ(an));
    REP(i,SZ(an))printf("%d %d\n",an[i],an[i+1]);
    return 0;
}