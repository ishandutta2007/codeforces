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
const int N=2e5+7;
const int INF=1e9+7;
int T,n,cnt;
set<int>S,G;
int Ans[N],a[N];
int gcd(int x,int y){return y?gcd(y,x%y):x;}
void del(int x){
	set<int>::iterator o=S.lower_bound(x);
	set<int>::iterator o1=o,o2=o;
	o1++;
	int l,r;
	if(o1!=S.end())r=*o1;
	else r=*S.begin();
	if(o2!=S.begin()){
		o2--;
		l=*o2;
	}
	else {
		o2=S.end();
		o2--;
		l=*o2;
	}
	G.erase(l);
	if(G.count(x))G.erase(x);
	S.erase(x);
	if(gcd(a[l],a[r])==1&&S.count(l)&&S.count(r))G.insert(l);
}
int main(){
	scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
		rep(i,n)scanf("%d",&a[i]);
		S.clear();
		G.clear();
		cnt=0;
		rep(i,n)S.insert(i);
		rep(i,n-1)if(gcd(a[i],a[i+1])==1)G.insert(i);
		if(gcd(a[n],a[1])==1)G.insert(n);
		rep(i,n){
			for(int j=0;j<=n;){
				set<int>::iterator w=G.upper_bound(j);
				if(w==G.end())break;
				set<int>::iterator u=S.upper_bound((*w));
				if(u==S.end())Ans[++cnt]=*S.begin();
				else Ans[++cnt]=*u;
				j=Ans[cnt];
				del(j);
			}
		}
		printf("%d ",cnt);
		rep(i,cnt)printf("%d ",Ans[i]);
		puts("");
	}
	return 0;
}