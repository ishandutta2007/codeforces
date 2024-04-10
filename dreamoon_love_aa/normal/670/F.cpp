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
int dd(int x){
 int r=0;
 for(;x;x/=10)r++;
 return r;
}
int d[10];
int main(){
 RS(s);
 int n=LEN(s);
 int m=1;
 while(m+dd(m)<n)m++;
 REP(i,n)d[s[i]-'0']++;
 while(m){d[m%10]--;m/=10;}
 RS(s);
 for(int i=0;s[i];i++)d[s[i]-'0']--;
 string an=s;
 REP(i,10)REP(j,d[i])an+=i+'0';
 int st=1;
 while(st<10&&d[st]==0)st++;
 if(st==10)return 0*printf("%s",an.c_str());
 d[st]--;
 REP(i,10){
  string tmp="";
  tmp+='0'+st;
  REP(j,10){
   if(i==j)tmp+=s;
   REP(k,d[j])tmp+='0'+j;
  }
  if(an[0]=='0'||tmp<an)an=tmp;
 }
 cout<<an;
 return 0;
}