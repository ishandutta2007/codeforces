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
#define VPII vector<pair<int,int> >
#define PLL pair<long long,long long>
#define VPLL vector<pair<long long,long long> >
#define F first
#define S second
typedef long long LL;
using namespace std;
const int MOD = 1e9+7;
const int SIZE = 1e6+10;
int a[SIZE],b[SIZE];
int main(){
    multiset<int>Ha,Hb,Ha2,Hb2;
    DRI(n);
    REP(i,n)RI(a[i]);
    REP(i,n)RI(b[i]);
    a[n]=-MOD;
    b[n]=MOD;
    LL an=0;
    int r1=0,r2=0;
    REP(i,n){
        while(r1<=n&&(SZ(Ha)==0||*Ha.rbegin()<*Hb.begin())){
            Ha.insert(a[r1]);
            Hb.insert(b[r1++]);
        }
        while(r2<=n&&(SZ(Ha2)==0||*Ha2.rbegin()<=*Hb2.begin())){
            Ha2.insert(a[r2]);
            Hb2.insert(b[r2++]);
        }
        //printf("(%d,%d)\n",r1,r2);
        an+=r2-r1;
        Ha.erase(Ha.find(a[i]));
        Hb.erase(Hb.find(b[i]));
        Ha2.erase(Ha2.find(a[i]));
        Hb2.erase(Hb2.find(b[i]));
    }
    cout<<an;
    return 0;
}