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
vector <int> v[5003]; 
int ans[5003];
int main(){
	cin>>n>>m;
	for (int i=1;i<=m;i++){
		int x,y;
		cin>>x>>y;
		v[x].push_back((n+y-x)%n);
	}
	for (int i=1;i<=n;i++){
		sort (v[i].begin(),v[i].end());
		int x=int(v[i].size()),num;
		if (x==0) continue;
		for (int j=1;j<=n;j++){
			if (j<=i) num=(i-j)+(x-1)*n;
			else num=n-(j-i)+(x-1)*n;
			ans[j]=max(ans[j],num+v[i][0]);
		}
	}
	for (int i=1;i<=n;i++) cout<<ans[i]<<" ";
	return 0;
}