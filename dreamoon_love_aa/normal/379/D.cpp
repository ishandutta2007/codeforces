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
vector<pair<string,int> >pp[2];
const long long INF = 1e10;
long long dp[111];
long long get(pair<string,int>&p1,pair<string,int>&p2,int k){
    dp[1]=p1.S;
    dp[2]=p2.S;
    string s1=p1.F.substr(0,1)+p1.F.substr(SZ(p1.F)-1);
    string s2=p2.F.substr(0,1)+p2.F.substr(SZ(p2.F)-1);
    for(int i=3;i<=k;i++){
        dp[i]=dp[i-2]+dp[i-1];
        if(s1[1]=='A'&&s2[0]=='C')dp[i]++;
        if(dp[i]>=INF)return INF;
        string tmp=s1.substr(0,1)+s2.substr(1);
        s1=s2;
        s2=tmp;
    }
    return dp[k];
}
void make_string(vector<pair<string,int> >&p,int n){
    string tmp="";
    REP(i,n)tmp+='B';
    p.PB(MP(tmp,0));
    tmp[n-1]='A';
    p.PB(MP(tmp,0));
    tmp[n-1]='B';
    for(int i=0;i+1<n;i+=2){
        tmp[i]='A';
        tmp[i+1]='C';
        p.PB(MP(tmp,i/2+1));
        if(i+2<n){
            tmp[n-1]='A';
            p.PB(MP(tmp,i/2+1));
            tmp[n-1]='B';
        }
    }
    REP(i,n)tmp[i]='B';
    tmp[0]='C';
    p.PB(MP(tmp,0));
    tmp[n-1]='A';
    p.PB(MP(tmp,0));
    tmp[n-1]='B';
    for(int i=1;i+1<n;i+=2){
        tmp[i]='A';
        tmp[i+1]='C';
        p.PB(MP(tmp,i/2+1));
        if(i+2<n){
            tmp[n-1]='A';
            p.PB(MP(tmp,i/2+1));
            tmp[n-1]='B';
        }
    }
}
int main(){
    DRII(k,x);
    DRII(n,m);
    make_string(pp[0],n);
    make_string(pp[1],m);
    REP(i,SZ(pp[0]))REP(j,SZ(pp[1])){
        if(get(pp[0][i],pp[1][j],k)==x){
            cout<<pp[0][i].F<<endl<<pp[1][j].F<<endl;
            return 0;
        }
    }
    puts("Happy new year!");
    return 0;
}