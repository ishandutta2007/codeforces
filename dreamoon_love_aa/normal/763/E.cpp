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
#define VI vector<int>
typedef long long LL;
using namespace std;
const int SIZE = 1e5+10;
int from[SIZE];
int an[SIZE];
struct data{
    int x,y,id;
    bool operator<(const data& b)const{
        return from[x]<from[b.x]||(from[x]==from[b.x]&&y<b.y);
    }
}qq[SIZE];
VI e[SIZE];
vector<pair<int*,int> >record;
void clear_record(int st=0){
    for(int i=SZ(record)-1;i>=st;i--)*record[i].F=record[i].S;
    record.resize(st);
}
struct Union_Find{
    int d[SIZE],num[SIZE];
    void init(int n){
        REP(i,n)d[i]=i,num[i]=1;
    }
    int find(int x){
        return (x!=d[x])?find(d[x]):x;
    }
    bool uu(int x,int y){
        x=find(x);
        y=find(y);
        if(x==y)return 0;
        if(num[x]>num[y])swap(x,y);
        record.PB(MP(&num[y],num[y]));
        num[y]+=num[x];
        record.PB(MP(&d[x],d[x]));
        d[x]=y;
        return 1;
    }
}U;
int main(){
    DRII(N,K);
    U.init(N);
    int sqN=sqrt(N+0.1);
    REP(i,N){
        from[i]=i/sqN;
    }
    DRI(m);
    while(m--){
        DRII(x,y);x--;y--;
        e[x].PB(y);
        e[y].PB(x);
    }
    DRI(Q);
    REP(i,Q){
        RII(qq[i].x,qq[i].y);
        qq[i].x--;qq[i].y--;
        qq[i].id=i;
    }
    sort(qq,qq+Q);
    int lt=-1;
    int dec=0;
    REP(i,Q){
        int x=qq[i].x,y=qq[i].y;
        if(from[x]==from[y]){
            dec=0;
            clear_record();
            REPP(j,x,y+1){
                REP(k,SZ(e[j])){
                    if(e[j][k]<x||e[j][k]>y)continue;
                    if(U.uu(j,e[j][k])){
                        dec++;
                    }
                }
            }
            lt=-1;
            an[qq[i].id]=y+1-x-dec;
            clear_record();
            continue;
        }
        int ed=from[x]*sqN+sqN;
        if(from[x]!=lt){
            dec=0;
            clear_record();
            REPP(j,ed,y+1){
                REP(k,SZ(e[j])){
                    if(e[j][k]<ed||e[j][k]>y)continue;
                    if(U.uu(j,e[j][k])){
                        dec++;
                    }
                }
            }
            lt=from[x];
        }
        else REPP(j,max(qq[i-1].y+1,ed),y+1){
            REP(k,SZ(e[j])){
                if(e[j][k]<ed||e[j][k]>y)continue;
                if(U.uu(j,e[j][k])){
                    dec++;
                }
            }
        }
        int dec2=0;
        int now_size=SZ(record);
        REPP(j,x,ed){
            REP(k,SZ(e[j])){
                if(e[j][k]<x||e[j][k]>y)continue;
                if(U.uu(j,e[j][k])){
                    dec2++;
                }
            }
        }
        an[qq[i].id]=y+1-x-dec-dec2;
        clear_record(now_size);
    }
    REP(i,Q)printf("%d\n",an[i]);
    return 0;
}