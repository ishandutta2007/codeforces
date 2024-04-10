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
vector <int> g[2];
int main(){
	int n;
	cin>>n;
	for (int i=1;i<=n;i++){
		int x;
		cin>>x;
		g[x%2].push_back(i); 
	}
	if (g[0].size()==1) cout<<g[0][0];
	else cout<<g[1][0];
	return 0;
}