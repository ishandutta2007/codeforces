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
int a[N],s[N],b[N];
vector<int>v[N];
bool cmp(int x,int y){return a[x]<a[y];}
int main(){
	scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
		rep(i,n){
			v[i].clear();
			s[i]=0;
		}
		rep(i,n)scanf("%d",&a[i]);
		rep(i,n){
			s[a[i]]++;
			v[s[a[i]]].push_back(i);
		}
		rep(i,n){
			if(!v[i].size())continue; 
			sort(v[i].begin(),v[i].end(),cmp);
			for(int j=0;j+1<v[i].size();j++)b[v[i][j]]=a[v[i][j+1]];
			b[v[i][v[i].size()-1]]=a[v[i][0]];
		}
		rep(i,n)printf("%d ",b[i]);
		puts("");
	}
	return 0;
}