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
typedef pair<int,int> pii;
int n,m;
vector <pii> g[100004]; 
int dist[100004];
map <pii,int> mp;
priority_queue <pii,vector <pii>,greater<pii> > q;
int main(){
	fill (dist,dist+100004,2e9);
	cin>>n>>m;
	for (int i=0;i<m;i++){
		int a,b,c;
		cin>>a>>b>>c;
		g[a].push_back(pii(b,c));
		g[b].push_back(pii(a,c));  
	}
	for (int i=1;i<=n;i++){
		int num,cnt; 
		cin>>num;
		vector <int> v;
		for (int j=0;j<num;j++){
			int pp;
			cin>>pp;
			v.push_back(pp); 
		}
		for (int j=0;j<num;j++){
			if (j==0 || v[j]!=v[j-1]+1) cnt=j;
				if (j==num-1 || v[j]+1!=v[j+1])
					for (int k=cnt;k<=j;k++)
						mp[pii(i,v[k])]=v[j]-v[k]+1;
				
		}
	}
	dist[1]=0;
	q.push(pii(mp[pii(1,0)],1));
	while (!q.empty()){
		int now=q.top().second;
		q.pop();
		if (now==n){
			cout<<dist[n];
			return 0;
		}
		for (int i=0;i<g[now].size();i++){
			int nn=dist[now]+g[now][i].second+mp[pii(now,dist[now])];
			if (nn<dist[g[now][i].first]){
				dist[g[now][i].first]=nn;
				q.push(pii(nn,g[now][i].first));
			}
		}
	}
	cout<<"-1";
	return 0;
}