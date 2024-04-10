#include <algorithm>
#include <cstdio>
#include <iostream>
#include <cfloat>
#include <climits>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include  <queue>
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
int n,sum;
vector <pii> g[103];
int main(){
	cin>>n;
	for (int i=0;i<n;i++){
		int l,r,pays;
		cin>>l>>r>>pays;
		l--,r--;
		sum+=pays;
		g[l].push_back(pii(r,0));
		g[r].push_back(pii(l,pays));  
	}
	int ans=0,pr=-1,now=0;
	for (int i=0;i<n;i++){
		int cities,cost;
		for (int j=0;j<2;j++){
			cities=g[now][j].first;
			cost=g[now][j].second;
			if (pr!=cities) break;
		}
		ans+=cost;
		pr=now;
		now=cities;
	}
	cout<<min(ans,sum-ans);
	return 0;
}