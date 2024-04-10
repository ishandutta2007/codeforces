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
#include <bitset>
#include <ios> 
#include <bits/stdc++.h>
using namespace std;
int n,x,ans=2e9+1;
int l[200004],r[200004],c[200004];
vector <pair<int,int> > costs;
vector <int> nd[200004],co[200004];
int main(){
	cin>>n>>x;
	for (int i=0;i<n;i++){
		cin>>l[i]>>r[i]>>c[i];
		costs.push_back(make_pair(l[i],i)); 
	}
	sort (costs.begin(),costs.end());
	for (int i=n-1;i>=0;i--){
		nd[r[costs[i].second]-l[costs[i].second]+1].push_back(l[costs[i].second]);
		if (co[r[costs[i].second]-l[costs[i].second]+1].size()>0 && co[r[costs[i].second]-l[costs[i].second]+1][co[r[costs[i].second]-l[costs[i].second]+1].size()-1]<c[costs[i].second])
			 co[r[costs[i].second]-l[costs[i].second]+1].push_back(co[r[costs[i].second]-l[costs[i].second]+1][co[r[costs[i].second]-l[costs[i].second]+1].size()-1]);
		else co[r[costs[i].second]-l[costs[i].second]+1].push_back(c[costs[i].second]);
	}
	for (int i=0;i<200004;i++){
		reverse (nd[i].begin(),nd[i].end());
		reverse (co[i].begin(),co[i].end());
	}
	for (int i=0;i<n;i++){
		int xx=r[i]-l[i]+1;
		if (xx>=x) continue;
		int p=upper_bound(nd[x-xx].begin(),nd[x-xx].end(),r[i])-nd[x-xx].begin();
		if (p!=nd[x-xx].size()) ans=min(ans,c[i]+co[x-xx][p]);
	}
	if (ans==2e9+1) cout<<-1;
	else cout<<ans;
}