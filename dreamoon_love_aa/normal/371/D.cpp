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
const int SIZE = 200010;
int a[SIZE],nxt[SIZE],lst[SIZE],v[SIZE];
bool full[SIZE];
set<int>r;
int main(){
    DRI(n);
    REP(i,n)RI(a[i+1]),r.insert(i+1);
    REPP(i,1,n+1)nxt[i]=i+1,lst[i]=i-1;
    DRI(m);
    while(m--){
        DRI(ty);
        if(ty==1){
            DRII(p,x);
            set<int>::iterator it=r.lower_bound(p);
            if(it!=r.end()){
                int now=*it;
                while(now!=n+1&&x>0){
                    if(x>=a[now]-v[now]){
                        x-=a[now]-v[now];
                        full[now]=true;
                        nxt[lst[now]]=nxt[now];
                        lst[nxt[now]]=lst[now];
                        r.erase(now);
                        now=nxt[now];
                    }
                    else{
                        v[now]+=x;
                        break;
                    }
                }
            }
        }
        else{
            DRI(k);
            if(full[k])printf("%d\n",a[k]);
            else printf("%d\n",v[k]);
        }
    }
    return 0;
}