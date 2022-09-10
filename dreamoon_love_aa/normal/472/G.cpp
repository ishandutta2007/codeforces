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
typedef unsigned long long UL;
using namespace std;
char s[200011];
UL d1[64][3150],d2[64][3150];
int bit_cnt[1<<16];
const UL maskk=(1<<16)-1;
int get(UL a[],UL b[],int len){
    //printf("%u %u %d\n",a[0],b[0],len);
    int res=0;
    if(len&63){
        int r=len&63;
        UL mask=0;
        REP(i,r)mask^=(UL)1<<i;
        UL A=(a[len>>6]^b[len>>6])&mask;
        res+=bit_cnt[A&maskk]+bit_cnt[(A>>16)&maskk]+bit_cnt[(A>>32)&maskk]+bit_cnt[(A>>48)&maskk];
    }
    len>>=6;
    REP(i,len){
        UL A=a[i]^b[i];
        res+=bit_cnt[A&maskk]+bit_cnt[(A>>16)&maskk]+bit_cnt[(A>>32)&maskk]+bit_cnt[(A>>48)&maskk];
    }
    return res;
}
int main(){
    REPP(i,1,(1<<16)){
        bit_cnt[i]=bit_cnt[i>>1]+(i&1);
    }
    RS(s);
    for(int i=0;s[i];i++){
        if(s[i]=='1')d1[0][i>>6]|=((UL)1)<<(i&63);
    }
    REPP(i,1,64){
        REP(j,3144){
            d1[i][j]=d1[i-1][j]>>1;
            if(d1[i-1][j+1]&1)d1[i][j]|=(UL)1<<63;
        }
    }
    RS(s);
    for(int i=0;s[i];i++){
        if(s[i]=='1')d2[0][i>>6]|=((UL)1)<<(i&63);
    }
    REPP(i,1,64){
        REP(j,3144){
            d2[i][j]=d2[i-1][j]>>1;
            if(d2[i-1][j+1]&1)d2[i][j]|=(UL)1<<63;
        }
    }
    DRI(Q);
    while(Q--){
        DRIII(p1,p2,len);
        printf("%d\n",get(d1[p1&63]+(p1>>6),d2[p2&63]+(p2>>6),len));
    }
    return 0;
}