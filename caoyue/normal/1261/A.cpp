#include<iostream>
#include<cstring>
#include<cassert>
#include<cmath>
#include<map>
#include<set>
#include<queue>
#include<stack>
#include<cstdio>
#include<vector>
#include<time.h>
#include<algorithm>
using namespace std;
#define REP(i,x,y) for(int i=x;i<=y;i++)
#define rep(i,n) REP(i,1,n)
#define rep0(i,n) REP(i,0,n-1)
#define repG(i,x) for(int i=pos[x];~i;i=e[i].next)
#define ll long long
#define db double
const int N=2007;
const int INF=1e9+7;
int T,n,k;
char s[N];
int a[N],b[N],l[N],r[N];
set<int>S1,S2;

int main(){
	scanf("%d",&T);
	while(T--){
		int cnt=0;
		scanf("%d%d",&n,&k);
		scanf("%s",s+1);
		rep(i,n)a[i]=(s[i]=='(');
		rep(i,k-1){
			b[i*2-1]=1;
			b[i*2]=0;
		}
		REP(i,(k-1)*2+1,n){
			if(i<=(k-1)*2+(n-2*(k-1))/2)b[i]=1;
			else b[i]=0;
		}
		S1.clear();
		S2.clear();
		rep(i,n){
			if(a[i])S1.insert(i);
			else S2.insert(i);
		}
		rep(i,n){
			if(a[i]==b[i]){
				if(a[i])S1.erase(i);
				else S2.erase(i);
				continue;
			}
			if(a[i]){
				set<int>::iterator gg=S2.upper_bound(i);
				int d=*gg;
				swap(a[i],a[d]);
				S2.erase(d);
				S1.erase(i);
				S1.insert(d);
				l[++cnt]=i;
				r[cnt]=d;
			}
			else{
				set<int>::iterator gg=S1.upper_bound(i);
				int d=*gg;
				swap(a[i],a[d]);
				S1.erase(d);
				S2.erase(i);
				S2.insert(d);
				l[++cnt]=i;
				r[cnt]=d;
			}
		}
		printf("%d\n",cnt);
		rep(i,cnt)printf("%d %d\n",l[i],r[i]);
	}
	return 0;
}