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
int T;
vector<int>h[N];
int n,m;
int w[N],a[N];

int main(){
	scanf("%d",&T);
	while(T--){
		scanf("%d%d",&n,&m);
		rep(i,n)w[i]=0;
		rep(i,m){
			h[i].clear();
			int k; scanf("%d",&k);
			rep(j,k){
				int x; scanf("%d",&x);
				h[i].push_back(x);
				w[x]++;
			}
		}
		int mx=0,bo=(m+1)/2,id;
		rep(i,n){
			if(w[i]>mx){
				mx=w[i];
				id=i;
			}
		}
		if(mx<=bo){
			puts("YES");
			rep(i,m)printf("%d ",h[i][0]);
			continue;
		}
		int nw=mx;
		rep(i,m){
			if(h[i].size()==1)a[i]=h[i][0];
			else{
				bool fl=0;
				int sd=0;
				rep0(j,h[i].size()){
					if(h[i][j]==id)fl=1;
					else sd=h[i][j];
				}
				if(fl&&nw>bo){
					a[i]=sd;
					nw--;
				}
				else{
					if(fl)a[i]=id;
					else a[i]=h[i][0];
				}
			}
		}
		if(nw>bo)puts("NO");
		else{
			puts("YES");
			rep(i,m)printf("%d ",a[i]);
			puts("");
		}
	}
	return 0;
}