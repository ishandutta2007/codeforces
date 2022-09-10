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
long long a,b;
long long sqr(long long x){return x*x;}
int main(){
    cin>>a>>b;
    if(a==0){
        cout<<-b*b<<endl;
        REP(i,b)printf("x");
        puts("");
        return 0;
    }
    int id=-1;
    long long ma=-1e18;
    for(int i=1;i<=a;i++){
        long long v=0;
        v+=sqr(a-(i-1))+i-1;
        int tmp=b%(i+1);
        v-=sqr(b/(i+1))*(i+1-tmp);
        v-=sqr(b/(i+1)+1)*tmp;
        if(v>ma){
            ma=v;
            id=i;
        }
    }
    cout<<ma<<endl;
    for(int i=0;i<=id;i++){
        if(i){
            if(i==1)
                REP(j,a-(id-1))putchar('o');
            else putchar('o');
        }
        int tmp=b/(id+1);
        if(i<b%(id+1))tmp++;
        REP(j,tmp)putchar('x');
    }
    puts("");
    return 0;
}