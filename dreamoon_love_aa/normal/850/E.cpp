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
const int INV_2 = 5e8 + 4;
const int SIZE = (1<<20)+5;
char s[SIZE];
int a[1<<21],res[1<<21];
inline void FWT(int c[], int N, int tf_utf)    // tf_utf 1:tf; 0:utf
{
    for (int i = 1; i < N; i <<= 1)
    {
        int tmp = i << 1;
        for (int j = 0; j < N; j += tmp)
        {
            for (int k = 0; k < i; k++)
            {
                int x = c[j + k], y = c[j + k + i];
                if (tf_utf)
                {
                    c[j + k] = x + y;
                    if (c[j + k] >= MOD)
                    {
                        c[j + k] -= MOD;
                    }
                    c[j + k + i] = x - y;
                    if (c[j + k + i] < 0)
                    {
                        c[j + k + i] += MOD;
                    }
                }
                else
                {
                    c[j + k] = (LL)(x + y) * INV_2 % MOD;
                    c[j + k + i] = (LL)(x - y + MOD) * INV_2 % MOD;
                }
            }
        }
    }
}
int main(){
    DRI(n);
    RS(s);
    REP(i,1<<n){
        a[(i<<1)+(s[i]-'0')]=1;
    }
    FWT(a,1<<(n+1),1);
    REP(i,1<<(n+1))a[i]=(a[i]*(LL)a[i])%MOD;
    FWT(a,1<<(n+1),0);
    LL sum=0;
    for(int i=0;i<(1<<(n+1));i+=2){
        int now=i>>1;
        LL v=1;
        REP(j,n){
            if(!(now&1))v*=2;
            now>>=1;
        }
        sum=(sum+a[i]*v)%MOD;
    }
    cout<<sum*3%MOD*INV_2%MOD<<endl;
    return 0;
}