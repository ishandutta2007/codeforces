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
int m;
void get(LL h,LL a,LL x,LL y,LL &v1,LL &v2){
    v1=-1;
    v2=-1;
    int tt=0;
    REP(i,m*5){
        h=(x*h+y)%m;
        if(h==a){
            if(!tt){
                v1=i+1;
            }
            else if(tt==1){
                v2=i+1;
            }
            else break;
            tt++;
        }
    }
}
int ha[SIZE];
int main(){
    RI(m);
    DRII(h1,a1);
    DRII(x1,y1);
    DRII(h2,a2);
    DRII(x2,y2);
    LL v1,v2,u1,u2;
    get(h1,a1,x1,y1,v1,v2);
    get(h2,a2,x2,y2,u1,u2);
    if(v1==-1||u1==-1){
        puts("-1");
    }
    else{
        if(u2==-1){
            swap(v1,u1);
            swap(v2,u2);
        }
        if(v2==-1){
            if(u2==-1){
                if(v1==u1)cout<<v1<<endl;
                else cout<<-1<<endl;
            }
            else{
                LL now=u1;
                REP(k,m*5){
                    if(now==v1){
                        cout<<now<<endl;
                        return 0;
                    }
                    now+=u2-u1;
                }
                cout<<-1<<endl;
                return 0;
            }
        }
        else{
            LL now=u1;
            REP(k,m*5){
                if(now>=v1&&(now-v1)%(v2-v1)==0){
                    cout<<now<<endl;
                    return 0;
                }
                now+=u2-u1;
            }
            cout<<-1<<endl;
            return 0;
        }
    }
    return 0;
}