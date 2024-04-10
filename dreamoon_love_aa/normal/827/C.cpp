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
const int SIZE = 1e5+20;
char s[SIZE];
int n;
int BIT[4][11][SIZE];
int to(char c){
    if(c=='A')return 0;
    if(c=='C')return 1;
    if(c=='G')return 2;
    if(c=='T')return 3;
}
void ins(int bit[],int x,int v){
    x++;
    for(;x<SIZE;x+=x&-x)bit[x]+=v;
}
int qq(int bit[],int x){
    x++;
    int res=0;
    for(;x;x-=x&-x)res+=bit[x];
    return res;
}
int trans(int l,int pos){
    int r=pos%l;
    return r*(n+l-1)/l+pos/l;
}
void build(){
    n=LEN(s);
    REP(i,n)s[i]=to(s[i]);
    REPP(l,1,11){
        REP(i,n)ins(BIT[s[i]][l],trans(l,i),1);
    }
}
int edit(int x,char c){
    c=to(c);
    char o=s[x];
    if(o!=c){
        s[x]=c;
        REPP(l,1,11){
            ins(BIT[o][l],trans(l,x),-1);
            ins(BIT[c][l],trans(l,x),1);
        }
    }
}
int solve(char ss[],int l,int r){
    int m=LEN(ss),ret=0;
    REP(i,m)ss[i]=to(ss[i]);
    REP(i,m){
        if(i+l>=r)break;
        int ll=l+i;
        int rr=(r-1-ll)/m*m+ll;
        while(rr>=r)rr-=m;
        ret+=qq(BIT[ss[i]][m],trans(m,rr))-qq(BIT[ss[i]][m],trans(m,ll)-1);
    }
    return ret;
}
int main(){
    RS(s);
    build();
    DRI(Q);
    while(Q--){
        DRI(ty);
        if(ty==1){
            DRI(x);
            char c[4];
            x--;
            RS(c);
            edit(x,c[0]);
        }
        else{
            DRII(l,r);l--;
            char ss[24];
            RS(ss);
            printf("%d\n",solve(ss,l,r));
        }
    }
    return 0;
}