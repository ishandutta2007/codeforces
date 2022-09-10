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
int v[SIZE];
int tt;
map<int,int>sg;
int solve(int x){
    if(sg.count(x))return sg[x];
    int res=0,mask=0,tmp[32]={};
    for(int i=0;(1<<i)<=x;i++){
        tmp[solve((x&mask)|(x>>(i+1)))]=1;
        mask|=1<<i;
    }
    while(tmp[res])res++;
    return sg[x]=res;
}
int main(){
    sg[0]=0;
    map<int,int>H;
    DRI(n);
    REP(i,n){
        DRI(x);
        for(int j=2;j*j<=x;j++){
            if(x%j==0){
                int cnt=0;
                while(x%j==0){
                    cnt++;
                    x/=j;
                }
                H[j]|=1<<(cnt-1);
            }
        }
        if(x!=1)H[x]|=1;
    }
    int res=0;
    for(auto it=H.begin();it!=H.end();it++){
        res^=solve(it->S);
    }
    puts(res?"Mojtaba":"Arpa");
    return 0;
}