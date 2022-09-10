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
#define VPII vector<pair<int,int> >
#define PLL pair<long long,long long>
#define F first
#define S second
typedef long long LL;
using namespace std;
const int MOD = 1e9+7;
const int SIZE = 2e5+10;
// template end here
string str[SIZE];
int n;
int d[SIZE];
set<int>H1,H2;
int to[SIZE];
int an;
bool compare(int x,int y){
    return str[x]<str[y]||(str[x]==str[y]&&x<y);
}
char get(int id,int pos){
    if(SZ(str[id])<=pos)return 0;
    return str[id][pos];
}
void f(int L,int R,int lv){
    int st=L;
    for(;st<=R&&!get(d[st],lv);st++);
    for(int i=st,j;i<=R;i=j){
        for(j=i+1;j<=R&&get(d[i],lv)==get(d[j],lv);j++);
        if(i+1<j)f(i,j-1,lv+1);
    }
    set<int>::iterator st1=H1.lower_bound(L);
    set<int>::iterator st2=H2.lower_bound(L);
    set<int>::iterator it1=st1;
    set<int>::iterator it2=st2;
    while(it1!=H1.end()&&*it1<=R&&it2!=H2.end()&&*it2<=R){
        an+=lv;
        to[d[*it1]]=d[*it2]-n;
        it1++;
        it2++;
    }
    if(st1!=it1)H1.erase(st1,it1);
    if(st2!=it2)H2.erase(st2,it2);
}
int main(){
    RI(n);
    REP(i,2*n)d[i]=i;
    REP(i,2*n){
        cin>>str[i];
    }
    sort(d,d+2*n,compare);
    REP(i,2*n){
        if(d[i]<n)H1.insert(i);
        else H2.insert(i);
    }
    f(0,2*n-1,0);
    printf("%d\n",an);
    REP(i,n){
        printf("%d %d\n",i+1,to[i]+1);
    }
    return 0;
}