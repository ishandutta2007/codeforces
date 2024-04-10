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
const int MAXLEN = (int)4e5 + 5;
int ban[MAXLEN];
char s[MAXLEN],forbidden[MAXLEN];
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
    for(i=0;i<len;i++)ban[i]=forbidden[SA[i]];
}
PII stk[SIZE];
int sn,ll[SIZE],rr[SIZE];
int dp[SIZE];
int main(){
    DRI(N);
    RS(s);
    LL an=0;
    RS(forbidden);
    REP(i,N){
        if(forbidden[i]=='0')an=i+1;
    }
    reverse(s,s+N);
    reverse(forbidden,forbidden+N);
    forbidden[N++]='1';
    REP(i,N)forbidden[i]-='0';
    make_suffix_array(128,N);
    REPP(i,1,N){
        dp[i]=1-ban[i]+dp[i-1];
    }
    stk[sn++]=MP(-1,0);
    REPP(i,2,N){
        while(sn&&Height[i]<=stk[sn-1].F){
            sn--;
        }
        ll[i]=stk[sn-1].S;
        stk[sn++]=MP(Height[i],i-1);
    }
    sn=1;
    stk[0].S=N-1;
    for(int i=N-1;i>1;i--){
        while(sn&&Height[i]<=stk[sn-1].F)sn--;
        rr[i]=stk[sn-1].S;
        stk[sn++]=MP(Height[i],i-1);
    }
    REPP(i,2,N){
        an=max(an,(LL)(dp[rr[i]]-dp[ll[i]])*Height[i]);
    }
    cout<<an<<endl;
    return 0;
}