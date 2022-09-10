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
#define SIZE 5010
int d[SIZE],a[SIZE];
void insert(int x){
    while(x<SIZE){
        d[x]++;
        x+=x&-x;
    }
}
int qq(int x){
    int res=0;
    while(x){
        res+=d[x];
        x-=x&-x;
    }
    return res;
}
int main(){
    int n;
    while(scanf("%d",&n)==1){
        int an=-50000000,an2=0,base=0;
        REPP(i,1,n+1){
            RI(a[i]);
            a[i]=a[i]+1;
        }
        REPP(i,1,n+1)REPP(j,i+1,n+1){
            if(a[i]>a[j])base++;
        }
        REPP(i,2,n+1){
            MS0(d);
            int cnt=0;
            for(int j=i-1;j>0;j--){
                int tmp=(a[j]>a[i])?1:-1;
                tmp+=cnt-qq(a[i])*2;
                tmp+=qq(a[j])*2-cnt;
                if(tmp>an){
                    an=tmp;
                    an2=1;
                }
                else if(tmp==an)an2++;
                insert(a[j]);
                cnt++;
            }
        }
        printf("%d %d\n",base-an,an2);
    }
    return 0;
}