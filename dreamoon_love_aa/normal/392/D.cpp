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
#define F first
#define S second
using namespace std;
const int SIZE = 1e5+3;
const int INF = 1e8;
multiset<int>H;
set<pair<int,int> >pp;
int n,rn,hn,mi,ep;
struct data{
    int v,pos,line;
    data(int _v=0,int _pos=0,int _line=0):v(_v),pos(_pos),line(_line){}
    bool operator<(const data& b)const{return v<b.v||(v==b.v&&pos>b.pos);}
}r[SIZE*3];
struct data2{
    int d[3];
    data2(int _x=INF,int _y=INF,int _z=INF){
        d[0]=_x;
        d[1]=_y;
        d[2]=_z;
    }
    bool operator<(const data2& b)const{
        return d[0]<b.d[0];
    }
}ha[SIZE*3];
int get(){
    if(SZ(pp)==0)return 0;
    if(SZ(pp)==1)return min(pp.begin()->F,pp.begin()->S);
    return min(*H.begin(),min(pp.begin()->S,pp.rbegin()->F));
}
void ins(int x,int y){
    if(SZ(pp)==0){
        pp.insert(MP(x,y));
    }
    else{
        set<pair<int,int> >::iterator it=pp.lower_bound(MP(x,y));
        int ly=INF;
        if(it!=pp.end()){
            if(y<=it->S)return;
            H.insert(x+it->S);
            ly=it->S;
        }
        set<pair<int,int> >::iterator it2=it;
        bool good=false;
        while(it2!=pp.begin()){
            it2--;
            if(it2->S>y){
                H.insert(it2->F+y);
                if(ly!=INF){
                    H.erase(H.find(it2->F+ly));
                }
                it2++;
                pp.erase(it2,it);
                good=true;
                break;
            }
            if(ly!=INF)H.erase(H.find(it2->F+ly));
            ly=it2->S;
        }
        if(!good){
            pp.erase(pp.begin(),it);
        }
        pp.insert(MP(x,y));
    }
}
int main(){
    RI(n);
    REP(i,3){
        REP(j,n){
            DRI(x);
            r[rn++]=data(x,j+1,i);
        }
    }
    sort(r,r+rn);
    for(int i=0,j;i<rn;i=j,hn++){
        REP(k,3){
            ha[hn].d[k]=INF+ep;
            ep++;
        }
        for(j=i;j<rn&&r[j].v==r[i].v;j++){
            ha[hn].d[r[j].line]=r[j].pos;
        }
    }
    sort(ha,ha+hn);
    int an=INF;
    int now=n,id=hn-1;
    while(now>=0){
        while(id>=0&&ha[id].d[0]>now){
            ins(ha[id].d[1],ha[id].d[2]);
            //printf("{%d,%d}",id,ha[id].d[0]);
            id--;
        }
        //printf("[%d]:%d\n",now,get());
        an=min(an,now+get());
        now--;
    }
    cout<<an<<endl;
    return 0;
}