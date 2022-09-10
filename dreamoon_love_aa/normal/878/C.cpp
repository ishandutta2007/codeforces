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
const int SIZE = 5e5+10;
int s[SIZE][10],ord[SIZE];
LL ma[SIZE],_tmp[SIZE];
void push(int id){
    if(_tmp[id]==0)return;
    _tmp[id*2]+=_tmp[id];
    ma[id*2]+=_tmp[id];
    _tmp[id*2+1]+=_tmp[id];
    ma[id*2+1]+=_tmp[id];
    _tmp[id]=0;
}
void pull(int id){
    ma[id]=max(ma[id*2],ma[id*2+1]);
}
LL qq(int L,int R,int id,int ll,int rr){
    if(R<ll||L>rr)return -MOD;
    if(L>=ll&&R<=rr)return ma[id];
    int mm=(L+R)/2;
    push(id);
    return max(qq(L,mm,id*2,ll,rr),qq(mm+1,R,id*2+1,ll,rr));
}
void ins(int L,int R,int id,int ll,int rr,int v){
    if(R<ll||L>rr)return;
    if(L>=ll&&R<=rr){
        ma[id]+=v;
        _tmp[id]+=v;
        return;
    }
    int mm=(L+R)/2;
    push(id);
    ins(L,mm,id*2,ll,rr,v);
    ins(mm+1,R,id*2+1,ll,rr,v);
    pull(id);
}
int n,k;
bool valid(int x){
    return 0<=x&&x<n;
}
int ans[SIZE];
int top,exist[SIZE];
LL BIT[SIZE];
void ins_BIT(int x,LL v=1){
    x++;
    for(;x<SIZE;x+=x&-x)BIT[x]+=v;
}
LL qq_BIT(int x){
    x++;
    if(!x)return 0;
    LL res=0;
    for(;x;x-=x&-x)res+=BIT[x];
    return res;
}
int main(){
    RII(n,k);
    set<PII>H[10];
    REP(i,n)REP(j,k)RI(s[i][j]);
    VI d(n);
    REP(i,n)d[i]=s[i][0];
    sort(ALL(d));
    REP(i,n)ord[i]=lower_bound(ALL(d),s[i][0])-d.begin();
    REP(i,k){
        H[i].insert(MP(-1,-1));
        H[i].insert(MP(MOD,MOD));
        H[i].insert(MP(s[0][i],0));
    }
    REPP(i,1,n){
        REP(j,k){
            auto it=H[j].lower_bound(MP(s[i][j],i));
            if(valid(it->S)&&ord[it->S]<ord[i]){
                ins(1,n-1,1,ord[it->S]+1,ord[i],-1);
            }
            it--;
            if(valid(it->S)&&ord[i]<ord[it->S]){
                ins(1,n-1,1,ord[i]+1,ord[it->S],-1);
            }
            H[j].insert(MP(s[i][j],i));
        }
    }
    REP(i,n){
        exist[i]=1;
        ins_BIT(i);
    }
    top=n-1;
    for(int i=n-1;i>0;i--){
        while(!exist[top])top--;
        int ll=0,rr=top;
        while(ll<rr){
            int mm=(ll+rr+1)/2;
            if(qq(1,n-1,1,mm,top)==0)ll=mm;
            else rr=mm-1;
        }
        ans[i]=qq_BIT(top)-qq_BIT(ll-1);
        REP(j,k){
            auto it=H[j].lower_bound(MP(s[i][j],i));
            it++;
            if(valid(it->S)&&ord[it->S]<ord[i]){
                ins(1,n-1,1,ord[it->S]+1,ord[i],1);
            }
            it--;it--;
            if(valid(it->S)&&ord[i]<ord[it->S]){
                ins(1,n-1,1,ord[i]+1,ord[it->S],1);
            }
            H[j].erase(MP(s[i][j],i));
        }
        exist[ord[i]]=0;
        ins_BIT(ord[i],-1);
    }
    ans[0]=1;
    REP(i,n)printf("%d\n",ans[i]);
    return 0;
}