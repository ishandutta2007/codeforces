#include<iostream>
#include<cstring>
#include<cassert>
#include<cmath>
#include<map>
#include<set>
#include<queue>
#include<stack>
#include<vector>
#include<time.h>
#include<bitset>
#include<cstdio>
#include<algorithm>
using namespace std;
#define REP(i,x,y) for(int i=x;i<=y;i++)
#define rep(i,n) REP(i,1,n)
#define rep0(i,n) REP(i,0,n-1)
#define repG(i,x) for(int i=pos[x];~i;i=e[i].next)
#define ll long long
#define db double
const int N=57;
const int INF=1e9+7;
int n,K;
int w[N];
char s[N];
void RD(){
	scanf("%d",&K);
	rep(i,K)scanf("%d",&w[i]);
}
void solve(int l,int r,int L,int R,int c){
	if(l==L&&r==R)return;
	if(l!=L){
		printf("? O");
		REP(i,l,r)putchar(s[i]);
		puts("");
		fflush(stdout);
		RD();
		bool fl=0;
		rep(i,K)if(w[i]==l-1)fl=1;
		if(fl)s[l-1]='O';
		else{
			if(c==2)s[l-1]='H';
			else{
				printf("? H");
				REP(i,l,r)putchar(s[i]);
				puts("");
				fflush(stdout);
				RD();
				rep(i,K)if(w[i]==l-1)fl=1;
				if(fl)s[l-1]='H';
				else s[l-1]='C';
			}
		}
		solve(l-1,r,L,R,c);
		return;
	}
	printf("? ");
	REP(i,l,r)putchar(s[i]);
	puts("O");
	fflush(stdout);
	RD();
	bool fl=0;
	rep(i,K)if(w[i]==l)fl=1;
	if(fl)s[r+1]='O';
	else{
		if(c==2)s[r+1]='H';
		else{
			printf("? ");
			REP(i,l,r)putchar(s[i]);
			puts("H");
			fflush(stdout);
			RD();
			rep(i,K)if(w[i]==l)fl=1;
			if(fl)s[r+1]='H';
			else s[r+1]='C';
		}
	}
	solve(l,r+1,L,R,c);
}
int main(){
	int T; scanf("%d",&T);
	int rt=T;
	while(T--){
		scanf("%d",&n);
		puts("? CH");
		fflush(stdout);
		RD();
		if(K){
			s[w[1]]='C';
			s[w[1]+1]='H';
			solve(w[1],w[1]+1,1,n,3);
		}
		else{
			puts("? CO");
			fflush(stdout);
			RD();
			if(K){
				s[w[1]]='C';
				s[w[1]+1]='O';
				solve(w[1],w[1]+1,1,n,3);
			}
			else{
				puts("? CC");
				fflush(stdout);
				RD();
				if(K){
					REP(i,w[1],n)s[i]='C';
					solve(w[1],n,1,n,2);
				}
				else{
					puts("? OH");
					fflush(stdout);
					RD();
					if(K){
						s[w[1]]='O';
						s[w[1]+1]='H';
						if(w[1]==n-1)solve(w[1],w[1]+1,1,n,2);
						else{
							solve(w[1],w[1]+1,1,n-1,2);
							solve(1,n-1,1,n,3);
						}
					}
					else{
						if(n>4){
							puts("? HO");
							fflush(stdout);
							RD();
							if(K){
								rep(i,w[1])s[i]='H';
								REP(i,w[1]+1,n-1)s[i]='O';
								solve(1,n-1,1,n,3);
							}
							else{
								printf("? ");
								rep(i,n-1)putchar('H');
								puts("");
								fflush(stdout);
								RD();
								if(!K){
									printf("? ");
									rep(i,n)putchar('O');
									puts("");
									fflush(stdout);
									RD();
									rep(i,n)s[i]='O';
									if(!K)s[n]='C';
								}
								else{
									rep(i,n)s[i]='H';
									if(K==1)s[n]='C';
								}
							}
						}
						else{
							puts("? HHO");
							fflush(stdout);
							RD();
							if(K){
								if(w[1]==1){
									s[1]=s[2]='H';
									s[3]='O';
									solve(1,3,1,4,3);
								}
								else{
									s[1]=s[2]=s[3]='H';
									s[4]='O';
								}
							}
							else{
								puts("? OOO");
								fflush(stdout);
								RD();
								if(K){
									if(w[1]==1){
										s[1]=s[2]=s[3]='O';
										solve(1,3,1,4,3);
									}
									else{
										s[2]=s[3]=s[4]='O';
										s[1]='H';
									}
								}
								else{
									puts("? HHH");
									fflush(stdout);
									RD();
									if(K)s[1]=s[2]=s[3]='H';
									else{
										s[1]='H';
										s[2]=s[3]='O';
									}
									s[4]='C';
									printf("? ");
									rep(i,4)putchar(s[i]);
									puts("");
									fflush(stdout);
									RD();
									if(!K)s[4]='H';
								}
							}
						}
					}
				}
			}
		}
		printf("! ");
		rep(i,n)putchar(s[i]);
		puts("");
		fflush(stdout);
		int x; scanf("%d",&x);
	}
	return 0;
}