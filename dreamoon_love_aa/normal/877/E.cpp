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
#define CASET int ___T; scanf("%d", &___T); for(int cs=1;cs<=___T;cs++)
#define MP make_pair
#define PB push_back
#define MS0(X) memset((X), 0, sizeof((X)))
#define MS1(X) memset((X), -1, sizeof((X)))
#define LEN(X) strlen(X)
#define PII pair<int,int>
#define VI vector<int>
#define VL vector<long long>
#define VPII vector<pair<int,int>>
#define PLL pair<long long,long long>
#define VPLL vector<pair<long long,long long>>
#define F first
#define S second
typedef int64_t LL;
using namespace std;
const int MOD = 1e9+7;
const int SIZE = 1e6+10;
int sum[SIZE],_tmp[SIZE];
int t[SIZE],v[SIZE],sz[SIZE];
void push(int id){
    if(_tmp[id]==0)return;
    _tmp[id*2]^=_tmp[id];
    sum[id*2]=sz[id*2]-sum[id*2];
    _tmp[id*2+1]^=_tmp[id];
    sum[id*2+1]=sz[id*2+1]-sum[id*2+1];
    _tmp[id]=0;
}
void pull(int id){
    sum[id]=sum[id*2]+sum[id*2+1];
}
void init(int L,int R,int id){
    if(L==R){
        sum[id]=v[L];
        sz[id]=1;
        return;
    }
    int mm=(L+R)/2;
    init(L,mm,id*2);
    init(mm+1,R,id*2+1);
    pull(id);
    sz[id]=sz[id*2]+sz[id*2+1];
}
int qq(int L,int R,int id,int ll,int rr){
    if(R<ll||L>rr)return 0;
    if(L>=ll&&R<=rr)return sum[id];
    int mm=(L+R)/2;
    push(id);
    return qq(L,mm,id*2,ll,rr)+qq(mm+1,R,id*2+1,ll,rr);
}
void ins(int L,int R,int id,int ll,int rr){
    if(R<ll||L>rr)return;
    if(L>=ll&&R<=rr){
        sum[id]=sz[id]-sum[id];
        _tmp[id]^=1;
        return;
    }
    int mm=(L+R)/2;
    push(id);
    ins(L,mm,id*2,ll,rr);
    ins(mm+1,R,id*2+1,ll,rr);
    pull(id);
}
VI e[SIZE];
int ll[SIZE],rr[SIZE],node_id;
void dfs(int x){
    ll[x]=rr[x]=node_id++;
    REP(i,SZ(e[x])){
        dfs(e[x][i]);
        rr[x]=rr[e[x][i]];
    }
}
int main(){
    DRI(n);
    REPP(i,2,n+1){
        DRI(x);
        e[x].PB(i);
    }
    REPP(i,1,n+1)RI(t[i]);
    dfs(1);
    REPP(i,1,n+1){
        v[ll[i]]=t[i];
    }
    init(0,n-1,1);
    DRI(q);
    while(q--){
        char s[12];
        RS(s);
        DRI(x);
        if(s[0]=='p'){
            ins(0,n-1,1,ll[x],rr[x]);
        }
        else{
            printf("%d\n",qq(0,n-1,1,ll[x],rr[x]));
        }
    }
    return 0;
}