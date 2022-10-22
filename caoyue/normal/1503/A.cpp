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
const int N=2e5+7;
const int INF=1e9+7;
int T,n;
char s[N];
int a[N],b[N];
bool check(int *c){
	int nw=0;
	rep(i,n){
		nw+=c[i];
		if(nw<0)return 0;
	}
	return 1;
}
int main(){
	scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
		scanf("%s",s+1);
		int s0=0,s1=0;
		rep(i,n){
			if(s[i]=='0')s0++;
			else s1++;
		}
		if((s1&1)||(s0&1)){
			puts("NO");
			continue;
		}
		int n1=0,n0=0;
		rep(i,n){
			if(s[i]=='1'){
				n1++;
				if(n1*2<=s1)a[i]=b[i]=1;
				else a[i]=b[i]=-1;
			}
			else{
				n0++;
				if(n0&1){
					a[i]=1;
					b[i]=-1;
				}
				else{
					a[i]=-1;
					b[i]=1;
				}
			}
		}
		bool fl=check(a)&check(b);
		if(!fl)puts("NO");
		else{
			puts("YES");
			rep(i,n)if(a[i]>0)putchar('(');else putchar(')');
			puts("");
			rep(i,n)if(b[i]>0)putchar('(');else putchar(')');
			puts("");
		}
	}
	return 0;
}