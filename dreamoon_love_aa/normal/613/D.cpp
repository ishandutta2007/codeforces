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
const int SIZE = 1e5+10;
map<int,int>pp[SIZE];
set<int>cc[SIZE];
map<int,int>*ptr[SIZE];
VI e[SIZE];
int gn[SIZE],an[SIZE];
void dfs(int x,int lt){
    ptr[x]=&(pp[x]);
    set<int>cr;
    REP(i,SZ(e[x])){
        int y=e[x][i];
        if(y==lt)continue;
        dfs(y,x);
        if(SZ(*ptr[x])<SZ(*ptr[y]))swap(ptr[x],ptr[y]);
        for(map<int,int>::iterator it=ptr[y]->begin();it!=ptr[y]->end();it++){
            int me=it->F;
            if(ptr[x]->count(me)){
                cr.insert(me);
            }
            (*ptr[x])[me]+=it->S;
        }
    }
    for(set<int>::iterator it=cc[x].begin();it!=cc[x].end();it++){
        if(ptr[x]->count(*it)){
            cr.erase(*it);
            an[*it]+=(*ptr[x])[*it];
        }
        (*ptr[x])[*it]=1;
    }
    for(set<int>::iterator it=cr.begin();it!=cr.end();it++){
        if(ptr[x]->count(*it)){
            ptr[x]->erase(*it);
            an[*it]++;
        }
    }
}
int main(){
    DRI(n);
    REPP(i,1,n){
        DRII(x,y);x--;y--;
        e[x].PB(y);
        e[y].PB(x);
    }
    DRI(q);
    REP(i,q){
        RI(gn[i]);
        REP(j,gn[i]){
            DRI(x);
            x--;
            cc[x].insert(i);
        }
    }
    REP(i,n){
        REP(j,SZ(e[i])){
            int y=e[i][j];
            if(y<i)continue;
            int x=i;
            if(SZ(cc[x])>SZ(cc[y]))swap(x,y);
            for(set<int>::iterator it=cc[x].begin();it!=cc[x].end();it++){
                if(an[*it]==-1)continue;
                if(cc[y].count(*it))an[*it]=-1000000000;
            }
        }
    }
    dfs(0,0);
    REP(i,q)printf("%d\n",max(-1,an[i]));
    return 0;
}