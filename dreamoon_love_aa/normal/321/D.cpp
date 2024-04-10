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
const int INF = 1e9+7;
const int SIZE = 33;
// template end here
int a[SIZE][SIZE];
int f(int x){
    assert(x==0||x==1);
    return 1-x*2;
}
int main(){
    DRI(n);
    REP(i,n)REP(j,n)RI(a[i][j]);
    int N=(n+1)/2;
    int an=-INF;
    REP(i,1<<N){
        int mid=i>>(N-1);
        int now=0;
        REP(j,N)now+=f((i>>j)&1)*a[j][N-1];
        REP(j,N-1)now+=f(mid^((i>>j)&1))*a[j+N][N-1];
        //printf("%d:%d\n",i,now);
        REP(j,N-1){
            int ma=-INF;
            REP(k,2){
                int x=k;
                int y=k^mid;
                int v=f(x)*a[N-1][j]+f(y)*a[N-1][j+N];
                REP(j2,N-1){
                    int v2=-INF;
                    REP(k2,2){
                        int s=k2;
                        int t=((i>>j2)&1)^s;
                        int m=s^x;
                        int l=t^y;
                        v2=max(v2,f(s)*a[j2][j]+f(t)*a[j2][j+N]
                                 +f(m)*a[j2+N][j]+f(l)*a[j2+N][j+N]);
                    }
                    v+=v2;
                }
                //printf("[%d]\n",v);
                ma=max(ma,v);
            }
            now+=ma;
        }
        //printf("%d:%d\n",i,now);
        an=max(an,now);
    }
    cout<<an<<endl;
    return 0;
}