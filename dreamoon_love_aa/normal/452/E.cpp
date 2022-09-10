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
const int MOD = 1000000007;
typedef long long LL;
using namespace std;const int MAXLEN = (int)3e5 + 5;

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
int n[3];
LL dp[100010];
int an_sz;
int ty[3][MAXLEN];
int mi[19][300010],id[19][300010];
void build(int N){
    REP(i,N){
        mi[0][i]=Height[i];
        id[0][i]=i;
    }
    for(int i=1;(1<<i)<=N;i++){
        for(int j=0;j+(1<<i)<=N;j++){
            mi[i][j]=mi[i-1][j];
            id[i][j]=id[i-1][j];
            if(mi[i][j]>mi[i-1][j+(1<<(i-1))]){
                mi[i][j]=mi[i-1][j+(1<<(i-1))];
                id[i][j]=id[i-1][j+(1<<(i-1))];
            }
        }
    }
}
int get(int L,int R){
    int len=R-L+1;
    int tp=0;
    while((1<<(tp+1))<=len)tp++;
    if(mi[tp][L]<mi[tp][R-(1<<tp)+1])return id[tp][L];
    return id[tp][R-(1<<tp)+1];
}
void dfs(int L,int R,int lt){
    if(L==R)return;
    int mid=get(L+1,R);
    dp[Height[mid]]+=(LL)(ty[0][R]-ty[0][L-1])*(ty[1][R]-ty[1][L-1])%MOD*(ty[2][R]-ty[2][L-1])%MOD;
    dp[lt]-=(LL)(ty[0][R]-ty[0][L-1])*(ty[1][R]-ty[1][L-1])%MOD*(ty[2][R]-ty[2][L-1])%MOD;
    dfs(L,mid-1,Height[mid]);
    dfs(mid,R,Height[mid]);
}
int main(){
    RS(s);
    n[0]=LEN(s);
    s[n[0]]=1;
    RS(s+n[0]+1);
    n[1]=LEN(s+n[0]+1);
    s[n[0]+n[1]+1]=2;
    RS(s+n[0]+n[1]+2);
    n[2]=LEN(s+n[0]+n[1]+2);
    an_sz=n[0];
    an_sz=min(an_sz,n[1]);
    an_sz=min(an_sz,n[2]);
    make_suffix_array(128,n[0]+n[1]+n[2]+3);
    int N=n[0]+n[1]+n[2]+3;
    REPP(i,1,N){
        REP(j,3)ty[j][i]=ty[j][i-1];
        if(SA[i]<n[0])ty[0][i]++;
        else if(SA[i]>n[0]&SA[i]<=n[0]+n[1])ty[1][i]++;
        else if(SA[i]>n[0]+n[1]+1&&SA[i]<=n[0]+n[1]+n[2]+1)ty[2][i]++;
    }
    build(N);
    dfs(3,N-1,0);
    for(int i=an_sz-1;i>0;i--){
        dp[i]+=dp[i+1];
        dp[i]%=MOD;
        if(dp[i]<0)dp[i]+=MOD;
    }
    REPP(i,1,an_sz+1){
        if(i!=1)putchar(' ');
        printf("%I64d",dp[i]);
    }
    puts("");
    return 0;
}