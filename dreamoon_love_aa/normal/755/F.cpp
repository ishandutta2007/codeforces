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
#define VPII vector<pair<int,int> >
#define PLL pair<long long,long long>
#define VPLL vector<pair<long long,long long> >
#define F first
#define S second
typedef long long LL;
using namespace std;
const int MOD = 1e9+7;
const int SIZE = 1e6+10;
int a[SIZE];
bool used[SIZE];
bitset<1000001>dp;
inline void rit(int& f){
    f=0;
    char ch=getchar();
    do{
        f = f*10+ch-'0';
        ch = getchar();
    }while(ch>='0'&&ch<='9');
}
int main(){
    int n,k,an1=0,an2=0;
    RI(n);RI(k);
    REP(i,n){
        RI(a[i]);a[i]--;
    }
    map<int,int>H;
    int odd=0;
    REP(i,n){
        if(!used[i]){
            int now=i,v=1;
            used[now]=1;
            while(!used[a[now]]){
                now=a[now];
                used[now]=1;
                v++;
            }
            if(v&1)odd++;
            H[v]++;
        }
    }
    int two=(n-odd)/2;
    an2=min(two,k)*2+max(0,k-two);
    an2=min(an2,n);
    dp[0]=1;
    for(map<int,int>::iterator it=H.begin();it!=H.end();it++){
        int cc=it->F;
        int all=it->F*it->S;
        while(all>0){
            dp|=dp<<min(all,cc);
            all-=cc;
            cc*=2;
        }
    }
    if(dp[k])an1=k;
    else an1=k+1;
    printf("%d %d\n",an1,an2);
    return 0;
}