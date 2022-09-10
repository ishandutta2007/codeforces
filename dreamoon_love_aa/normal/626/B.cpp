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
char s[SIZE];
bool t[222][222][222];
void go(int x,int y,int z){
    if(t[x][y][z])return;
    t[x][y][z]=1;
    if(x+y+z==1)return;
    if(x>1)go(x-1,y,z);
    if(y>1)go(x,y-1,z);
    if(z>1)go(x,y,z-1);
    if(x&&y)go(x-1,y-1,z+1);
    if(x&&z)go(x-1,y+1,z-1);
    if(z&&y)go(x+1,y-1,z-1);
}
int main(){
    DRI(n);
    RS(s);
    int x=0,y=0,z=0;
    REP(i,n){
        if(s[i]=='B')x++;
        else if(s[i]=='G')y++;
        else z++;
    }
    go(x,y,z);
    if(t[1][0][0])printf("B");
    if(t[0][1][0])printf("G");
    if(t[0][0][1])printf("R");
    return 0;
}