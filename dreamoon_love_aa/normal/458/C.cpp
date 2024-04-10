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
const int N = 1e5+5;
const int BIT_SIZE = (1<<15);
vector<int>e[N];
int BIT1[BIT_SIZE],BIT2[BIT_SIZE],d[N];
void add(int bit[],int x,int v){
    while(x<BIT_SIZE){
        bit[x]+=v;
        x+=x&-x;
    }
}
bool compare(int x,int y){
    return SZ(e[x])<SZ(e[y]);
}
int qq(int num){
    int two=1<<20;
    while(two>=BIT_SIZE)two>>=1;
    int now=0;
    int res=0;
    while(two){
        if(!num)return res;
        if(two==1){
            if(num<=BIT1[now+two]){
                return res+num*now;
            }
            else{
                return res+BIT1[now+two]*now+(num-BIT1[now+two])*(now+1);
            }
        }
        if(BIT1[now+two]<=num){            
            num-=BIT1[now+two];
            res+=BIT2[now+two];
            now+=two;
        }
        two>>=1;
    }
    return res;
}
int main(){
    DRI(n);
    REP(i,n){
        DRII(x,y);
        e[x].PB(y);
        if(x){
            add(BIT1,y+1,1);
            add(BIT2,y+1,y);
        }
    }
    REP(i,N){
        sort(ALL(e[i]));
        reverse(ALL(e[i]));
    }
    REP(i,N-1)d[i]=i+1;
    sort(d,d+N-1,compare);
    int an=2e9;
    int base_p=SZ(e[0]);
    int add_p=0;
    int need=0;
    for(int i=n;i>=1;i--){
        for(int j=N-2;j>=0;j--){
            int id=d[j];
            if(SZ(e[id])==i){
                int v=e[id][i-1];
                need+=v;
                add(BIT1,v+1,-1);
                add(BIT2,v+1,-v);
                e[id].pop_back();
                add_p++;
            }
            else break;
        }
        if(base_p+add_p>=i){
            an=min(an,need);
            break;
        }
        an=min(an,need+qq(i-base_p-add_p));
    }
    printf("%d\n",an);
    return 0;
}