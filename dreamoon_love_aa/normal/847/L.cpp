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
#define VL vector<long long>
#define VPII vector<pair<int,int> >
#define PLL pair<long long,long long>
#define VPLL vector<pair<long long,long long> >
#define F first
#define S second
typedef long long LL;
using namespace std;
const int MOD = 1e9+7;
const int SIZE = 1e3+10;
char s[SIZE*SIZE];
vector<VI>lit[SIZE];
VPII pp;
bool cmp(PII x,PII y){
    return SZ(lit[x.F][x.S])<SZ(lit[y.F][y.S]);
}
VI ee[SIZE];
VPII e;
bool u[SIZE],u_son[SIZE];
void add_edge(int x,int y){
    ee[x].PB(y);
    ee[y].PB(x);
}
void dfs(int x,int lt,VI& tmp){
    tmp.PB(x);
    REP(i,SZ(ee[x])){
        int y=ee[x][i];
        if(lt==y)continue;
        dfs(y,x,tmp);
    }
}
bool check(int id){
    vector<VI>gg;
    REP(i,SZ(ee[id])){
        VI tmp;
        dfs(ee[id][i],id,tmp);
        sort(ALL(tmp));
        gg.PB(tmp);
    }
    sort(ALL(gg));
    sort(ALL(lit[id]));
    return lit[id]==gg;
}
int main(){
    DRI(n);
    REPP(id,1,n+1){
        RS(s);
        for(int i=0;s[i];i++){
            if(s[i]==':'||s[i]=='-'||s[i]==',')s[i]=' ';
        }
        stringstream ss(s);
        int have_read=0;
        while(have_read<n-1){
            int num;
            ss>>num;
            lit[id].PB(VI());
            bool have_one=0;
            REP(j,num){
                int x;
                ss>>x;
                lit[id].back().PB(x);
                if(x==1)have_one=1;
            }
            sort(ALL(lit[id].back()));
            if(!have_one)pp.PB(MP(id,SZ(lit[id])-1));
            have_read+=SZ(lit[id].back());
        }
    }
    if(SZ(pp)!=n-1)return 0*puts("-1");
    sort(ALL(pp),cmp);
    REP(i,SZ(pp)){
        VI now=lit[pp[i].F][pp[i].S];
        //fprintf(stderr,"(");
        //REP(j,SZ(now))fprintf(stderr,"%d%c",now[j],",)"[j==(SZ(now)-1)]);
        int root=-1;
        VI sons;
        REP(j,SZ(now)){
            int x=now[j];
            if(!u[x]){
                root=x;
                u[x]=1;
            }
            else if(!u_son[x]){
                sons.PB(x);
                u_son[x]=1;
            }
        }
        if(root==-1)return 0*puts("-1");
        REP(j,SZ(sons)){
            e.PB(MP(sons[j],root));
            add_edge(root,sons[j]);
        }
    }
    REPP(i,2,n+1){
        if(!u_son[i]){
            e.PB(MP(1,i));
            add_edge(1,i);
        }
    }
    REPP(i,1,n+1){
        if(!check(i))return 0*puts("-1");
    }
    printf("%d\n",SZ(e));
    REP(i,SZ(e))printf("%d %d\n",e[i].F,e[i].S);
    return 0;
}