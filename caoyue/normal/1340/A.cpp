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
const int N=1e5+7;
const int INF=1e9+7;
int T,n;
int p[N];
map<int,int>mp;
void ins(int x){
	if(mp.count(x))mp[x]++;
	else mp[x]=1;
}
void del(int x){
	if(mp[x]==1)mp.erase(x);
	else mp[x]--;
}
set<int>S;

int main(){
	scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
		S.clear();
		mp.clear();
		rep(i,n){
			int x; scanf("%d",&x);
			p[x]=i;
		}
		rep0(i,n+1)S.insert(i);
		mp[1]=n;
		int fl=1;
		rep(i,n){
			set<int>::iterator u=S.lower_bound(p[i]);
			set<int>::iterator v=u;
			v--;
			map<int,int>::iterator gg=mp.upper_bound((*u)-(*v));
			if(gg!=mp.end()){
				puts("No");
				fl=0;
				break;
			}
			u++;
			if(u!=S.end()){
				del((*u)-p[i]);
				ins((*u)-(*v));
			}
			del(p[i]-(*v));
			S.erase(p[i]);
		}
		if(fl)puts("Yes");
	} 
	return 0;
}