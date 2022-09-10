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
const int MOD = 1e9+7;
const int SIZE = 4e5+10;
// template end here

const int MAXLEN = (int)4e5 + 5;

char s[MAXLEN];
int SA[MAXLEN], cnt[MAXLEN], ary1[MAXLEN], ary2[MAXLEN];
int *Rank, *Height;


inline bool cmp(int *r, int a, int b, int l) {
    return r[a] == r[b] && r[a + l] == r[b + l];
}

void make_suffix_array(int MSIZE, int len) {
    int p, *x, *y, *tmp, i, j, k;
    x = ary1; y = ary2;
    memset(cnt, 0, sizeof(int) * MSIZE);
    for (i = 0; i < len; i++) cnt[x[i] = s[i]]++;
    for (i = 1; i < MSIZE; i++) cnt[i] += cnt[i - 1];
    for (i = len - 1; i >= 0; i--) SA[--cnt[x[i]]] = i;
    for (j = p = 1; p < len; j <<= 1, MSIZE = p) {
        for (p = 0, i = len - j; i < len; i++) y[p++] = i;
        for (i = 0; i < len; i++) {
            if (SA[i] >= j) y[p++] = SA[i] - j;
        }
        memset(cnt, 0, sizeof(int) * MSIZE);
        for (i = 0; i < len; i++) cnt[x[y[i]]]++;
        for (i = 1; i < MSIZE; i++) cnt[i] += cnt[i - 1];
        for (i = len - 1; i >= 0; i--) SA[--cnt[x[y[i]]]] = y[i];
        tmp = x; x = y; y = tmp;
        x[SA[0]] = 0;
        for (i = p = 1; i < len; i++) {
            x[SA[i]] = cmp(y, SA[i - 1], SA[i], j) ? p - 1 : p++;
        }
    }
    Rank = x;
    Height = y;
    for (i = k = 0; i < len - 1; i++) {
        if (k > 0) k--;
        j = SA[Rank[i] - 1];
        while (s[i + k] == s[j + k]) k++;
        Height[Rank[i]] = k;
    }
}
int st[SIZE],len[SIZE],from[SIZE],two[SIZE];
int ma[19][SIZE];
int rmq(int L,int R){
    int lv=two[R-L+1];
    return min(ma[lv][L],ma[lv][R-(1<<lv)+1]);
}
int L[SIZE],R[SIZE];
int BIT[SIZE];
int an[500001];
void ins(int x){
    x++;
    for(;x<SIZE;x+=x&-x)BIT[x]++;
}
int qq(int x){
    x++;
    int res=0;
    for(;x;x-=x&-x)res+=BIT[x];
    return res;
}
VPII ker[SIZE];
int main(){
    for(int i=2;i<SIZE;i++)two[i]=two[i>>1]+1;
    MS1(from);
    DRII(n,q);
    int now=0;
    REP(i,n){
        RS(s+now);
        st[i]=now;
        from[now]=i;
        len[i]=strlen(s+now);
        now+=len[i];
        s[now]='a'-1;
        now++;
    }
    s[now-1]=0;
    make_suffix_array(128,now);
    REP(i,now)ma[0][i]=Height[i];
    REPP(i,1,19){
        REP(j,now){
            if(j+(1<<i)<=now)ma[i][j]=min(ma[i-1][j],ma[i-1][j+(1<<(i-1))]);
        }
    }
    REP(i,n){
        int me=Rank[st[i]];
        int ll=0,rr=me+1;
        while(ll<rr){
            int mm=(ll+rr)>>1;
            if(rmq(mm,me)>=len[i])rr=mm;
            else ll=mm+1;
        }
        L[i]=ll-1;
        ll=me;
        rr=now-1;
        while(ll<rr){
            int mm=(ll+rr+1)>>1;
            if(rmq(me+1,mm)>=len[i])ll=mm;
            else rr=mm-1;
        }
        R[i]=ll;
    }
    REP(i,q){
        DRIII(x,y,z);
        x--;y--;z--;
        ker[R[z]].PB(MP(st[y]+len[y]-1,i+1));
        ker[R[z]].PB(MP(st[x]-1,-i));
        if(L[z]){
            ker[L[z]-1].PB(MP(st[y]+len[y]-1,-i));
            ker[L[z]-1].PB(MP(st[x]-1,i+1));
        }
    }
    REP(i,now){
        ins(SA[i]);
        REP(j,SZ(ker[i])){
            int id,ty;
            if(ker[i][j].S>0){
                id=ker[i][j].S-1;
                ty=1;
            }
            else{
                id=-ker[i][j].S;
                ty=-1;
            }
            an[id]+=qq(ker[i][j].F)*ty;
        }
    }
    REP(i,q)printf("%d\n",an[i]);
    return 0;
}