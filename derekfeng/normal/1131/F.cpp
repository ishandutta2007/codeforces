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
int n,f[150004];
int find(int x){return f[x]==x?x:f[x]=find(f[x]);}
void unite(int x,int y){x=find(x),y=find(y);f[x]=y;} 
vector <int> v[150004];
void dfs(int x){
	cout<<x<<" ";
	for (int i=0;i<v[x].size();i++)
		dfs(v[x][i]);
}
int main(){
	cin>>n;
	for (int i=1;i<=n;i++) f[i]=i;  
	for (int i=1;i<n;i++){
		int x,y;
		cin>>x>>y;
		x=find(x),y=find(y);
		if (f[x]==f[y]);
		v[y].push_back(x); 
		unite(x,y);
	}
	for (int i=1;i<=n;i++)
		if (f[i]==i)
			dfs(i);
}