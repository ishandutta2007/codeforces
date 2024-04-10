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
const int SIZE = 1<<20;
int t[SIZE],d[SIZE],dn;
int get(int v){
    return lower_bound(d,d+dn,v)-d;
}
int ma[SIZE],tmp[SIZE];
void push(int id){
    if(tmp[id]==0)return;
    tmp[id*2]+=tmp[id];
    ma[id*2]+=tmp[id];
    tmp[id*2+1]+=tmp[id];
    ma[id*2+1]+=tmp[id];
    tmp[id]=0;
}
void pull(int id){
    if(id*2+1<SIZE){
        ma[id]=max(ma[id*2],ma[id*2+1]);
    }
}
int qq(int L,int R,int id,int ll,int rr){
    if(R<ll||L>rr)return 0;
    if(L>=ll&&R<=rr)return ma[id];
    int mm=(L+R)/2;
    push(id);
    return max(qq(L,mm,id*2,ll,rr),qq(mm+1,R,id*2+1,ll,rr));
}
void ins(int L,int R,int id,int ll,int rr,int v){
    if(R<ll||L>rr)return;
    if(L>=ll&&R<=rr){
        ma[id]+=v;
        tmp[id]+=v;
        return;
    }
    int mm=(L+R)/2;
    push(id);
    ins(L,mm,id*2,ll,rr,v);
    ins(mm+1,R,id*2+1,ll,rr,v);
    pull(id);
}
int main(){
    DRII(n,T);
    REPP(i,1,n+1){
        RI(t[i]);
        t[i]=max(t[i]-i,0);
        d[i-1]=t[i];
    }
    sort(d,d+n);
    dn=unique(d,d+n)-d;
    REPP(i,1,n+1){
        if(t[i]+i>=T)continue;
        int me=get(t[i]);
        int v=qq(0,dn-1,1,0,me)+1;
        int me_v=qq(0,dn-1,1,me,me);
        int it=get(T-i);
        if(it>me+1)ins(0,dn-1,1,me+1,it-1,1);
        ins(0,dn-1,1,me,me,v-me_v);

    }
    printf("%d\n",qq(0,dn-1,1,0,dn-1));
    return 0;
}