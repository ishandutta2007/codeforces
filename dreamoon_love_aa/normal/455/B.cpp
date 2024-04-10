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
const int SIZE = 1e5+5;
int N,K;
string str[SIZE];
bool state;
int dfs(int L,int R,int h){
    while(L<=R&&str[L].size()==h)L++;
    if(L>R){
        if(!state)return -1;
        return 1;
    }
    for(int i=L,j;i<=R;i=j){
        for(j=i+1;j<=R&&str[j][h]==str[i][h];j++){
        }
        if(dfs(i,j-1,h+1)==-1)return 1;
    }
    return -1;
}
int main(){
    RII(N,K);
    REP(i,N){
        cin>>str[i];
    }
    sort(str,str+N);
    int res[2]={};
    state=0;
    res[0]=dfs(0,N-1,0);
    state=1;
    res[1]=dfs(0,N-1,0);
    if(res[0]==1&&res[1]==1)puts("First");
    else if(res[0]==1&&res[1]==-1){
        if(K%2==1)puts("First");
        else puts("Second");
    }
    else if(res[0]==-1&&res[1]==1){
        puts("Second");
    }
    else if(res[0]==-1&&res[1]==-1){
        puts("Second");
    }
    return 0;
}