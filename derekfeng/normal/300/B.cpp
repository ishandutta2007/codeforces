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
vector <int> g[50];
bool vis[50];
vector <vector <int> > o[4]; 
vector <int> dfs(int x){
	vector <int> res;
	if (vis[x]) return res;
	vis[x]=1;
	for (int i=0;i<g[x].size();i++){
		vector <int> mp;
		mp=dfs(g[x][i]);
		for (int i=0;i<mp.size();i++) res.push_back(mp[i]); 
	}
	res.push_back(x);  
	return res;
}
vector <int> ans1,ans2,ans3;
int main(void){
	cin>>n>>m;
	for (int i=0;i<m;i++){
		int x,y;
		cin>>x>>y;
		g[x].push_back(y);
		g[y].push_back(x);  
	}
	for (int i=1;i<=n;i++)
		if (!vis[i]){
			vector <int> ot;
			ot=dfs(i);
			if (int(ot.size()>3)) return puts("-1");
			o[int(ot.size())].push_back(ot);
		}
	for (int i=0;i<o[3].size();i++){
		ans1.push_back(o[3][i][0]);
		ans2.push_back(o[3][i][1]);
		ans3.push_back(o[3][i][2]);   
	}
	if (int(o[2].size())>int(o[1].size())) return puts("-1");
	else{
		for (int i=0;i<o[2].size();i++){
			ans1.push_back(o[2][i][0]);
			ans2.push_back(o[2][i][1]);
			ans3.push_back(o[1][i][0]);    
		}
	}
	if ((int(o[1].size())-int(o[2].size()))%3!=0) return puts("-1");
	else{
		for (int i=int(o[2].size());i<o[1].size();i+=3){
			ans1.push_back(o[1][i][0]);
			ans2.push_back(o[1][i+1][0]);
			ans3.push_back(o[1][i+2][0]);  
		}
	}
	for (int i=0;i<ans1.size();i++)
		cout<<ans1[i]<<" "<<ans2[i]<<" "<<ans3[i]<<"\n";
}