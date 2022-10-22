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
const int N=1e6+7;
const int INF=1e9+7;
int T,n;
int a[N],b[N];
vector<int>V[N];
set<int>S[N];

int main(){
	scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
		rep(i,n){
			S[i].clear();
			V[i].clear();
		}
		rep(i,n){
			scanf("%d",&a[i]);
			S[a[i]].insert(i);
			V[a[i]].push_back(i);
		}
		rep(i,n)scanf("%d",&b[i]);
		int mn=n,fl=0;
		for(int i=n;i;i--){
			set<int>::iterator o=S[b[i]].upper_bound(mn);
			if(o==S[b[i]].begin()){
				fl=1;
				break;
			}
			o--;
			mn=*o;
			int t=V[b[i]][V[b[i]].size()-1];
			if(t>mn){
				fl=1;
				break;
			}
			V[b[i]].pop_back();
		}
		if(fl)puts("NO");
		else puts("YES");
	}
	return 0;
}