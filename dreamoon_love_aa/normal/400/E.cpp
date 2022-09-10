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
const int  BB = 17;
const int SIZE = 1e5+5;
set<int>bit[BB];
int a[SIZE];
inline int get_bit(int x,int v){return (x>>v)&1;}
inline long long f(long long x){
    return x*(x+1)/2;
}
int main(){
    DRII(n,m);
    REPP(i,1,n+1){
        RI(a[i]);
        a[i]=(1<<BB)-1-a[i];
    }
    long long an=((1LL<<BB)-1)*f(n);
    long long ha=((1LL<<BB)-1)*f(n);
    REP(i,BB){
        int now=0;
        REPP(j,1,n+1){
            if(get_bit(a[j],i)){
                bit[i].insert(j);
                if(now){
                    an-=(1LL<<i)*f(now);
                    now=0;
                }
            }
            else{
                now++;
            }
        }
        if(now){
            an-=(1LL<<i)*f(now);
        }
    }
    while(m--){
        DRII(p,v);
        v=(1<<BB)-1-v;
        REP(i,BB){
            int pre_bit=get_bit(a[p],i);
            int nxt_bit=get_bit(v,i);
            if(pre_bit!=nxt_bit){
                if(pre_bit==0){
                    set<int>::iterator it=bit[i].lower_bound(p);
                    int pre,nxt;
                    if(it==bit[i].end())nxt=n+1;
                    else nxt=*it;
                    if(it==bit[i].begin())
                        pre=0;
                    else{
                        it--;
                        pre=*it;
                    }
                    an+=f(nxt-pre-1)*(1LL<<i);
                    an-=f(p-pre-1)*(1LL<<i);
                    an-=f(nxt-p-1)*(1LL<<i);
                    bit[i].insert(p);
                }
                else{
                    set<int>::iterator it=bit[i].upper_bound(p);
                    int pre,nxt;
                    if(it==bit[i].end())nxt=n+1;
                    else nxt=*it;
                    it--;
                    if(it==bit[i].begin())
                        pre=0;
                    else{
                        it--;
                        pre=*it;
                    }
                    an-=f(nxt-pre-1)*(1LL<<i);
                    an+=f(p-pre-1)*(1LL<<i);
                    an+=f(nxt-p-1)*(1LL<<i);
                    bit[i].erase(p);
                }
            }
        }
        a[p]=v;
        printf("%I64d\n",ha-an);
    }
    return 0;
}