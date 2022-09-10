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
int p[SIZE];
bool used[SIZE];
int now;
VI cnt[SIZE];
int an[SIZE],a[SIZE];
int main(){
	DRI(n);
	REP(i,n){
		RI(p[i]);
		p[i]--;
	}
	REP(i,n){
		if(!used[i]){
			int v=1;
			int me=i;
			while(p[me]!=i){me=p[me];v++;used[me]=1;}
			cnt[v].PB(i);
			if(v&1)continue;
			if(SZ(cnt[v])&1)now++;
			else now--;
		}
	}
	if(now)puts("-1");
	else{
		REPP(i,1,n+1){
			if(i&1){
				REP(j,SZ(cnt[i])){
					int me=cnt[i][j];
					int it=0;
					REP(k,i){
						a[it]=me;
						me=p[me];
						it=(it+2)%i;
					}
					REP(k,i)an[a[k]]=a[(k+1)%i];
				}
				continue;
			}
			REP(j,SZ(cnt[i])){
				int me=cnt[i][j++];
				int you=cnt[i][j];
				REP(k,i){
					an[me]=you;
					me=p[me];
					an[you]=me;
					you=p[you];
				}
			}
		}
		REP(i,n)printf("%d ",an[i]+1);
	}
    return 0;
}