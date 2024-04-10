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
const int INF = 2e9+7;
const int SIZE = 1e6+10;
map<int,int>H;
int main(){
	DRII(n,k);
	REP(i,n){
		DRII(x,y);
		H[x*2]++;
		H[y*2+1]--;
	}
	int now=0;
	int ll=INF;
	VPII an;
	for(map<int,int>::iterator it=H.begin();it!=H.end();it++){
		now+=it->S;
		if(now>=k){
			if(ll==INF)ll=it->F;
		}
		else{
			if(ll!=INF){
				an.PB(MP(ll/2,(it->F-1)/2));
				ll=INF;
			}
		}
	}
	printf("%d\n",SZ(an));
	REP(i,SZ(an))printf("%d %d\n",an[i].F,an[i].S);
    return 0;
}