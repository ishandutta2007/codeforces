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
const int MOD = 1e9+7;
const int SIZE = 1e6+10;
map<int,int>p;
PII d[SIZE],d2[SIZE];
int dn,d2n;
LL BIT[SIZE];
void ins(int x,LL v){
    for(;x<SIZE;x+=x&-x)BIT[x]+=v;
}
LL qq(int x){
    LL res=0;
    for(;x;x-=x&-x)res+=BIT[x];
    return res;
}
int get(int x){
    return lower_bound(d,d+dn,MP(x,0))-d+1;
}
int main(){
    DRI(n);
    REP(i,n){
        DRII(x,y);
        if(!p.count(x))p[x]=x;
        if(!p.count(y))p[y]=y;
        swap(p[x],p[y]);
    }
    int lt=-1;
    for(map<int,int>::iterator it=p.begin();it!=p.end();it++){
        if(lt!=-1){
            if(lt+1<it->F){
                d[dn++]=MP(lt+1,it->F-lt-1);
            }
        }
        d[dn++]=MP(it->F,1);
        lt=it->F;
    }
    lt=-1;
    for(map<int,int>::iterator it=p.begin();it!=p.end();it++){
        if(lt!=-1){
            if(lt+1<it->F){
                d2[d2n++]=MP(get(lt+1),it->F-lt-1);
            }
        }
        d2[d2n++]=MP(get(it->S),1);
        lt=it->F;
    }
    LL an=0;
    for(int i=d2n-1;i>=0;i--){
        an+=(LL)d2[i].S*qq(d2[i].F-1);
        ins(d2[i].F,d2[i].S);
    }
    cout<<an<<endl;
    return 0;
}