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
#define VPII vector<pair<int,int> >
#define PLL pair<long long,long long>
#define F first
#define S second
typedef long long LL;
using namespace std;
namespace io {
    const int SIZE = 1e7 + 10;
    char inbuff[SIZE];
    char *l, *r;
    inline void init() {
        l = inbuff;
        r = inbuff + fread(inbuff, 1, SIZE, stdin);
    }
    inline char gc() {
        if (l == r) init();
        return (l != r) ? *(l++) : EOF;
    }
    void read(int &x) {
        x = 0; char ch = gc();
        while(!isdigit(ch)) ch = gc();
        while(isdigit(ch)) x = x * 10 + ch - '0', ch = gc();
    }
} using io::read;
const int MOD = 1e9+7;
const int SIZE = 3e5+10;
int a[SIZE];
int from[SIZE];
int cnt[SIZE];
int ma;
LL an[SIZE];
struct data{
    int x,y,id;
    bool operator<(const data& b)const{
        return from[x]<from[b.x]||(from[x]==from[b.x]&&y<b.y);
    }
}qq[SIZE];
int main(){
    int N,Q;
    read(N);
    read(Q);
    int sqN=sqrt(N+0.1);
    REP(i,N){
        read(a[i]);
        from[i]=i/sqN;
    }
    REP(i,Q){
        read(qq[i].x);
        read(qq[i].y);
        qq[i].x--;qq[i].y--;
        qq[i].id=i;
    }
    sort(qq,qq+Q);
    int lt=-1;
    REP(i,Q){
        int x=qq[i].x,y=qq[i].y;
        int ed=min(from[x]*sqN+sqN,y+1);
        if(from[x]!=lt){
            MS0(cnt);
            ma=0;
            REPP(j,ed,y+1){
                cnt[a[j]]++;
                ma=max(ma,cnt[a[j]]);
            }
            lt=from[x];
        }
        else REPP(j,max(qq[i-1].y+1,ed),y+1){
            cnt[a[j]]++;
            ma=max(ma,cnt[a[j]]);
        }
        int tmp_ma=ma;
        REPP(j,x,ed){
            cnt[a[j]]++;
            ma=max(ma,cnt[a[j]]);
        }
        REPP(j,x,ed)cnt[a[j]]--;
        an[qq[i].id]=max(1,ma+ma-(qq[i].y-qq[i].x+1));
        ma=tmp_ma;
    }
    REP(i,Q)printf("%lld\n",an[i]);
    return 0;
}