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
string s;
int ans=1e9;
vector <int> g[200];
int main(){
	cin>>s;
	int n=s.size();
	for (int i='a';i<='z';i++) g[i].push_back(-1);
	for (int i=0;i<n;i++) g[s[i]].push_back(i);
	for (int i='a';i<='z';i++) g[i].push_back(n);
	for (char c='a';c<='z';c++)
		if (g[c].size()>2){
			int res=0;
			for (int i=1;i<g[c].size();i++)
				res=max(res,g[c][i]-g[c][i-1]);
			ans=min(ans,res);
		}
	cout<<ans;
	return 0;
}