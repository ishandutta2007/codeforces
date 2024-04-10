#include<stdio.h>
#include<string>
#include<math.h>
#include<stdlib.h>
#include<set>
#include<bitset>
#include<map>
#include<vector>
#include<string.h>
#include<algorithm>
#include<iostream>
#include<queue>
#define SZ(X) ((int)(X).size())
#define ALL(X) (X).begin(), (X).end()
#define REP(I, N) for (int I = 0; I < (N); ++I)
#define REPP(I, A, B) for (int I = (A); I < (B); ++I)
#define REPC(I, C) for (int I = 0; !(C); ++I)
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
using namespace std;
const int MAX=1<<24;
int n;
int have[MAX];
inline int get(int x){return 1<<x;}
int a[24],an;
void dfs(int x,int y,int z){
    if(x==24){
        an^=(n-z)*(n-z);
        return;
    }
    dfs(x+1,y,z);
    z+=have[1<<x];
    for(int i=0;i<y;i++)z+=have[a[i]|(1<<x)];
    for(int i=0;i<y;i++){
        int now=a[i]|(1<<x);
        for(int j=i+1;j<y;j++)z+=have[now|a[j]];
    }
    a[y++]=1<<x;
    dfs(x+1,y,z);
}
int main(){
    RI(n);
    REP(i,n){
        char s[8];
        RS(s);
        have[get(s[0]-'a')|get(s[1]-'a')|get(s[2]-'a')]++;
    }
    dfs(0,0,0);
    printf("%d\n",an);
    return 0;
}