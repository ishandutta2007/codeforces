#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/priority_queue.hpp>
using namespace std;
using namespace __gnu_pbds;
typedef long long int LL;
typedef pair<int,int> PII;
typedef pair<LL , LL> PLL;
#define REP(i,j)      for(int i = 0 ; i < j ; i++)
#define REPNM(i,j,k)  for(int i = j ; i < k ; i++)
#define RREP(i,j,k)   for(int i = j ; i >=k ; i--)
#define pb   push_back
#define mp   make_pair
#define A    first
#define B    second
#define MEM(i,j)   memset(i,j,sizeof i)
#define ALL(i)     i.begin(),i.end()
#define DB()          if(debug)
#define DBGG(i,j)     if(debug) cout << i << " " << j << endl;
#define DB4(i,j,k,l)  if(debug) cout << i << " " << j << " " << k << " " << l <<endl;
#define RI(i)       scanf("%d" , &i)
#define RII(i,j)    scanf("%d%d" , &i , &j)
#define RIII(i,j,k) scanf("%d%d%d" , &i , &j , &k)
#define RL(i)       scanf("%lld" , &i)
#define RLL(i,j)    scanf("%lld%lld" , &i , &j)
#define RLLL(i,j,k) scanf("%lld%lld%lld" , &i , &j , &k)
#define AS assert
#define IOS cin.tie() , cout.sync_with_stdio(0);
///------------------------------------------------------------
#define MAX 2000
#define INF 0x3f3f3f3f
#define debug 1

int n , po;

int p[MAX][MAX];

void ADDE(int q , int w){
	// DBGG(q , w);
	p[q][w] = 1 , p[w][q] = 1;
}

int main(){
	int n;
	while(~RI(n)){
		po = 3;
		int lel = -1;
		while(n){
			int now = n % 10; n = n / 10; lel ++;

			if(now == 0) continue;
			int las = 1 , nxt = po;  po++;
			int sum = 2;
			
			REP(i , now){
				ADDE(las , po);
				ADDE(po , nxt);
				po ++;
			}
			las = nxt;
			REP(i , lel){
				nxt = po++;
				REP(i , 10){
					ADDE(po , las);
					ADDE(po , nxt);
					po ++;
				}
				las = nxt;
				sum += 2;
			}
			REPNM(i , sum , 35){
				ADDE(las , po) , las = po , po ++;
			}
			ADDE(las , 2);
		}


		printf("%d\n" , po - 1);
		REPNM(i , 1 , po){
			REPNM(j , 1 , po){
				if(p[i][j]) printf("Y");
				else printf("N");
			}
			puts("");
		}
	}
    return 0;
}