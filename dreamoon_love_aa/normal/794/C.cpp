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
char s[2][SIZE],an[SIZE];
int c[2][26];
char find_ma(int cc[]){
    for(int i=25;i>=0;i--)
        if(cc[i])return i+'a';
}
char find_mi(int cc[]){
    REP(i,26)
        if(cc[i])return i+'a';
}
int main(){
    RS(s[0]);
    RS(s[1]);
    int n=LEN(s[0]);
    REP(i,2)REP(j,n){
        c[i][s[i][j]-'a']++;
    }
    REP(i,n){
        int r=n-i;
        if(i%2==0){
            char me=find_mi(c[0]);
            char you=find_ma(c[1]);
            if(me<you){
                an[i]=me;
                c[0][me-'a']--;
            }
            else{
                if(r%2==1){
                    while(i<n){
                        if(i%2==0){
                            an[i]=find_mi(c[0]);
                            c[0][an[i]-'a']--;
                        }
                        else{
                            an[i]=find_ma(c[1]);
                            c[1][an[i]-'a']--;
                        }
                        i++;
                    }
                }
                else{
                    while(i<n){
                        if(i%2==1){
                            an[i]=find_mi(c[0]);
                            c[0][an[i]-'a']--;
                        }
                        else{
                            an[i]=find_ma(c[1]);
                            c[1][an[i]-'a']--;
                        }
                        i++;
                    }
                }
            }
        }
        else{
            char me=find_ma(c[1]);
            char you=find_mi(c[0]);
            if(me>you){
                an[i]=me;
                c[1][me-'a']--;
            }
            else{
                if(r%2==1){
                    while(i<n){
                        if(i%2==0){
                            an[i]=find_mi(c[0]);
                            c[0][an[i]-'a']--;
                        }
                        else{
                            an[i]=find_ma(c[1]);
                            c[1][an[i]-'a']--;
                        }
                        i++;
                    }
                }
                else{
                    while(i<n){
                        if(i%2==1){
                            an[i]=find_mi(c[0]);
                            c[0][an[i]-'a']--;
                        }
                        else{
                            an[i]=find_ma(c[1]);
                            c[1][an[i]-'a']--;
                        }
                        i++;
                    }
                }
            }
        }
    }
    puts(an);
    return 0;
}