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
const int SIZE = 1e5+10;
int d[21][SIZE],num[21][SIZE],one[21][SIZE],v[21];
char s[20][SIZE];
int n,an;
void dfs(int lv,int m){
    if(lv==n){
        int me=0;
        REP(i,m)
            me+=v[one[lv][i]]*num[lv][i];
        an=min(an,me);
        //REP(i,m)printf("%d-%d\n",one[lv][i],num[lv][i]);
        //puts("--------------");
        return;
    }
    int mid=0;
    int mask=(1<<(n-lv-1))-1;
    while(mid<m&&d[lv][mid]<=mask)mid++;
    int it1=0,it2=mid;
    int nxt=0;
    while(it1<mid&&it2<m){
        PII pp1=MP(d[lv][it1]&mask,one[lv][it1]),pp2=MP(d[lv][it2]&mask,one[lv][it2]+1);
        if( pp1<pp2 ){
            d[lv+1][nxt]=pp1.F;
            num[lv+1][nxt]=num[lv][it1];
            one[lv+1][nxt++]=pp1.S;
            it1++;
        }
        else if(pp1>pp2){
            d[lv+1][nxt]=pp2.F;
            num[lv+1][nxt]=num[lv][it2];
            one[lv+1][nxt++]=pp2.S;
            it2++;
        }
        else{
            d[lv+1][nxt]=pp1.F;
            num[lv+1][nxt]=num[lv][it1]+num[lv][it2];
            one[lv+1][nxt++]=pp1.S;
            it1++;it2++;
        }
    }
    while(it1<mid){
        d[lv+1][nxt]=d[lv][it1]&mask;
        num[lv+1][nxt]=num[lv][it1];
        one[lv+1][nxt++]=one[lv][it1];
        it1++;
    }
    while(it2<m){
        d[lv+1][nxt]=d[lv][it2]&mask;
        num[lv+1][nxt]=num[lv][it2];
        one[lv+1][nxt++]=one[lv][it2]+1;
        it2++;
    }
    dfs(lv+1,nxt);

    nxt=0;
    it1=0,it2=mid;
    while(it1<mid&&it2<m){
        PII pp1=MP(d[lv][it1]&mask,one[lv][it1]+1),pp2=MP(d[lv][it2]&mask,one[lv][it2]);
        if( pp1<pp2 ){
            d[lv+1][nxt]=pp1.F;
            num[lv+1][nxt]=num[lv][it1];
            one[lv+1][nxt++]=pp1.S;
            it1++;
        }
        else if(pp1>pp2){
            d[lv+1][nxt]=pp2.F;
            num[lv+1][nxt]=num[lv][it2];
            one[lv+1][nxt++]=pp2.S;
            it2++;
        }
        else{
            d[lv+1][nxt]=pp1.F;
            num[lv+1][nxt]=num[lv][it1]+num[lv][it2];
            one[lv+1][nxt++]=pp1.S;
            it1++;it2++;
        }
    }
    while(it1<mid){
        d[lv+1][nxt]=d[lv][it1]&mask;
        num[lv+1][nxt]=num[lv][it1];
        one[lv+1][nxt++]=one[lv][it1]+1;
        it1++;
    }
    while(it2<m){
        d[lv+1][nxt]=d[lv][it2]&mask;
        num[lv+1][nxt]=num[lv][it2];
        one[lv+1][nxt++]=one[lv][it2];
        it2++;
    }
    dfs(lv+1,nxt);
}
int main(){
    an=1e9;
    int m;
    RII(n,m);
    REP(i,n+1)v[i]=min(i,n-i);
    REP(i,n)RS(s[i]);
    REP(i,m){
        int me=0;
        REP(j,n)
            if(s[j][i]=='1')me|=1<<j;
        d[0][i]=me;
    }
    sort(d[0],d[0]+m);
    {
        int it=0;
        for(int i=0,j;i<m;i=j){
            for(j=i+1;j<m&&d[0][i]==d[0][j];j++);
            num[0][it]=j-i;
            d[0][it++]=d[0][i];
        }
        m=it;
        //REP(i,m)printf("[%d,%d]\n",num[0][i],d[0][i]);
    }
    dfs(0,m);
    printf("%d\n",an);
    return 0;
}