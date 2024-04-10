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
const int MOD = 1e9+7;
const int SIZE = 1e5+10;
LL h[SIZE];
LL a[SIZE];
int m;
int get(LL x){
    return lower_bound(a,a+m,x)-a;
}
int ma[SIZE<<2],pos[SIZE<<2];
bool fresh(int& x,int v){
    if(x<v){
        x=v;
        return true;
    }
    return false;
}
void ins(int L,int R,int id,int x,int v,int ff){
    if(fresh(ma[id],v))pos[id]=ff;
    if(L==R){
        return;
    }
    int mm=(L+R)>>1;
    if(x<=mm)ins(L,mm,id*2,x,v,ff);
    else ins(mm+1,R,id*2+1,x,v,ff);
}
pair<int,int>qq(int L,int R,int id,int ll,int rr){
    if(ll>rr)return MP(-11111,0);
    if(L>=ll&&R<=rr){
        return MP(ma[id],pos[id]);
    }
    int mm=(L+R)>>1;
    if(mm>=rr)return qq(L,mm,id*2,ll,rr);
    if(mm+1<=ll)return qq(mm+1,R,id*2+1,ll,rr);
    pair<int,int>res1=qq(L,mm,id*2,ll,rr);
    pair<int,int>res2=qq(mm+1,R,id*2+1,ll,rr);
    if(res1.F>res2.F)return res1;
    return res2;
}
int from[SIZE],r1,r2,dp[SIZE];
void print(int x){
    if(dp[x]==1)printf("%d",x+1);
    else{
        print(from[x]);
        printf(" %d",x+1);
    }
}
int main(){
    memset(ma,0x80,sizeof(ma));
    DRII(n,d);
    REP(i,n){scanf("%I64d",&h[i]);a[i]=h[i];}
    sort(a,a+n);
    m=unique(a,a+n)-a;
    ins(0,m-1,1,get(h[0]),1,0);
    r1=1,r2=0;
    dp[0]=1;
    REPP(i,1,n){
        int rr=get(h[i]+d);
        pair<int,int>res1=qq(0,m-1,1,rr,m-1);
        int ll=get(h[i]-d+1)-1;
        pair<int,int>res2=qq(0,m-1,1,0,ll);
        if(res1.F<res2.F)res1=res2;
        if(res1.F>=1){
            res1.F++;
            dp[i]=res1.F;
            from[i]=res1.S;
            if(res1.F>r1){
                r1=res1.F;
                r2=i;
            }
        }
        else dp[i]=1;
        ins(0,m-1,1,get(h[i]),dp[i],i);
    }
    printf("%d\n",r1);
    print(r2);
    puts("");
    return 0;
}