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
struct Union_Find{
    int d[SIZE],num[SIZE];
    void init(int n){
        REP(i,n)d[i]=i,num[i]=1;
    }
    int find(int x){
        return (x!=d[x])?(d[x]=find(d[x])):x;
    }
    bool uu(int x,int y){
        x=find(x);
        y=find(y);
        if(x==y)return 0;
        if(num[x]>num[y])swap(x,y);
        num[y]+=num[x];
        d[x]=y;
        return 1;
    }
}U;
int l[SIZE],r[SIZE];
int main(){
    DRI(n);
    U.init(n+1);
    REPP(i,1,n+1){
        RII(l[i],r[i]);
        if(l[i])U.uu(l[i],i);
        if(r[i])U.uu(r[i],i);
    }
    map<int,int>L,R;
    REPP(i,1,n+1){
        if(!l[i])L[U.find(i)]=i;
        if(!r[i])R[U.find(i)]=i;
    }
    auto it_L=L.begin();
    auto it_R=R.begin();
    int lt=-1;
    while(it_L!=L.end()){
        if(lt!=-1){
            r[lt]=it_L->S;
            l[it_L->S]=lt;
        }
        lt=it_R->S;
        it_L++;
        it_R++;
    }
    REPP(i,1,n+1)printf("%d %d\n",l[i],r[i]);
    return 0;
}