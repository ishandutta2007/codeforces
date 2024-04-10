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
const int SIZE = 1e6+10;
const int INF = 2147483647;
template <class T>
void maa(T& x,T y){
    if(x<y)x=y;
}
template <class T>
void mii(T& x,T y){
    if(x>y)x=y;
}
int a[SIZE];
// before $ll$ have had $cul$.
int record[SIZE][3],rn;
void update_answer(int ll,int rr,int cul){
#ifdef HOME
    printf("[%d,%d,%d]\n",ll,rr,cul);
#endif
    record[rn][0]=ll;
    record[rn][1]=rr;
    record[rn][2]=cul;
    rn++;
}
int C,l[SIZE],r[SIZE],c[SIZE],cn,cc_pos[SIZE];
PII cc[SIZE];
VPII qq;
int single_add[SIZE];
int kerker[SIZE];
set<PII>singles;
PII BIT[SIZE][2];
void ins(int x,int v){
    PII me=MP(v,x);
    for(;x<SIZE;x+=x&-x){
        if(me>BIT[x][0]){
            if(BIT[x][0].S!=me.S){
                BIT[x][1]=BIT[x][0];
            }
            BIT[x][0]=me;
        }
        else if(me>BIT[x][1]){
            BIT[x][1]=me;
        }
    }
}
int qq_BIT(int x,int id){
    int res=0;
    for(;x;x-=x&-x){
        if(BIT[x][0].S!=id)res=max(res,BIT[x][0].F);
        else res=max(res,BIT[x][1].F);
    }
    return res;
}
void update_single(int id,int v){
    single_add[id]+=v;
    ins(cc_pos[id],single_add[id]);
}
int get_single_ma(int id){
    int it=upper_bound(cc+1,cc+cn,MP(C-c[id],INF))-cc-1;
    if(it){
        return qq_BIT(it,cc_pos[id]);
    }
    return 0;
}
PII GP(int x,int y){
    if(x>y)return MP(y,x);
    return MP(x,y);
}
int an[SIZE];
int main(){
    int n;
    RII(n,C);
    VPII rain;
    cn=1;
    REPP(i,1,n+1){
        RIII(l[i],r[i],c[i]);
        rain.PB(MP(l[i],i));
        rain.PB(MP(r[i],-i));
        cc[cn++]=MP(c[i],i);
    }
    sort(cc+1,cc+cn);
    REPP(i,1,cn)cc_pos[cc[i].S]=i;
    sort(ALL(rain));
    rain.PB(MP(2000000000,0));
    DRI(m);
    REP(i,m){
        DRI(x);
        qq.PB(MP(x,i));
    }
    sort(ALL(qq));
    map<PII,int>pair_add;
    set<int>now;
    int zero=0;
    int pair_ma=0;
    if(rain[0].F){
        update_answer(0,rain[0].F,0);
        zero+=rain[0].F;
    }
    for(int i=0,j;i<2*n;i=j){
        for(j=i;j<2*n&&rain[j].F==rain[i].F;j++){
            int id=rain[j].S;
            if(id<0){
                now.erase(-id);
            }
            else{
                now.insert(id);
            }
        }
        if(SZ(now)==0){
            update_answer(rain[i].F,rain[j].F,zero+max(pair_ma,get_single_ma(0)));
            zero+=rain[j].F-rain[i].F;
        }
        else if(SZ(now)==1){
            int me=*now.begin();
            if(c[me]<=C){
                int v=single_add[me]+max(get_single_ma(me),kerker[me]);
                update_answer(rain[i].F,rain[j].F,zero+v);
                update_single(me,rain[j].F-rain[i].F);
                maa(pair_ma,v+rain[j].F-rain[i].F);
            }
        }
        else if(SZ(now)==2){
            int me=*now.begin();
            int you=*now.rbegin();
            if(c[me]+c[you]<=C){
                update_answer(rain[i].F,rain[j].F,zero+single_add[me]+single_add[you]+pair_add[GP(me,you)]);
                pair_add[GP(me,you)]+=rain[j].F-rain[i].F;
                maa(pair_ma,single_add[me]+single_add[you]+pair_add[GP(me,you)]);
                maa(kerker[me],pair_add[GP(me,you)]+single_add[you]);
                maa(kerker[you],pair_add[GP(me,you)]+single_add[me]);
            }
        }
    }
    {
        int it=0;
        REP(i,rn){
            while(it<m&&record[i][1]-record[i][0]+record[i][2]>=qq[it].F){
                an[qq[it].S]=record[i][0]+(qq[it].F-record[i][2]);
                it++;
            }
        }
    }
    REP(i,m)printf("%d\n",an[i]);
    return 0;
}