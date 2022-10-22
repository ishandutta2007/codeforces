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
const int N=1007;
const int INF=1e9+7;
int T;
int a[N];
vector<int>w;
int main(){
	scanf("%d",&T);
	while(T--){
		int n; scanf("%d",&n);
		rep(i,n)scanf("%d",&a[i]);
		w.clear(); 
		rep(i,n){
			if(a[i]==1)w.push_back(1);
			else{
				while(w[w.size()-1]!=a[i]-1)w.pop_back();
				w.pop_back();
				w.push_back(a[i]);
			}
			for(int j=0;j<w.size();j++){
				if(j)putchar('.');
				printf("%d",w[j]);
			}
			puts("");
		}
	}
	return 0;
}