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
typedef unsigned long long ULL;
using namespace std;
const int MOD = 1e9+7;
const int SIZE = 2000;
ULL d[SIZE][32],from[SIZE][32];
int id[SIZE];
bool contain[SIZE];
char s[SIZE];
int bit_cnt[1<<16];
inline void myset(ULL a[],int idx){
    a[idx>>6]|=(ULL)1<<(idx&63);
}
inline int myget(ULL a[],int idx){
    return (a[idx>>6]>>(idx&63))&1;
}
inline void mycopy(ULL a[],ULL b[]){
    memcpy(a,b,sizeof(ULL)*32);
}
inline void myxor(ULL a[],ULL b[]){
    REP(i,32)a[i]^=b[i];
}
inline int mycount(ULL a[]){
    int res=0;
    REP(i,32){
        ULL tmp=a[i];
        REP(j,4){
            res+=bit_cnt[tmp&65535];
            tmp>>=16;
        }
    }
    return res;
}
ULL H[64];
LL digit[300];
LL ten[9]={1,10,100,1000,10000,100000,1000000,10000000,100000000};
int main(){
    REPP(i,1,1<<16){
        bit_cnt[i]=bit_cnt[i>>1]+(i&1);
    }
    DRI(n);
    REP(i,n){
        RS(s);
        int len=LEN(s);
        reverse(s,s+len);
        MS0(digit);
        REP(j,len)digit[j>>3]+=(s[j]-'0')*ten[j&7];
        int tail=(len+10)/8;
        while(!digit[tail])tail--;
        ULL me[32]={},me_from[32]={};
        int idx=0;
        while(tail>0||digit[0]){
            REP(j,8)
                if((digit[0]>>j)&1)myset(me,idx+j);
            idx+=8;
            digit[0]^=digit[0]&255;
            for(int j=tail;j>0;j--){
                digit[j-1]+=(digit[j]&255)*ten[8];
                digit[j]>>=8;
            }
            digit[0]>>=8;
            while(tail>0&&!digit[tail])tail--;
        }
        bool suc=1;
            REP(j,SIZE){
                if(myget(me,j)){
                    if(contain[j]){
                        myxor(me,d[j]);
                        myxor(me_from,from[j]);
                    }
                    else{
                        contain[j]=1;
                        mycopy(d[j],me);
                        mycopy(from[j],me_from);
                        id[j]=i;
                        myset(from[j],j);
                        suc=0;
                        break;
                    }
                }
            }
        if(suc){
            printf("%d",mycount(me_from));
            REP(j,SIZE)if(myget(me_from,j))printf(" %d",id[j]);
            puts("");
        }
        else{
            puts("0");
        }
    }
    return 0;
}