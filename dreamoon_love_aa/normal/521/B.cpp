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
const int MOD = 1e9+9;
const int SIZE = 1e5+10;
int x[SIZE],y[SIZE];
vector<int>e[SIZE],from[SIZE];
int sup[SIZE];
bool used[SIZE];
int an[SIZE];
set<int>can;
bool test(int i){
    if(used[i])return 0;
    bool stop=0;
    REP(j,SZ(e[i])){
        if(sup[e[i][j]]==1){
            return 0;
            break;
        }
    }
    return 1;
}
void remove(int x){
    used[x]=1;
    can.erase(x);
    sup[x]=0;
    REP(i,SZ(from[x])){
        int y=from[x][i];
        if(test(y)){
            can.insert(y);
        }
    }
    REP(i,SZ(e[x])){
        int y=e[x][i];
        if(used[y])continue;
        sup[y]--;
        REP(j,SZ(from[y])){
            int z=from[y][j];
            if(used[z])continue;
            if(test(z))can.insert(z);
            else{
                if(can.count(z))can.erase(z);
            }

        }
    }
}
int main(){
    map<PII,int>H;
    DRI(n);
    REP(i,n){
        RII(x[i],y[i]);
        H[MP(x[i],y[i])]=i;
    }
    REP(i,n){
        REPP(k,-1,2){
            int nx=x[i]+k;
            int ny=y[i]+1;
            if(H.count(MP(nx,ny))){
                int you=H[MP(nx,ny)];
                from[you].PB(i);
                e[i].PB(you);
                sup[you]++;
            }
        }
    }
    REP(i,n){
        if(test(i))can.insert(i);
    }
    REP(i,n){
        if(i&1){
            an[i]=*can.begin();
        }
        else{
            an[i]=*can.rbegin();
        }
        remove(an[i]);
    }
    LL res=0;
    REP(i,n){
        res*=n;
        res+=an[i];
        res%=MOD;
    }
    cout<<res<<endl;
    return 0;
}