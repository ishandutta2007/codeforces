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
int w[N];
int main(){
	scanf("%d",&T);
	while(T--){
		scanf("%s",s+1);
		n=strlen(s+1);
		int cnt=0;
		rep(i,n){
			if(!cnt)w[++cnt]=s[i]-'A';
			else{
				if(s[i]=='B'&&!w[cnt])cnt--;
				else w[++cnt]=s[i]-'A';
			}
		}
		int ans=cnt;
		rep(i,cnt){
			if(i<cnt&&w[i]&&w[i+1]){
				ans-=2;
				i++;
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}