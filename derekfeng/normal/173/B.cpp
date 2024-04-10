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
char c[1003][1003];
int d[2004];
vector <int> e[2004];
int main() {
	cin>>n>>m;
	for (int i=0; i<n; i++)
		for (int j=0; j<m; j++) {
			cin>>c[i][j];
			if (c[i][j]=='#') {
				e[i].push_back(j+n);
				e[j+n].push_back(i);
			}
		}
	for (int i=0;i<2004;i++)
		d[i]=1e9;
	queue <int> q;
	q.push(0);
	d[0]=0;
	while (!q.empty()) {
		int x=q.front();
		q.pop();
		for(int i=0; i<e[x].size(); i++)
			if(d[e[x][i]]>d[x]+1) {
				d[e[x][i]]=d[x]+1;
				q.push(e[x][i]);
			}
	}
	if (d[n-1]==1e9) cout<<"-1";
	else cout<<d[n-1];
	return 0;
}