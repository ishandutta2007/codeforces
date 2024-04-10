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
char c[1003][1003];
bool p[1003][1003];
int dir[4][2]= {{0,1},{1,0},{-1,0},{0,-1}};
vector <pair<int,int> > ve[1000004];
int xp[1003][1003];
int cnt,n,m;
void dfs(int i,int j,int l) {
	if (p[i][j] || c[i][j]=='*') return;
	p[i][j]=1;
	ve[l].push_back(make_pair(i,j));
	for (int k=0; k<4; k++) {
		int u=i+dir[k][0],v=j+dir[k][1];
		if (u<0 || v<0 || u>=n || v>=m) continue;
		dfs(u,v,l);
	}
	xp[i][j]=l;
}
int main() {
	memset (p,0,sizeof(p));
	cin>>n>>m;
	for (int i=0; i<n; i++)
		for (int j=0; j<m; j++)
			cin>>c[i][j];
	for (int i=0; i<n; i++)
		for (int j=0; j<m; j++)
			if (c[i][j]=='.' && (!p[i][j]))
				dfs(i,j,cnt++);
	for (int i=0; i<n; i++) {
		for (int j=0; j<m; j++) {
			if (c[i][j]=='*') {
				int num=0;
				vector <int> hu,nah;
				for (int k=0; k<4; k++) {
					int u=i+dir[k][0],v=dir[k][1]+j;
					if (u<0 || v<0 || u>=n || v>=m || c[u][v]=='*') continue;
					hu.push_back(xp[u][v]);
				}
				if (hu.size()==0) {
					cout<<"1";
					continue;
				}
				sort (hu.begin(),hu.end());
				num+=ve[hu[0]].size();
				for (int k=1; k<hu.size(); k++)
					if (hu[k]!=hu[k-1])
						num+=ve[hu[k]].size();
				cout<<(num+1)%10;
			} else cout<<".";
		}
		cout<<endl;
	}
	return 0;
}