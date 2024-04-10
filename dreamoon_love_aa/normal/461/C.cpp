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
const int SIZE = 1e5+5;
bool rev;
int a[SIZE];
int BIT[SIZE];
void ins(int x,int v){
    while(x<SIZE){
        BIT[x]+=v;
        x+=x&-x;
    }
}
int qq(int x){
    int res=0;
    while(x){
        res+=BIT[x];
        x-=x&-x;
    }
    return res;
}
int get(int x){
    if(!x)return 0;
    return qq(x)-qq(x-1);
}
int main(){
    DRII(n,q);
    int ll=1,rr=n;
    REP(i,n){
        a[i+1]=1;
        ins(i+1,1);
    }
    while(q--){
        DRI(ty);
        if(ty==1){
            DRI(x);
            if(x+x<=rr-ll+1){
                if(!rev){
                    REP(i,x){
                        int me=get(ll+i);
                        ins(ll+i,-me);
                        ins(ll+x+x-i-1,me);
                    }
                    ll+=x;
                }
                else{
                    REP(i,x){
                        int me=get(rr-i);
                        ins(rr-i,-me);
                        ins(rr-x-x+i+1,me);
                    }
                    rr-=x;
                }
            }
            else{
                int y=rr-ll+1-x;
                //printf("[%d]\n",y);
                if(!rev){
                    REP(i,y){
                        int me=get(rr-i);
                        ins(rr-i,-me);
                        ins(rr-y-y+i+1,me);
                    }
                    rr-=y;
                    rev=!rev;
                }
                else{
                    REP(i,y){
                        int me=get(ll+i);
                        ins(ll+i,-me);
                        ins(ll+y+y-i-1,me);
                    }
                    ll+=y;
                    rev=!rev;
                }
            }
        }
        else{
            DRII(x,y);
            if(!rev){
                printf("%d\n",qq(ll+y-1)-qq(ll+x-1));
            }
            else{
                printf("%d\n",qq(rr-x)-qq(rr-y));
            }
        }
    }
    return 0;
}