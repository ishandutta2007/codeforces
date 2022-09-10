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
using namespace std;
const int MOD = 1e9+7;
const int SIZE = 1e6+10;
const LL MAX = 1e18;
LL t,a,b;
LL mul(LL x,LL y){
    if(x<0||y<0)return -1;
    if(!x||!y)return 0;
    if(x>MAX/y)return -1;
    return x*y;
}
bool check(vector<LL>&ha){
    LL now=0;
    for(int i=SZ(ha)-1;i>=0;i--){
        now=mul(t,now);
        if(now<0)return 0;
        now+=ha[i];
        if(now>a)return 0;
    }
    return now==a;
}
int main(){
    LL an=0;
    cin>>t>>a>>b;
    if(a==1&&b==1&&t==1)puts("inf");
    else if(a==t&&t!=b)puts("0");
    else if(a<t)printf("%d\n",a==b?1:0);
    else{
        vector<LL>d;
        LL now=b;
        int an=0;
        while(now){
            d.PB(now%a);
            now/=a;
        }
        if(check(d))an++;
        for(int i=SZ(d)-1;i>0;i--){
            if(d[i]>0){
                d[i]--;
                d[i-1]+=a;
                if(check(d))an++;
                d[i]++;
                d[i-1]-=a;
            }
        }
        cout<<an<<endl;
    }
    return 0;
}