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
#define F first
#define S second
typedef long long LL;
using namespace std;
char s[200000][52];
int p[200000];
int d[200000],r[200000];
bool compare(int x,int y){
    return strcmp(s[x],s[y])<0;
}
int main(){
    DRI(n);
    REP(i,n){
        RS(s[2*i]);
        RS(s[2*i+1]);
    }
    REP(i,n){RI(p[i]);p[i]--;}
    REP(i,2*n)d[i]=i;
    sort(d,d+2*n,compare);
    REP(i,2*n)r[d[i]]=i;
    int now=-1;
    REP(i,n){
        int x=r[p[i]*2];
        int y=r[p[i]*2+1];
        if(min(x,y)>now)now=min(x,y);
        else if(max(x,y)>now)now=max(x,y);
        else{
            puts("NO");
            return 0;
        }
    }
    puts("YES");
    return 0;
}