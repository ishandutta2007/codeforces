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
#define VI vector<int>
#define VPII vector<pair<int,int> >
#define PLL pair<long long,long long>
#define VPLL vector<pair<long long,long long> >
#define F first
#define S second
typedef long long LL;
using namespace std;
const int MOD = 1e9+7;
const int SIZE = 2e5+10;
vector<pair<int,LL> > e[SIZE];
vector<LL>mat;
VI gg;
bool used[SIZE];
LL top[SIZE];
void dfs(int x,int lt){
    used[x]=1;
    gg.PB(x);
    REP(i,SZ(e[x])){
        int y=e[x][i].F;
        if(y==lt)continue;
        if(used[y]){
            mat.PB(top[y]^top[x]^e[x][i].S);
        }
        else{
            top[y]=top[x]^e[x][i].S;
            dfs(y,x);
        }
    }
}
void guess(){
    int now=0;
    for(int i=59;i>=0;i--){
        int j;
        for(j=now;j<SZ(mat);j++)
            if((mat[j]>>i)&1)break;
        if(j==SZ(mat))continue;
        if(j!=now)swap(mat[j],mat[now]);
        for(j=now+1;j<SZ(mat);j++){
            if((mat[j]>>i)&1){
                mat[j]^=mat[now];
            }
        }
        now++;
    }
    mat.resize(now);
}
LL C[64][64],two[64];
void ADD(LL&x,LL v){
    x=(x+v)%MOD;
    if(x<0)x+=MOD;
}
int main(){
    two[0]=1;
    REPP(i,1,64)two[i]=two[i-1]*2%MOD;
    REP(i,64){
        C[i][0]=1;
        REPP(j,1,i+1){
            C[i][j]=C[i-1][j-1]+C[i-1][j];
            if(C[i][j]>=MOD)C[i][j]-=MOD;
        }
    }
    DRII(n,m);
    REP(i,m){
        DRII(x,y);
        x--;y--;
        LL v;
        scanf("%I64d",&v);
        e[x].PB(MP(y,v));
        e[y].PB(MP(x,v));
    }
    LL an=0;
    REP(i,n){
        if(!used[i]){
            mat.clear();
            gg.clear();
            dfs(i,i);
            guess();
            int leaf[64][2]={},cy[64][2]={};
            REP(j,SZ(gg)){
                REP(k,60){
                    leaf[k][(top[gg[j]]>>k)&1]++;
                }
            }
            REP(j,SZ(mat)){
                REP(k,60){
                    cy[k][(mat[j]>>k)&1]++;
                }
            }
            LL all=leaf[0][0]+leaf[0][1];
            all=all*(all-1LL)/2;
            REP(k,60){
                ADD(an,(LL)leaf[k][0]*leaf[k][1]%MOD*two[cy[k][0]+max(0,cy[k][1]-1)]%MOD*two[k]);
                if(cy[k][1])ADD(an,(all-(LL)leaf[k][0]*leaf[k][1])%MOD*two[cy[k][0]+cy[k][1]-1]%MOD*two[k]);
            }
        }
    }
    cout<<an<<endl;
    return 0;
}