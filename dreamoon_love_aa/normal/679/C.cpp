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
char s[555][555];
struct Union_Find{
    int d[SIZE],num[SIZE];
    void init(int n){
        REP(i,n)d[i]=i,num[i]=1;
    }
    int find(int x){
        return (x!=d[x])?(d[x]=find(d[x])):x;
    }
    bool uu(int x,int y){
        x=find(x);
        y=find(y);
        if(x==y)return 0;
        if(num[x]<=num[y]){
            num[y]+=num[x];
            d[x]=y;
        }
        else{
            num[x]+=num[y];
            d[y]=x;
        }
        return 1;
    }
}U;
int v[555][555];
int used[555555],tt,dp[555][555],from[555][555],base[555][555];
int cnt[555555];
int get(int x1,int y1,int x2,int y2){
    x1--;y1--;
    return dp[x2][y2]+dp[x1][y1]-dp[x1][y2]-dp[x2][y1];
}
int check(int x,int y){
    if(s[x][y]!='.')return 0;
    if(cnt[from[x][y]])return 0;
    if(used[from[x][y]]==tt)return 0;
    used[from[x][y]]=tt;
    return U.num[from[x][y]];
}
int main(){
    DRII(n,k);
    U.init(n*n+1);
    {
        int id=1;
        REPP(i,1,n+1)REPP(j,1,n+1){
            v[i][j]=id++;
        }
    }
    REP(i,n)RS(s[i+1]+1);
    REPP(i,1,n+1)REPP(j,1,n+1){
        if(s[i][j]=='.'){
            if(s[i][j+1]=='.')U.uu(v[i][j],v[i][j+1]);
            if(s[i+1][j]=='.')U.uu(v[i][j],v[i+1][j]);
        }
    }
    REPP(i,1,n+1)REPP(j,1,n+1)dp[i][j]=dp[i][j-1]+(s[i][j]=='.');
    REPP(i,1,n+1)REPP(j,1,n+1)dp[i][j]+=dp[i-1][j];
    REPP(i,1,n+1)REPP(j,1,n+1){
        if(s[i][j]=='.')from[i][j]=U.find(v[i][j]);
    }
    int an=0;
    for(int i=1;i+k-1<=n;i++){
        int rr=1;
        int ll=1;
        int base_v=0;
        MS0(cnt);
        for(int j=1;j+k-1<=n;j++){
            while(rr<=j+k-1){
                REP(it,k){
                    if(from[i+it][rr]>0){
                        cnt[from[i+it][rr]]++;
                        if(cnt[from[i+it][rr]]==1){
                            base_v+=U.num[from[i+it][rr]];
                        }
                    }
                }
                rr++;
            }
            tt++;
            int me=k*k+base_v-get(i,j,i+k-1,j+k-1);
            REP(it,k){
                me+=check(i-1,j+it);
                me+=check(i+k,j+it);
                me+=check(i+it,j-1);
                me+=check(i+it,j+k);
            }
            //printf("(%d,%d):%d %d\n",i,j,me,base_v);
            an=max(an,me);
            while(ll==j||(j+k-1==n&&ll<=n)){
                REP(it,k){
                    if(from[i+it][ll]>0){
                        cnt[from[i+it][ll]]--;
                        if(cnt[from[i+it][ll]]==0){
                            base_v-=U.num[from[i+it][ll]];
                        }
                    }
                }
                ll++;
            }
        }
    }
    cout<<an<<endl;
    return 0;
}