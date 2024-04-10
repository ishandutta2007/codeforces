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
const int SIZE = 1e5+5;
vector<int>p[SIZE];
vector<pair<int,int> >vv;
bool Out(int x){
    return x<0||x>=SIZE;
}
int sk[SIZE];
int main(){
    int an=0;
    DRI(n);
    REP(i,n){
        DRII(x,y);
        p[x].PB(y);
    }
    REP(i,SIZE){
        sort(ALL(p[i]));
        if(p[i].size()>1)vv.PB(MP(SZ(p[i]),i));
    }
    sort(ALL(vv));
    int idx=0;
    for(;idx<SZ(vv)&&vv[idx].F<=300;idx++){
        int id=vv[idx].S;
        REP(i,SZ(p[id]))REPP(j,i+1,SZ(p[id])){
            int dif=abs(p[id][j]-p[id][i]);
            if(!Out(id-dif)){
                if(binary_search(ALL(p[id-dif]),p[id][j])&&binary_search(ALL(p[id-dif]),p[id][i])){
                    if(SZ(p[id-dif])<=300)an+=1;
                    else an+=2;
                }
            }
            if(!Out(id+dif)){
                if(binary_search(ALL(p[id+dif]),p[id][j])&&binary_search(ALL(p[id+dif]),p[id][i])){
                    if(SZ(p[id+dif])<=300)an+=1;
                    else an+=2;
                }
            }
        }
    }
    REPP(i,idx,SZ(vv)){
        sort(ALL(p[vv[i].S]));
    }
    REPP(i,idx,SZ(vv))REPP(j,i+1,SZ(vv)){
        int id1=vv[i].S;
        int id2=vv[j].S;
        int it1=0,it2=0;
        int sn=0,ll=0;
        int len=abs(id1-id2);
        while(it1<SZ(p[id1])&&it2<SZ(p[id2])){
            if(p[id1][it1]<p[id2][it2]){
                it1++;
            }
            else if(p[id1][it1]>p[id2][it2]){
                it2++;
            }
            else{
                int x=p[id1][it1];
                while(ll<sn&&sk[ll]<x-len)ll++;
                if(ll<sn&&sk[ll]==x-len)an+=2;
                sk[sn++]=x;
                it1++;it2++;
            }
        }
    }
    printf("%d\n",an/2);
    return 0;
}