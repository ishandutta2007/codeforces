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
map <int,bool> mp2;
map <int,vector<int> > mp;
void dfs(int x){
	if (mp2[x]) return;
	mp2[x]=1;
	cout<<x<<" ";
	for (int i=0;i<mp[x].size();i++)
		dfs(mp[x][i]);
}
int main(){
	int n;
	cin>>n;
	for (int i=0;i<n;i++){
		int a,b;
		cin>>a>>b;
		mp[a].push_back(b);
		mp[b].push_back(a);
	}
	vector <int> p;
	for (map <int,vector <int> >::iterator it=mp.begin();it!=mp.end();it++){
		if ((it->second).size()==1){
			p.push_back(it->first);
		}
	}
	dfs(p[0]);
	return 0;
}