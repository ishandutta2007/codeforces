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
typedef pair<char,char> pcc;
string s[103];
vector <int> g[200];
string ans="";
bool vis[200];
bool dis[200]; 
void dfs(int x){
	if (vis[x]){
		if (dis[x]){
		cout<<"Impossible";
		exit(0);
		}
		return;
	}
	vis[x]=1;
	dis[x]=1;
	for (int i=0;i<g[x].size();i++)
		dfs(g[x][i]);
	dis[x]=0;
	ans+=(char)(x);
}
int main() {
	int n;
	cin>>n;
	for (int i=0; i<n; i++) { 
		cin>>s[i];
		if (i>0) {
			int j=0;
			while (j<s[i].size() && j<s[i-1].size() && s[i][j]==s[i-1][j]) j++;
			if (j==min(s[i].size(),s[i-1].size())) {
				if (s[i].size()<s[i-1].size()) {
					cout<<"Impossible";
					return 0;
				}
			}
			else g[s[i-1][j]].push_back(s[i][j]);
		}
	}
	for (int i='a';i<='z';i++) if (!vis[i]) dfs(i);
	reverse(ans.begin(),ans.end());
	cout<<ans;
	return 0;
}