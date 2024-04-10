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
const int INF = 1e9+7;
const int SIZE = 1e6+10;
int R,N;
int in[SIZE][3];
PII R_R[SIZE];
VPII pp;
bool cmp(PII x,PII y){
    if((x.S>=0)!=(y.S>=0)){
        return x.S<y.S;
    }
    return (LL)x.F*y.S-(LL)x.S*y.F>0;
}
PII sat[SIZE],ll[SIZE],rr[SIZE];
int sid;
int my_gcd(int x,int y){
    x=abs(x);y=abs(y);
    if(!x||!y)return x+y;
    return __gcd(x,y);
}
PII get_left(int x,int y){
    x+=R;
    int gg=my_gcd(x,y);
    x/=gg;
    y/=gg;
    return MP(x,y);
}
PII get_right(int x,int y){
    x-=R;
    int gg=my_gcd(x,y);
    x/=gg;
    y/=gg;
    if(x<=0)return MP(y,-x);
    return MP(y,-x);
}
int mi[SIZE*4];
multiset<int>ker[SIZE*2];
void ins(int L,int R,int id,int x,int v){
    if(L==R){
        mi[id]=v;
        return;
    }
    int mm=(L+R)/2;
    if(x<=mm)ins(L,mm,id*2,x,v);
    else ins(mm+1,R,id*2+1,x,v);
    mi[id]=min(mi[id*2],mi[id*2+1]);

}
int qq(int L,int R,int id,int x,int y){
    if(L>y||R<x)return INF;
    if(L>=x&&R<=y){
        return mi[id];
    }
    int mm=(L+R)/2;
    return min(qq(L,mm,id*2,x,y),qq(mm+1,R,id*2+1,x,y));
}
int main(){
    sid=0;
    RII(R,N);
    REP(i,N){
        RII(in[i][0],in[i][1]);
        if(in[i][0]!=2)RI(in[i][2]);
        if(in[i][0]==1){
            int x=in[i][1];
            int y=in[i][2];
            sid++;
            ll[sid]=get_left(x,y),rr[sid]=get_right(x,y);
            pp.PB(ll[sid]);
            pp.PB(rr[sid]);
            in[i][1]=sid;
        }
    }
    sort(ALL(pp),cmp);
    pp.resize(unique(ALL(pp))-pp.begin());
    map<PII,int>get_id;
    REP(i,SZ(pp))get_id[pp[i]]=i+1;
    REPP(i,1,sid+1)R_R[i]=MP(get_id[rr[i]],get_id[ll[i]]);
    memset(mi,0x7f,sizeof(mi));
    REP(i,N){
        if(in[i][0]==1){
            ker[R_R[in[i][1]].S].insert(R_R[in[i][1]].F);
            ins(1,sid*2,1,R_R[in[i][1]].S,*ker[R_R[in[i][1]].S].begin());
        }
        else if(in[i][0]==2){
            ker[R_R[in[i][1]].S].erase(ker[R_R[in[i][1]].S].find(R_R[in[i][1]].F));
            int v=1e9;
            if(ker[R_R[in[i][1]].S].begin()!=ker[R_R[in[i][1]].S].end())v=*ker[R_R[in[i][1]].S].begin();
            ins(1,sid*2,1,R_R[in[i][1]].S,v);
        }
        else{
            int x=max(R_R[in[i][1]].F,R_R[in[i][2]].F);
            int y=min(R_R[in[i][1]].S,R_R[in[i][2]].S);
            if(x>y)puts("NO");
            else{
                
                ker[R_R[in[i][1]].S].erase(ker[R_R[in[i][1]].S].find(R_R[in[i][1]].F));
                int v=1e9;
                if(ker[R_R[in[i][1]].S].begin()!=ker[R_R[in[i][1]].S].end())v=*ker[R_R[in[i][1]].S].begin();
                ins(1,sid*2,1,R_R[in[i][1]].S,v);
                
                ker[R_R[in[i][2]].S].erase(ker[R_R[in[i][2]].S].find(R_R[in[i][2]].F));
                v=1e9;
                if(ker[R_R[in[i][2]].S].begin()!=ker[R_R[in[i][2]].S].end())v=*ker[R_R[in[i][2]].S].begin();
                ins(1,sid*2,1,R_R[in[i][2]].S,v);

                int res=qq(1,sid*2,1,y,sid*2);
                if(res>x)puts("YES");
                else puts("NO");
                ker[R_R[in[i][1]].S].insert(R_R[in[i][1]].F);
                ins(1,sid*2,1,R_R[in[i][1]].S,*ker[R_R[in[i][1]].S].begin());
                ker[R_R[in[i][2]].S].insert(R_R[in[i][2]].F);
                ins(1,sid*2,1,R_R[in[i][2]].S,*ker[R_R[in[i][2]].S].begin());
            }
        }
    }
    return 0;
}