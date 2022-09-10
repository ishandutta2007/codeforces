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
const int SIZE = 100005;
int a[SIZE];
map<int,int> BIT[SIZE];
set<int>pos[SIZE];
int n,m;
void init(){
    int d[2]={0,n+1};
    REPP(i,1,n+1){
        pos[i]=set<int>(d,d+2);
    }
}
void ins(int x,int y0,int v){
    if(x==n+1||y0==n+1)return;
    x=n+1-x;
    for(;x<SIZE;x+=x&-x){
        for(int y=y0;y<SIZE;y+=y&-y){
            BIT[x][y]+=v;
        }
    }
}
LL qq(int x,int y0){
    x=n+1-x;
    LL res=0;
    for(;x;x-=x&-x){
        for(int y=y0;y;y-=y&-y){
            res+=BIT[x][y];
        }
    }
    return res;
}
void ch(int p,int y){
    int x=a[p];
    if(x==y)return;
    {
        auto it=pos[x].find(p);
        it++;
        int r_p=*it;
        it--;it--;
        int l_p=*it;
        it++;
        pos[x].erase(it);
        ins(p,r_p,p-r_p);
        ins(l_p,p,l_p-p);
        ins(l_p,r_p,r_p-l_p);
    }
    {
        auto it=pos[y].insert(p).F;
        it++;
        int r_p=*it;
        it--;it--;
        int l_p=*it;
        it++;
        ins(p,r_p,r_p-p);
        ins(l_p,p,p-l_p);
        ins(l_p,r_p,l_p-r_p);
    }
    a[p]=y;
}
int main(){
    RII(n,m);
    init();
    REPP(i,1,n+1){
        RI(a[i]);
        pos[a[i]].insert(i);
    }
    REPP(x,1,n+1){
        int lt=-1;
        for(auto it=pos[x].begin();it!=pos[x].end();it++){
            if(lt!=-1){
                ins(lt,*it,*it-lt);
            }
            lt=*it;
        }
    }
    REP(i,m){
        DRI(ty);
        if(ty==1){
            DRII(p,x);
            ch(p,x);
        }
        else{
            DRII(l,r);
            printf("%I64d\n",qq(l,r));
        }
    }
    return 0;
}