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
void print_array(int arr[],int n){
    REP(i,n){
        if(i)printf(" ");
        printf("%d",arr[i]);
    }
    puts("");
}
bool valid(int n){
    REPP(i,1,n){
        if(i%2==1){
            if(b[i]<b[i-1])return 0;
        }
        else{
            if(b[i]>b[i-1])return 0;
        }
    }
    return 1;
}
int main(){
    DRI(n);
    REP(i,n)RI(a[i]);
    sort(a,a+n);
    int now=0;
    REP(i,n){
        if(now>=n)now=1;
        b[now]=a[i];
        now+=2;
    }
    if(valid(n)){
        print_array(b,n);
        return 0;
    }
    now=n-2;
    REP(i,n){
        if(now<0)now=n-1;
        b[now]=a[i];
        now-=2;
    }
    if(valid(n)){
        print_array(b,n);
        return 0;
    }
    puts("Impossible");
    return 0;
}