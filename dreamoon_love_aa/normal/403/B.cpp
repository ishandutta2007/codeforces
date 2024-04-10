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
bitset<33000>p;
int pn,pp[33333];
void init(){
    for(int i=2;i<33000;i++){
        if(!p[i]){
            for(int j=i+i;j<33000;j+=i)p[j]=1;
        }
    }
    for(int i=2;i<33000;i++){
        if(!p[i])pp[pn++]=i;
    }
}
struct data{
    int first,second;
    int num;
    data(int _first=0,int _second=0,int _num=0):first(_first),second(_second),num(_num){}
    bool operator<(const data& bb)const{return first<bb.first||(first==bb.first&&second<bb.second);}
};
vector<data>d;
int b[5555],a[5555];
int main(){
    init();
    int an=0;
    DRII(n,m);
    REP(i,n)RI(a[i]);
    REP(i,m)RI(b[i]);
    for(int i=n-1;i>=0;i--){
        int gg=a[0],now=0;
        REP(j,i+1)gg=__gcd(gg,a[j]);
        int id=0,gg2=gg;
        for(int j=0;pp[j]*pp[j]<=gg2;j++){
            int cnt=0;
            while(gg2%pp[j]==0){
                gg2/=pp[j];
                cnt++;
            }
                while(id<m&&b[id]<pp[j])id++;
            if(cnt){
                if(id<m&&b[id]==pp[j])now-=cnt;
                else now+=cnt;
            }
        }
        if(gg2!=1){
            while(id<m&&b[id]<gg2)id++;
            if(id<m&&b[id]==gg2)now--;
            else now++;
        }
        if(now<0){
            REP(j,i+1)a[j]/=gg;
        }
        gg2=a[i];
        id=0;
        for(int j=0;pp[j]*pp[j]<=gg2;j++){
            int cnt=0;
            while(gg2%pp[j]==0){
                gg2/=pp[j];
                cnt++;
            }
            while(id<m&&b[id]<pp[j])id++;
            if(cnt){
                if(id<m&&b[id]==pp[j])an-=cnt;
                else an+=cnt;
            }
        }
        if(gg2!=1){
            while(id<m&&b[id]<gg2)id++;
            if(id<m&&b[id]==gg2)an--;
            else an++;
        }
    }
    printf("%d\n",an);
    return 0;
}