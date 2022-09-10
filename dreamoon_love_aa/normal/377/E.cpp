#include<stdio.h>
#include<string>
#include<math.h>
#include<stdlib.h>
#include<set>
#include<bitset>
#include<map>
#include<vector>
#include<string.h>
#include<algorithm>
#include<iostream>
#include<queue>
#define SZ(X) ((int)(X).size())
#define ALL(X) (X).begin(), (X).end()
#define REP(I, N) for (int I = 0; I < (N); ++I)
#define REPP(I, A, B) for (int I = (A); I < (B); ++I)
#define REPC(I, C) for (int I = 0; !(C); ++I)
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
#define X first
#define Y second
using namespace std;
const int SIZE = 200010;
const long long INF = 1e17;
const long long INF_half = 1e16+1e10;
struct data{
    long long v,c;
    data(long long _v=0,long long _c=0):v(_v),c(_c){}
    bool operator<(const data& b)const{
        return c<b.c||(c==b.c&&v>b.v);
    }
    void scan(){
        scanf("%I64d%I64d",&v,&c);
    }
}a[SIZE];
long long S;
struct Line{
    long long x,y;
    long long v;
    Line(long long _x=0,long long _y=0,long long _v=0):x(_x),y(_y),v(_v){}
    long long inter(const Line& b){
        long long ll,rr;
        ll=b.x;
        rr=(INF-b.y)/b.v+b.x;
        while(ll<rr){
            long long mm=(ll+rr)>>1;
            if(b.y+(mm-b.x)*b.v>=y+(mm-x)*v)rr=mm;
            else ll=mm+1;
        }
        if(rr==(INF-b.y)/b.v+b.x)return INF;
        return ll;
    }
}ss[SIZE];
long long over_pos[SIZE];
int sn;
void add_line(pair<long long,long long> st,long long v){
    if(st.Y>=INF)return;
    if(sn==0){
        ss[sn++]=Line(st.X,st.Y,v);
    }
    else{
        Line now=Line(st.X,st.Y,v);
        while(sn>1){
            long long tmp=ss[sn-2].inter(now);
            if(tmp==INF)return;
            if(tmp<=over_pos[sn-1]){
                if(tmp==over_pos[sn-1]&&tmp<ss[sn-1].inter(now))break;
                sn--;
            }
            else break;
        }
        over_pos[sn]=ss[sn-1].inter(now);
        if(over_pos[sn]<INF)ss[sn++]=now;
    }
}
pair<long long,long long> get_time(long long t){
    int ll=0,rr=sn-1;
    while(ll<rr){
        int mm=(ll+rr)>>1;
        if(ss[mm].y+(over_pos[mm+1]-1-ss[mm].x)*ss[mm].v<t)ll=mm+1;
        else rr=mm;
    }
    if(ss[ll].y>=t)return MP(ss[ll].x,ss[ll].y-t);
    long long need=(t-ss[ll].y+ss[ll].v-1)/ss[ll].v;
    return MP(ss[ll].x+need,ss[ll].y+ss[ll].v*need-t);
}
int main(){
    int n;
    scanf("%d%I64d",&n,&S);
    REP(i,n){
        a[i].scan();
    }
    sort(a,a+n);
    long long now=a[0].v;
    add_line(MP(0LL,0LL),a[0].v);
    for(int i=1;i<n;i++){
        if(a[i].v<=now)continue;
        pair<long long,long long> t=get_time(a[i].c);
        add_line(t,a[i].v);
        now=max(now,a[i].v);
    }
    pair<long long,long long> an=get_time(S);
    printf("%I64d\n",an.X);
    return 0;
}