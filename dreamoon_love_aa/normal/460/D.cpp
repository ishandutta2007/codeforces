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
vector<LL>an;
LL mi;
LL l,r;
int K;
void dfs(LL x,LL v,int num,int used){
    if(x>r){
        if(num==0)return;
        if(v<mi){
            mi=v;
            an.clear();
            REP(i,20){
                if((used>>i)&1)an.PB(l+i);
            }
            return;
        }
        return;
    }
    if(num<K)dfs(x+1,v^x,num+1,used^(1<<(x-l)));
    dfs(x+1,v,num,used);
}
int main(){
    mi=1e18;
    cin>>l>>r>>K;
    if(K>=3){
        vector<LL>sp;
        REPP(i,1,50){
            sp.PB((1LL<<i)-1);
            REP(j,i)sp.PB((1LL<<i)^(1LL<<j));
        }
        REP(i,SZ(sp))
            REP(j,i){
                if(sp[i]>=l&&sp[i]<=r&&sp[j]>=l&&sp[j]<=r&&(sp[i]^sp[j])>=l&&(sp[i]^sp[j])<=r){
                    if(mi){
                        mi=0;
                        an.PB(sp[i]);
                        an.PB(sp[j]);
                        an.PB(sp[i]^sp[j]);
                    }
                }
            }
    }
    if(r>l+18)r=l+18;
    dfs(l,0,0,0);
    cout<<mi<<endl;
    printf("%d\n",SZ(an));
    REP(i,SZ(an)){
        if(i)putchar(' ');
        cout<<an[i];
    }
    puts("");
    return 0;
}