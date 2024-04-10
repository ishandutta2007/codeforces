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
char s[SIZE],op[SIZE];
int stk[SIZE],sn,to[SIZE];
int main(){
 DRIII(n,m,p);
 RS(s+1);RS(op);
 set<int>H;
 REPP(i,1,n+1){
  if(s[i]=='('){
   stk[sn++]=i;
  }
  else{
   to[i]=stk[--sn];
   to[stk[sn]]=i;
  }
  H.insert(i);
 }
 REP(i,m){
  if(op[i]=='R'){
   set<int>::iterator it=H.lower_bound(p);
   it++;
   p=*it;
  }
  else if(op[i]=='L'){
   set<int>::iterator it=H.lower_bound(p);
   it--;
   p=*it;
  }
  else{
   int x=p;
   int y=to[p];
   if(x>y)swap(x,y);
   set<int>::iterator it1=H.lower_bound(x);
   set<int>::iterator it2=H.upper_bound(y);
   H.erase(it1,it2);
   it1=H.lower_bound(x);
   if(H.end()==it1)it1--;
   p=*it1;
  }
 }
 for(set<int>::iterator it=H.begin();it!=H.end();it++)printf("%c",s[*it]);
 return 0;
}