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
#define BLUE 1
#define RED 2
using namespace std;
vector<pair<int,int> >blue,red;
const int SIZE = 2000;
const int INF = 1e7;
struct data{
    int x,ty,id,ty2;
    data(int _x=0,int _ty=0,int _id=0,int _ty2=0):x(_x),ty(_ty),id(_id),ty2(_ty2){}
    bool operator<(const data& b)const{
        return x<b.x||(x==b.x&&ty2<b.ty2);
    }
};
int used[SIZE][SIZE],tt;
bool valid(int len){
    tt++;
    set<pair<int,int> >H;
    vector<data>vv;
    REP(i,SZ(blue)){
        vv.PB(data(blue[i].F,BLUE,i,1));
    }
    {
        vector<pair<pair<int,pair<int,int> >,int> >seg;
        REP(i,SZ(red)){
            seg.PB(MP(MP(red[i].S,MP(red[i].F-len,red[i].F+len)),i));
        }
        sort(ALL(seg));
        int tmp_id=0;
        for(int i=0,j;i<SZ(seg);i=j){
            int st=-1e9,ed=-1e9;
            for(j=i;j<SZ(seg)&&seg[j].F.F==seg[i].F.F;j++){
                if(seg[j].F.S.F>ed){
                    if(st!=int(-1e9)){
                        vv.PB(data(st,RED,tmp_id,0));
                        vv.PB(data(ed+1,RED,tmp_id,-1));
                    }
                    tmp_id=seg[j].S;
                    st=seg[j].F.S.F;
                    ed=seg[j].F.S.S;
                }
                else{
                    ed=max(ed,seg[j].F.S.S);
                }
            }
            vv.PB(data(st,RED,tmp_id,0));
            vv.PB(data(ed+1,RED,tmp_id,-1));
        }
    }
    sort(ALL(vv));
    for(int i=0,j;i<SZ(vv);i=j){
        if(vv[i].ty==BLUE){
            vector<pair<int,int> >seg;
            for(j=i;j<SZ(vv)&&vv[j].x==vv[i].x&&vv[j].ty==BLUE;j++){
                seg.PB(MP(blue[vv[j].id].S-len,blue[vv[j].id].S+len));
            }
            sort(ALL(seg));
            int st=-1e9,ed=-1e9;
            REP(k,SZ(seg)){
                if(seg[k].F>ed){
                    if(st!=int(-1e9)){
                        set<pair<int,int> >::iterator it=H.lower_bound(MP(st,0));
                        vector<int>now;
                        while(it!=H.end()&&it->F<=ed){
                            now.PB(it->S);
                            it++;
                        }
                        REP(i2,SZ(now))REPP(j2,i2+1,SZ(now)){
                            if(used[now[i2]][now[j2]]==tt)return true;
                            used[now[i2]][now[j2]]=used[now[j2]][now[i2]]=tt;
                        }
                    }
                    st=seg[k].F;
                    ed=seg[k].S;
                }
                else{
                    ed=max(seg[k].S,ed);
                }
            }
            {
                set<pair<int,int> >::iterator it=H.lower_bound(MP(st,0));
                vector<int>now;
                while(it!=H.end()&&it->F<=ed){
                    now.PB(it->S);
                    it++;
                }
                REP(i2,SZ(now))REPP(j2,i2+1,SZ(now)){
                    if(used[now[i2]][now[j2]]==tt)return true;
                    used[now[i2]][now[j2]]=used[now[j2]][now[i2]]=tt;
                }
            }
        }
        else{
            if(vv[i].ty2==0){
                H.insert(MP(red[vv[i].id].S,vv[i].id));
            }
            else{
                H.erase(MP(red[vv[i].id].S,vv[i].id));
            }
            j=i+1;
        }
    }
    return false;
}
int main(){
    DRII(n,m);
    if(n==1||m==1){
        puts("Poor Sereja!");
        return 0;
    }
    REP(i,n){
        DRII(x,y);
        blue.PB(MP(x+y,x-y));
    }
    REP(i,m){
        DRII(x,y);
        red.PB(MP(x+y,x-y));
    }
    int ll=1,rr=INF;
    while(ll<rr){
        int mm=(ll+rr)>>1;
        if(valid(mm*2))rr=mm;
        else ll=mm+1;
    }
    if(ll==INF)puts("Poor Sereja!");
    else printf("%d\n",ll);
    return 0;
}