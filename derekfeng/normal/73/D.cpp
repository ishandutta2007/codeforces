#include <algorithm>
#include <cstdio>
#include <iostream>
#include <cfloat>
#include <climits>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <queue>
#include <sstream>
#include <stack>
#include <time.h>
#include <vector>
#include <complex>
#include <map>
#include <set>
#include <iomanip>
#include <math.h>
#include <stdlib.h>
#include <list>
#include <utility>
#include <memory>
#include <cstring>
#include <fstream>
#include <numeric>
#include <assert.h>
#include <bits/stdc++.h>
using namespace std;
#define forn(i,n) for(int i=0;i<(int)n;i++)
#define pb push_back
#define seta(a,b) memset(a,b,sizeof(b))
const int NMAX=1000010;
int n,m,k,used[NMAX],num,cnt[NMAX],may[NMAX];
vector <int> g[NMAX];
void dfs(int v){
	used[v]=1;
	cnt[num]++;
	forn(i,g[v].size())
		if (!used[g[v][i]])
			dfs(g[v][i]);
}
int main(){
	cin>>n>>m>>k;
	forn(i,m){
		int x,y;
		scanf("%d%d",&x,&y);
		x--,y--;
		g[x].pb(y);
		g[y].pb(x);
	}
	seta(used,0);
	num=0;
	seta(cnt,0);
	forn(i,n)
		if (!used[i]){
			dfs(i);
			num++;
		}
	if (k==1){
		cout<<max(0,num-2)<<endl;
		return 0;
	}
	sort (cnt,cnt+num);
	reverse (cnt,cnt+num);
	forn(i,num)
		may[i]=min(k,cnt[i]);
	int now=may[0],ans=0;
	forn(i,num)
		if (i){
			if (now>0)
				now+=may[i]-2;
			else{
				ans++;
				now++;
			}
		}
	cout<<ans<<endl;
}