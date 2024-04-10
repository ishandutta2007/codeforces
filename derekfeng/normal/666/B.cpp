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
int n,m;
int dist[3003][3003];
vector <int> g[3003];
void bfs(int i) {
	memset (dist[i],-1,sizeof(dist[i]));
	queue <int> q;
	q.push(i);
	dist[i][i]=0;
	while (!q.empty()) {
		int k=q.front();
		q.pop();
		for (int j=0; j<g[k].size(); j++) {
			int p=g[k][j];
			if (dist[i][p]>=0) continue;
			dist[i][p]=dist[i][k]+1;
			q.push(p);
		}
	}
}
vector <pair<int,int> > fin[3003],fout[3003];
int main() {
	cin>>n>>m;
	for (int i=0; i<m; i++) {
		int x,y;
		cin>>x>>y;
		x--,y--;
		g[x].push_back(y);
	}
	for (int i=0; i<n; i++) bfs(i);
	for (int i=0; i<n; i++)
		for (int j=0; j<n; j++) {
			if (i!=j && dist[j][i]!=-1)
				fin[i].push_back(make_pair(dist[j][i],j));
			if (fin[i].size()>3) {
				sort (fin[i].begin(),fin[i].end());
				fin[i].erase(fin[i].begin());
			}
		}
	for (int i=0; i<n; i++)
		for (int j=0; j<n; j++) {
			if (i!=j && dist[i][j]!=-1)
				fout[i].push_back(make_pair(dist[i][j],j));
			if (fout[i].size()>3) {
				sort (fout[i].begin(),fout[i].end());
				fout[i].erase(fout[i].begin());
			}
		}
	int ans[4],cnt=0;
	for (int i=0; i<n; i++)
		for (int j=0; j<n; j++) {
			if (i!=j && dist[i][j]!=-1) {
				for (int k=fin[i].size()-1; k>=0; k--)
					for (int q=fout[j].size()-1; q>=0; q--) {
						int num=dist[i][j]+fin[i][k].first+fout[j][q].first;
						if (num>cnt) {
							if (fout[j][q].second!=i && fout[j][q].second!=fin[i][k].second
							        && fin[i][k].second!=j);
							else continue;
							cnt=num;
							ans[0]=fin[i][k].second,ans[1]=i,ans[2]=j,ans[3]=fout[j][q].second;
						}
					}
			}
		}
	for (int i=0; i<4; i++) cout<<++ans[i]<<" ";
	return 0;
}