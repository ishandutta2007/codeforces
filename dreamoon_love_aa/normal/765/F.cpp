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
const int INF = 1e9+7;
const int SIZE = 1e5+10;
template <class T>
void maa(T& x,T y){
    if(x<y)x=y;
}
template <class T>
void mii(T& x,T y){
    if(x>y)x=y;
}
int a[SIZE],d[SIZE],dn;
struct node{
    int ch[2],mi;
}tree[SIZE*400];
int top;
int root[2][SIZE];
int stk[SIZE],sn;
void upd_mi(int &id,int L,int R,int ll,int rr,int v){
    if(L>rr||R<ll)return;
    tree[++top]=tree[id];
    id=top;
    if(L>=ll&&R<=rr){
        mii(tree[id].mi,v);
        return;
    }
    int M=(L+R)>>1;
    upd_mi(tree[id].ch[0],L,M,ll,rr,v);
    upd_mi(tree[id].ch[1],M+1,R,ll,rr,v);
}
int qq_mi(int id,int L,int R,int x){
    if(L==R)return tree[id].mi;
    int mm=(L+R)/2;
    if(x<=mm)return min(tree[id].mi,qq_mi(tree[id].ch[0],L,mm,x));
    else return min(tree[id].mi,qq_mi(tree[id].ch[1],mm+1,R,x));
}
int ma[SIZE*4];
void upd_ma(int L,int R,int id,int x,int v){
    maa(ma[id],v);
    if(L==R){
        return;
    }
    int mm=(L+R)/2;
    if(x<=mm)upd_ma(L,mm,id*2,x,v);
    else upd_ma(mm+1,R,id*2+1,x,v);
}
int qq_ma(int L,int R,int id,int ll,int rr){
    if(rr<L||ll>R)return -1;
    if(L>=ll&&R<=rr)return ma[id];
    int mm=(L+R)/2;
    return max(qq_ma(L,mm,id*2,ll,rr),qq_ma(mm+1,R,id*2+1,ll,rr));
}
void build(int rt[],int N){
    MS1(ma);
    sn=0;
    tree[0].mi=INF;
    REP(i,N){
        if(i)rt[i]=rt[i-1];
        while(sn&&a[stk[sn-1]]>a[i])sn--;
        if(sn){
            int id=stk[sn-1];
            while(id!=-1){
                int v=d[a[i]]-d[a[id]];
                upd_mi(rt[i],0,N-1,0,id,v);
                if(!v)break;
                int lv=d[a[i]]-(v-1)/2;
                int it=lower_bound(d,d+dn,lv)-d;
                id=qq_ma(0,dn-1,1,it,a[i]);
            }
        }
        stk[sn++]=i;
        upd_ma(0,dn-1,1,a[i],i);
    }
}
int main(){
    DRI(N);
    REP(i,N){RI(a[i]);d[dn++]=a[i];}
    sort(d,d+dn);
    dn=unique(d,d+dn)-d;
    REP(i,N)a[i]=lower_bound(d,d+dn,a[i])-d;
    build(root[0],N);
    reverse(a,a+N);
    build(root[1],N);
    int ans=0;
    DRI(Q);
    REP(cs,Q){
        DRII(x,y);x--;y--;
        ans=min(qq_mi(root[0][y],0,N-1,x),qq_mi(root[1][N-1-x],0,N-1,N-1-y));
        printf("%d\n",ans);
    }
    return 0;
}