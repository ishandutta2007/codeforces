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
#define mp make_pair
typedef pair<int,int> pii;
int n,m;
vector <pii> g[100004];
long long dist[100004];
int from_[100004];
int main(){
	cin>>n>>m;
	for (int i=0;i<m;i++){
		int a,b,l;
		cin>>a>>b>>l;
		a--;
		b--;
		g[a].push_back(mp(b,l));
		g[b].push_back(mp(a,l));
	}
	fill (dist,dist+n,1e18);
	fill (from_,from_+n,-1);
	set <pii> q;
	dist[0]=0;
	q.insert(mp(0,0)); 
	while (!q.empty()){
		int p=q.begin()->second;
		q.erase(q.begin());
		for (int i=0;i<g[p].size();i++){
			int to=g[p][i].first;
			int len=g[p][i].second;
			if (dist[p]+len<dist[to]){
				q.erase(mp(dist[to],to));
				dist[to]=dist[p]+len;
				from_[to]=p;
				q.insert(mp(dist[to],to));
			}
		}
	}
	if (from_[n-1]==-1){
		cout<<"-1";
		return 0;
	}
	vector <int> ans;
	for (int i=n-1;i!=-1;i=i=from_[i])
		ans.push_back(i);
	reverse (ans.begin(),ans.end());
	for (int i=0;i<ans.size();i++)
		cout<<ans[i]+1<<" ";
	return 0;
}