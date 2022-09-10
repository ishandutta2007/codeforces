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
const int MOD = 1<<12;
const int SIZE = 1e6+10;
int row[10],col[40];
map<int,PII>dp[22][1<<12];
int seg_n[32];
void pre(){
    int d[5];
    REP(i,32){
        MS0(d);
        REP(j,5)d[j]=(i>>j)&1;
        REP(j,5){
            if(d[j]){
                if(j==0||d[j-1]==0)seg_n[i]++;
            }
        }
    }
}
char res[5][40];
char ch(int x){
    if(x)return '*';
    return '.';
}
void print(int m,int v){
    map<int,PII>::iterator it=dp[m][v&(MOD-1)].find(v);
    REP(k,5)res[k][m-1]=ch((((it->S).S)>>k)&1);
    if(m>1)print(m-1,(it->S).F);
}
bool get_answer(int x,int v,int n,int m){
    if(x==n){
        if(dp[m][v&(MOD-1)].count(v)){
            //printf("%d,%d\n",m,v);
            print(m,v);
            return 1;
        }
        return 0;
    }
    if( get_answer(x+1,v|((row[x]*2)<<(5*x)),n,m) )return 1;
    if( row[x] && get_answer(x+1,v|((row[x]*2-1)<<(5*x)),n,m) )return 1;
    return 0;
}
int main(){
    pre();
    DRII(n,m);
    REP(i,n)RI(row[i]);
    REP(i,m)RI(col[i]);
    dp[0][0][0]=MP(-1,-1);
    int nn=1<<n;
    REP(i,m){
        REP(mod,MOD){
        for(map<int,PII>::iterator it=dp[i][mod].begin();it!=dp[i][mod].end();it++){
            int me[5];
            int now=it->F;
            REP(j,n){
                me[j]=now&31;
                now>>=5;
            }
            REP(j,nn){
                if(seg_n[j]!=col[i])continue;
                int you[5];
                memcpy(you,me,sizeof(int)*n);
                REP(k,n){
                    if((you[k]&1)!=((j>>k)&1))you[k]++;
                }
                int nxt=0;
                bool err=0;
                REP(k,n){
                    if(you[k]>row[k]*2||you[k]+(m-i)<row[k]*2)err=1;
                    nxt|=you[k]<<(5*k);
                }
                if(err)continue;
                dp[i+1][nxt&(MOD-1)][nxt]=MP(it->F,j);
            }
        }
        }
    }
    if(!get_answer(0,0,n,m))puts("err!!!");
    REP(i,n)puts(res[i]);
    return 0;
}