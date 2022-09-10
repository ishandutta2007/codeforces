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
const int SIZE = 2e5+10;
int jump[18][SIZE],jv[18][SIZE];
void build(int n){
    jump[0][n]=n;
    n++;
    REPP(i,1,18){
        REPP(x,1,n){
            jump[i][x]=jump[i-1][jump[i-1][x]];
            jv[i][x]=jv[i-1][x]+jv[i-1][jump[i-1][x]];
        }
    }
}
int p[SIZE],l[SIZE];
int BIT[SIZE],BIT_from[SIZE];
void ins(int x,int v){
    int id=x;
    for(;x<SIZE;x+=x&-x){
        if(BIT[x]<v){
            BIT[x]=v;
            BIT_from[x]=id;
        }
    }
}
pair<int,int> qq(int x){
    pair<int,int> res=MP(0,0);
    for(;x;x-=x&-x){
        if(BIT[x]>res.F){
            res=MP(BIT[x],BIT_from[x]);
        }
    }
    return res;
}
int main(){
    DRI(n);
    REPP(i,1,n+1)RII(p[i],l[i]);
    for(int i=n;i>0;i--){
        ins(i,p[i]+l[i]);
        if(i<n){
            int ll=i,rr=n;
            while(ll<rr){
                int mm=(ll+rr+1)>>1;
                if(p[i]+l[i]>=p[mm])ll=mm;
                else rr=mm-1;
            }
            if(ll==n){
                jump[0][i]=n;
            }
            else{
                PII res=qq(ll);
                if(res.S==i){
                    jump[0][i]=rr+1;
                    jv[0][i]=p[rr+1]-p[i]-l[i];
                }
                else{
                    jump[0][i]=res.S;
                }
            }
        }
    }
    build(n);
    DRI(Q);
    while(Q--){
        DRII(x,y);
        if(p[x]+l[x]>=p[y]){
            puts("0");
            continue;
        }
        int an=0;
        for(int i=17;i>=0;i--){
            int nxt=jump[i][x];
            if(p[nxt]+l[nxt]<p[y]){
                an+=jv[i][x];
                x=nxt;
            }
        }
        printf("%d\n",an+jv[0][x]);
    }
    return 0;
}