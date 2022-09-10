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
const int MAX = 1e9+7;
const int SIZE = 24;
#include<time.h>
const double TIME_LIMIT = 1.9;
clock_t time_start;
void time_cut_start(){time_start = clock();}
bool check_time_cut(){return (clock()-time_start) / CLOCKS_PER_SEC < TIME_LIMIT;}
struct Hugarian{
    int A[SIZE][SIZE],lx[SIZE],ly[SIZE],px[SIZE],py[SIZE],n,bfs[SIZE],my[SIZE],pmy[SIZE],p[SIZE];
    bool tr_x[SIZE],tr_y[SIZE];
    void fresh(int x){
        REPP(i,1,n+1)
            if(lx[x]+ly[i]-A[x][i]<my[i]){
                my[i]=lx[x]+ly[i]-A[x][i];
                pmy[i]=x;
            }
    }
    void back(int x,int y){
        int tmp;
        while(x!=-1){
            tmp=px[x];
            px[x]=y;
            py[y]=x;
            y=tmp;
            x=p[x];
        }
    }
    void match(int x){
        int i,j,k;
        for(i=1;i<=n;i++){
            my[i]=MAX;
            tr_x[i]=tr_y[i]=0;
            p[i]=-1;
        }
        fresh(x);
        tr_x[x]=1;
        bfs[0]=x;
        j=1;
        while(1){
            for(i=0;i<j;i++){
                for(k=1;k<=n;k++){
                    if(!tr_y[k]&&lx[bfs[i]]+ly[k]==A[bfs[i]][k]){
                        if(py[k]==-1){
                            back(bfs[i],k);
                            return;
                        }
                        else{
                            p[py[k]]=bfs[i];
                            tr_x[py[k]]=tr_y[k]=1;
                            bfs[j++]=py[k];
                            fresh(py[k]);
                        }
                    }
                }
            }
            for(i=1,k=MAX;i<=n;i++)
                if(!tr_y[i])k=min(k,my[i]);
            for(i=1;i<=n;i++){
                if(tr_x[i])lx[i]-=k;
                if(tr_y[i])ly[i]+=k;
                if(!tr_y[i])my[i]-=k;
            }
            j=0;
            for(i=1;i<=n;i++){
                if(!tr_y[i]&&!my[i]){
                    if(py[i]==-1){
                        back(pmy[i],i);
                        return;
                    }
                    tr_x[py[i]]=tr_y[i]=1;
                    p[py[i]]=pmy[i];
                    bfs[j++]=py[i];
                    fresh(py[i]);
                }
            }
        }
    }
    int solve(int _n,int a[][SIZE]){
        n=_n;
        REP(i,n)REP(j,n)A[i+1][j+1]=a[i][j];
        REPP(j,1,n+1){
            px[j]=py[j]=-1;
            lx[j]=ly[j]=0;
            for(int k=1;k<=n;k++)lx[j]=max(lx[j],A[j][k]);
        }
        REPP(i,1,n+1)match(i);
        int res=0;
        REPP(i,1,n+1)
            res+=lx[i]+ly[i];
        return res;
     }
}Hug;
int A[21][21],B[21][21];
int main(){
    int N;
    int tmp[SIZE][SIZE];
    scanf("%d",&N);
    REP(i,N)REP(j,N)RI(A[i][j]);
    REP(i,N)REP(j,N)RI(B[i][j]);
    int res=0;
    time_cut_start();
    for(int i=(1<<N)-1;i>=0&&check_time_cut();i--){
        int bn=0;
        REP(j,N)
            bn+=(i>>j)&1;
        if(bn*2!=N)continue;
        int sum=0;
        REP(j,N){
            int ma=0;
            if((i>>j)&1){
                REP(k,N){
                    ma=max(A[j][k],ma);
                    tmp[j][k]=A[j][k];
                }
            }
            else{
                REP(k,N){
                    ma=max(B[j][k],ma);
                    tmp[j][k]=B[j][k];
                }
            }
            sum+=ma;
        }
        if(sum<=res)continue;
        res=max(res,Hug.solve(N,tmp));
    }
    printf("%d\n",res);
}