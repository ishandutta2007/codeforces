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
long long need[18][10][10];
int next[18][10][10];
void init(){
    REP(i,10)
        REP(j,10)next[0][i][j]=i;
    REPP(i,1,18)
        REP(j,10){
            REP(k,10){
                int now=j;
                for(int k2=9;k2>=0;k2--){
                    need[i][j][k]+=need[i-1][now][max(k,k2)];
                    now=next[i-1][now][max(k,k2)];
                    if(k2){
                        while(now>=0){
                            now-=max(k,max(k2,now));
                            need[i][j][k]++;
                        }
                        now+=10;
                    }
                }
                next[i][j][k]=now;
            }
        }
}
int main(){
    init();
    long long res=0,n;
    cin>>n;
    if(n==1000000000000000000ll){
        n--;
        res++;
    }
    char s[24];
    sprintf(s+1,"%I64d",n);
    int len=strlen(s+1);
    if(len==1)res+=(s[1]!='0');
    else{
        bool end=0;
        s[0]='0';
        int i,j,k;
        for(i=len-1;i>=0&&!end;i--){
            while(s[i]!='9'){
                int ma=0;
                for(j=0;j<=i;j++)ma=max(ma,s[j]-'0');
                res+=need[len-i-1][s[len]-'0'][ma];
                s[len]='0'+next[len-i-1][s[len]-'0'][ma];
                if(ma==0){
                    end=1;
                    res+=s[len]!='0';
                    break;
                }
                while(s[len]>='0'){
                    res++;
                    s[len]-=max(ma,s[len]-'0');
                }
                s[len]+=10;
                s[i]--;
                k=i;
                while(s[k]<'0'){
                    s[k]+=10;
                    s[k-1]--;
                    k--;
                }
            }
        }
    }
    cout<<res<<endl;
    return 0;
}